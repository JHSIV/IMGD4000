// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "BoidsGameModeBase.h"
#include "FlockingManager.h"

ABoidsGameModeBase::ABoidsGameModeBase() {
    AgentMesh = CreateDefaultSubobject<UStaticMeshComponent>("AgentMesh");
    PrimaryActorTick.bCanEverTick = true;
} 

void ABoidsGameModeBase::BeginPlay() {
    Super::BeginPlay();
    Manager = NewObject<UFlockingManager>();
    Manager->Init(GetWorld(), AgentMesh);
}

void ABoidsGameModeBase::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    Manager->CleanUp();
    Manager->Flock();
};