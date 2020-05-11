// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Agent.h"
#include "FlockingManager.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API UFlockingManager : public UObject
{
	public:
		GENERATED_BODY()

		void SetupPlayerInputComponent(class UInputComponent* InputComponent);
		void Init(UWorld *world, UStaticMeshComponent *mesh);
		void CleanUp();
		void Flock();
		void Steer(float axisValue);
			
	private:
		UWorld *World;
		float Direction;
		FVector SteeringSpeed;
		bool Initialized;
		TArray<class AAgent*> Agents;
};
