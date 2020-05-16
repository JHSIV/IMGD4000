// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Agent.generated.h"

UCLASS()
class BOIDS_API AAgent : public AActor
{
	GENERATED_BODY()
	
	public:	
		AAgent();
		void Init( UStaticMeshComponent *mesh, int id );
		UStaticMeshComponent * Mesh;
		FVector Velocity;
		bool ToDelete = false;

		void Advance(FVector velocityChange);

		// Called every frame
		virtual void Tick(float DeltaTime) override;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
};
