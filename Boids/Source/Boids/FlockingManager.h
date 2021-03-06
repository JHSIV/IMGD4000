// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Agent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "FlockingManager.generated.h"

/**
 * Controls and monitors the Boid agent flock
 */
UCLASS()
class BOIDS_API AFlockingManager : public APawn
{
	GENERATED_BODY()

	public:
		AFlockingManager();

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

		void Init(UWorld *world, UStaticMeshComponent *mesh);
		void CleanUp();
		void Flock();
		void Steer(float AxisValue);

		virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
		virtual void Tick(float DeltaTime) override;
			
	private:
		UWorld* World;
		float Direction = 90.f;
		FVector SteeringSpeed = FVector(0.f);
		bool Initialized = false;
		TArray<class AAgent*> Agents;

		void StartGame();
		int Sign(float Number);
};
