// Fill out your copyright notice in the Description page of Project Settings.

#include "FlockingManager.h"
#include "BoidsGameModeBase.h"
#include "Engine/EngineTypes.h"
#include "Math/Vector.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

#define AGENT_COUNT 20
#define RULE1_WEIGHT 0.01
#define RULE2_THRESHOLD 200
#define RULE2_WEIGHT 0.5
#define RULE3_WEIGHT 0.125
#define ROTATION_SPEED 4
#define STEERING_SPEED 4
#define DISTANCE_CONSTRAINT 15000
#define DISTANCE_CONSTRAINT_WEIGHT 0.4
#define HEIGHT_CONSTRAINT 800
#define HEIGHT_CONSTRAINT_WEIGHT 0.2
#define SPEED_CONSTRAINT 60

AFlockingManager::AFlockingManager() {
    // set up the camera boom
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 1000.f;
	CameraBoom->bUsePawnControlRotation = true;

    // set up the camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void AFlockingManager::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Steering", this, &AFlockingManager::Steer);
    PlayerInputComponent->BindAction("Start", IE_Pressed, this, &AFlockingManager::StartGame);
}

void AFlockingManager::Init(UWorld *world, UStaticMeshComponent *mesh) {
    World = world;
    // setup boids agents
    float incr = (PI * 2.f) / AGENT_COUNT;
    for( int i = 0; i < AGENT_COUNT; i++ ) {
        if( World != nullptr ) {
            FRotator rotation = FRotator();

            FVector location = FVector();
            location.X = FMath::Sin(incr * i) * 150.f;
            location.Y = FMath::Cos(incr * i) * 150.f;

            AAgent* agent = World->SpawnActor<AAgent>(location, rotation);
            agent->Init(mesh, i);
            Agents.Add(agent);
        }
    }

    // initialize steering
    Direction = 90.f;
    SteeringSpeed = FVector(STEERING_SPEED, 0.f, 0.f);

    Initialized = true;
}

/*
 * Safely deletes all boids agents marked for removal before updating positions
 */
void AFlockingManager::CleanUp() {
    int i = Agents.Num()-1;
    while (i >= 0)
    {
        if (Agents[i]->ToDelete)
        {
            Agents.RemoveAt(i);
        }
        i -= 1;
    }
}

/*
 * Update the positions and trajectories of the boids agents
 */
