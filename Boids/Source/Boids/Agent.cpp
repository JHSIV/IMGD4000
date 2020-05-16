// Fill out your copyright notice in the Description page of Project Settings.


#include "Agent.h"

AAgent::AAgent() {
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AgentMesh"));	
	RootComponent = Mesh;
	Velocity = FVector(0.f);
}

void AAgent::BeginPlay() {
	Super::BeginPlay();
}

void AAgent::Init(UStaticMeshComponent *mesh, int id) {
	Mesh->SetStaticMesh(mesh->GetStaticMesh());
}

/*
 * Update this boid agent
 */
void AAgent::Advance(FVector newVelocity) {
	FVector loc = GetActorLocation();
	Velocity = newVelocity;
	SetActorLocation(loc + Velocity);
	SetActorRotation(Velocity.ToOrientationRotator());
}

/*
 * Only here for compatability with superclass
 */
void AAgent::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}