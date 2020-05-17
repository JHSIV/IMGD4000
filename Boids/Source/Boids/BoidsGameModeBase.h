// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FlockingManager.h"
#include "GameFramework/GameModeBase.h"
#include "BoidsGameModeBase.generated.h"

/**
 * Sets up and manages the game
 */
UCLASS()
class BOIDS_API ABoidsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	ABoidsGameModeBase();

	public:
		UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* AgentMesh;
		UPROPERTY(EditAnywhere)
		TSubclassOf<AFlockingManager> ManagerClass;
		UPROPERTY(EditAnywhere)
		AFlockingManager* Manager;
		//UPROPERTY(EditAnywhere)
		//UInfoWidget* InfoWidget;

		void StartGame();

	private:
		float TickTime = 0.f;
		float ElapsedTime = 0.f;
		int ElapsedSeconds = 0;
		bool GameStart = false;
		bool GameEnd = false;

		void EndGame();

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
};
