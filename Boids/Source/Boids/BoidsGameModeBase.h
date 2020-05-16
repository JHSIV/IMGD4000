// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FlockingManager.h"
#include "GameFramework/GameModeBase.h"
#include "BoidsGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API ABoidsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	ABoidsGameModeBase();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* AgentMesh;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AFlockingManager> ManagerClass;
	UPROPERTY(EditAnywhere)
	AFlockingManager* Manager;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
