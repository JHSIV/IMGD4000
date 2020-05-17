// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "InfoWidget.generated.h"

/**
 * A widget used to display text to the user
 */
UCLASS()
class BOIDS_API UInfoWidget : public UUserWidget
{
	GENERATED_BODY()
	
	public:
		UInfoWidget(const FObjectInitializer& ObjectInitializer);
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* InfoText;

		void UpdateText(FText NewText);

		virtual void NativeConstruct() override;
};
