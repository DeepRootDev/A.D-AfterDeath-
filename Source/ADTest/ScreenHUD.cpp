// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenHUD.h"

AScreenHUD::AScreenHUD()
{

}

void AScreenHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AScreenHUD::BeginPlay()
{
	Super::BeginPlay();

	if (WidgetClass)
	{
		ScreenHUDWidget = CreateWidget<UScreenHUDWidget>(GetWorld(), WidgetClass);
		if (ScreenHUDWidget)
		{
			ScreenHUDWidget->AddToViewport();

		}
	}

}

void AScreenHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AScreenHUD::UpdateForm(int value)
{
	if (ScreenHUDWidget)
	{
		ScreenHUDWidget->UpdateForm(value);
	}
}
