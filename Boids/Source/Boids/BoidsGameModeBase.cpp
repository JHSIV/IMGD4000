// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BoidsGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "FlockingManager.h"

#define TICK_TIME 0.016

ABoidsGameModeBase::ABoidsGameModeBase() {
    // load FlockingManager blueprint
    static ConstructorHelpers::FClassFinder<AFlockingManager> ManagerBPClass(TEXT("/Game/Blueprints/BP_FlockingManager"));
	if (ManagerBPClass.Class != NULL) {
		ManagerClass = ManagerBPClass.Class;
	}
    
    // set Boid agent mesh
    AgentMesh = CreateDefaultSubobject<UStaticMeshComponent>("AgentMesh");
    
    PrimaryActorTick.bCanEverTick = true;
} 

void ABoidsGameModeBase::BeginPlay() {
    Super::BeginPlay();
    UWorld* world = GetWorld();
    Manager = world->SpawnActor<AFlockingManager>(ManagerClass, FVector(0.f), FRotator(0.f));
    AController* controller = UGameplayStatics::GetPlayerController(world, 0);
    controller->Possess(Manager);
    controller->SetControlRotation(FRotator(-45.f, 0.f, 0.f));
    Manager->Init(GetWorld(), AgentMesh);
}

void ABoidsGameModeBase::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    Manager->CleanUp();

    // Update Timer
    if (GameStart && !GameEnd)
    {
       ElapsedTime += DeltaTime;
       while (ElapsedTime > 1.f)
       {
           ElapsedSeconds += 1;
           ElapsedTime -= 1;
       }

       // End Game
       if (false) // All Boids Free
       {
           EndGame();
       } 
    }

    // Update Boids
    TickTime += DeltaTime;
    while (TickTime > TICK_TIME)
    {
        Manager->Flock();
        TickTime -= TICK_TIME;
    }
}

/*
 * Start the game on command
 */
void ABoidsGameModeBase::StartGame() {
    if (!GameEnd)
    {
        GameStart = true;
        //TODO set InfoWidget to show timer
    }
}

/*
 * End game 
 */
void ABoidsGameModeBase::EndGame()
{
    GameEnd = true;
    //TODO set InfoWidget to show result  
}