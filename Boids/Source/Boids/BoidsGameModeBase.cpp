// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Kismet/GameplayStatics.h"
#include "BoidsGameModeBase.h"
#include "FlockingManager.h"

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
    Manager = world->SpawnActor<AFlockingManager>(ManagerClass, FVector(0.f,0.f,0.f), FRotator());
    AController* controller = UGameplayStatics::GetPlayerController(world, 0);
    controller->Possess(Manager);
    controller->SetControlRotation(FRotator(-45.f, 0.f, 0.f));
    Manager->Init(GetWorld(), AgentMesh);
}

void ABoidsGameModeBase::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    Manager->CleanUp();
    Manager->Flock();
}