void AFlockingManager::Flock() {
    int boidCount = Agents.Num();
    float flockMinX = 100000.f;
    float flockAveY = 0.f;
    FVector flockCenter = FVector(0.f);
    FVector steeringVel = SteeringSpeed.RotateAngleAxis(Direction, FVector(0.f,0.f,1.f));

    // Get world obstacles
    TArray<AActor*> obstacles;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Wall"), obstacles);
    int obstacleCount = obstacles.Num();

    for (int i = 0; i < boidCount; i++)
    {
        // Get Agent
        AAgent* currentAgent = Agents[i];
        FVector currentPos = currentAgent->GetActorLocation();
        FVector currentVel = currentAgent->Velocity;
        FVector centerPos = FVector(0.f);
        FVector averageVel = FVector(0.f);
        FVector avoidanceOffset = FVector(0.f);
        FVector velocityChange = FVector(0.f);

        // Get neighbor information
        for (int j = 0; j < boidCount; j++)
        {
            // skip current boid agent
            if (i != j)
            {
                AAgent* neighborAgent = Agents[j];
                FVector neighborPos = neighborAgent->GetActorLocation();
                // contribute to flock center calculation
                centerPos += neighborPos;
                // contribute to flock velocity calculation
                averageVel += neighborAgent->Velocity;
                // if close enough, contribute to avoidance calculation
                if (FVector::Dist(neighborPos, currentPos) < RULE2_THRESHOLD)
                {
                    avoidanceOffset -= neighborPos - currentPos;
                }
            }
        }

        // Interact with world obstacles
        for (int j = 0; j < obstacleCount; j++)
        {
            AActor* obstacle = obstacles[j];
            FHitResult hit;
            FCollisionQueryParams TraceParams;
            if (obstacle->ActorLineTraceSingle(hit, currentPos, obstacle->GetActorLocation(), ECC_Visibility, TraceParams))
            {
                if (hit.Distance < RULE2_THRESHOLD)
                {
                    avoidanceOffset -= hit.ImpactPoint - currentPos;
                }
            }
        }
        
        // Evaluate rules
        // - Rule 1: Fly towards center
        velocityChange += (centerPos/(boidCount-1) - currentPos) * RULE1_WEIGHT;

        // - Rule 2: Avoid other boids/objects
        velocityChange += avoidanceOffset * RULE2_WEIGHT;

        // - Rule 3: Match other boids' velocity
        averageVel /= boidCount - 1;
        velocityChange += (averageVel - currentVel) * RULE3_WEIGHT;

        // - Constraint: stay within bounds
        float originDistance = currentPos.Size();
        if (originDistance > DISTANCE_CONSTRAINT)
        {
            velocityChange -= ((originDistance-DISTANCE_CONSTRAINT)*currentPos/originDistance) * DISTANCE_CONSTRAINT_WEIGHT;
        }
        float zPos = currentPos.Z;
        if (abs(zPos) > HEIGHT_CONSTRAINT)
        {
            velocityChange -= FVector(0.f, 0.f, (zPos-HEIGHT_CONSTRAINT*Sign(zPos)) * HEIGHT_CONSTRAINT_WEIGHT);
        }

        // Update camera position
        if (currentPos.X < flockMinX)
        {
            flockMinX = currentPos.X;
        }
        flockAveY += currentPos.Y;
        flockCenter += currentPos;

        // Apply results
        FVector newVelocity = currentVel + velocityChange + steeringVel;
        float newVelMag = newVelocity.Size();
        if (newVelMag > SPEED_CONSTRAINT)
        {
            newVelocity *= SPEED_CONSTRAINT / newVelMag;
        }
        currentAgent->Advance(newVelocity);
    }

    // Keep the camera centered on the flock
    FVector thisPos = GetActorLocation();
    FVector nextPos = FVector(flockMinX-600.f, flockAveY/boidCount, HEIGHT_CONSTRAINT+600.f);
    SetActorLocation(thisPos + (nextPos-thisPos)/2);
    //UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f"), thisPos.X, thisPos.Y, thisPos.Z);

    // DEBUG: Draw flock trajectory
    flockCenter /= boidCount;
    FVector flockProjection = flockCenter + 50*steeringVel;
    //DrawDebugLine(GetWorld(), flockCenter, flockProjection, FColor(255,0,0,255), false, 0.1f, 1, 10.f);
    //UE_LOG(LogTemp, Warning, TEXT("( %f, %f, %f ) -> ( %f, %f, %f )"), flockCenter.X, flockCenter.Y, flockCenter.Z, flockProjection.X, flockProjection.Y, flockProjection.Z);
    //UE_LOG(LogTemp, Warning, TEXT(" \nSPD: (%f, %f, %f)\nDIR: %f\nVEL: (%f, %f, %f)"), SteeringSpeed.X, SteeringSpeed.Y, SteeringSpeed.Z, Direction, steeringVel.X, steeringVel.Y, steeringVel.Z);
}

/*
 * Start the game
 */
void AFlockingManager::StartGame() {
    ABoidsGameModeBase* gm = (ABoidsGameModeBase*) GetWorld()->GetAuthGameMode();
    gm->StartGame();
}

/*
 * Steer the flock
 */
void AFlockingManager::Steer(float AxisValue) {
    Direction = fmod(Direction + ROTATION_SPEED*FMath::Clamp(AxisValue, -1.f, 1.f), 360.f);
}

/*
 * Only here for compatability with superclass
 */
void AFlockingManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

/*
 * Helper Function: Return a float's sign 
 * (I bafflingly cannot find an equivalent method in the documentation)
 */
int AFlockingManager::Sign(float Number) {
    if (Number < 0)
    {
        return -1;
    }
    else if (Number > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}