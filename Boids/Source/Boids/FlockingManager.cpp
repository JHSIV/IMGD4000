// Fill out your copyright notice in the Description page of Project Settings.

#include "FlockingManager.h"
#include "Math/Vector.h"


#define AGENT_COUNT 10
#define RULE1_WEIGHT 0.01
#define RULE2_THRESHOLD 200
#define RULE2_WEIGHT 1
#define RULE3_WEIGHT 0.125
#define STEERING_SPEED 0
#define DISTANCE_CONSTRAINT 2000
#define SPEED_CONSTRAINT 60

AFlockingManager::AFlockingManager() {
    // set up the camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// set up the camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

void AFlockingManager::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Steering", this, &AFlockingManager::Steer);
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

    // initialize camera
    //TODO

    // initialize steering
    Direction = 90.f;
    SteeringSpeed = FVector(STEERING_SPEED, 0, 0);

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
            velocityChange -= (originDistance-DISTANCE_CONSTRAINT)*currentPos/originDistance;
        }

        // Apply results
        FVector newVelocity = currentVel + velocityChange + FRotator(0,0,Direction).RotateVector(SteeringSpeed);
        float newVelMag = newVelocity.Size();
        if (newVelMag > SPEED_CONSTRAINT)
        {
            newVelocity *= SPEED_CONSTRAINT / newVelMag;
        }
        currentAgent->Advance(newVelocity);
    }
    // Keep the camera centered on the flock
    float flockMinX = 100000.f;
    float flockAveY = 0.f;
    float flockMaxZ = -100000.f;
    for (int i = 0; i < boidCount; i++) {
        FVector boidPos = Agents[i]->GetActorLocation();
        if (boidPos.X < flockMinX)
        {
            flockMinX = boidPos.X;
        }
        flockAveY += boidPos.Y;
        if (boidPos.Z > flockMaxZ)
        {
            flockMaxZ = boidPos.Z;
        }
    }
    FVector thisPos = GetActorLocation();
    FVector nextPos = FVector(flockMinX-400.f, flockAveY/boidCount, flockMaxZ+400.f);
    SetActorLocation(thisPos + (nextPos-thisPos)/2);
}

/*
 * Steer the flock
 */
void AFlockingManager::Steer(float axisValue) {
    Direction = fmod(Direction + axisValue, 360.f);
}

/*
 * Only here for compatability with superclass
 */
void AFlockingManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}