// Fill out your copyright notice in the Description page of Project Settings.


#include "InfoWidget.h"

UInfoWidget::UInfoWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

void UInfoWidget::NativeConstruct() 
{
    Super::NativeConstruct();
}

/*
 * Update the text displayed
 */
void UInfoWidget::UpdateText(FText NewText)
{
    InfoText->SetText(NewText);
}