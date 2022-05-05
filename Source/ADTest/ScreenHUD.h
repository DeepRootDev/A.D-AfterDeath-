// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ScreenHUDWidget.h"
#include "Components/WidgetComponent.h"
#include "ScreenHUD.generated.h"

/**
 * 
 */
UCLASS()
class ADTEST_API AScreenHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AScreenHUD();

	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;


	void UpdateForm(int value);

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere, Category = "Player")
		TSubclassOf<class AMyCharacter> BPPlayer;
private:

	UScreenHUDWidget* ScreenHUDWidget;
};
