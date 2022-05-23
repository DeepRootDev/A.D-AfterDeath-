// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Card.generated.h"

/**
 * 
 */
UCLASS()
class ADTEST_API UCard : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quadrants", meta = (AllowPrivateAccess = "true"))
		bool quad1Spawn = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quadrants", meta = (AllowPrivateAccess = "true"))
		bool quad2Spawn = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quadrants", meta = (AllowPrivateAccess = "true"))
		bool quad3Spawn = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quadrants", meta = (AllowPrivateAccess = "true"))
		bool quad4Spawn = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimTiming", meta = (AllowPrivateAccess = "true"))
		float symbolTime = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimTiming", meta = (AllowPrivateAccess = "true"))
		float riseTime = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimTiming", meta = (AllowPrivateAccess = "true"))
		float hoverTime = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ProjectileProperties", meta = (AllowPrivateAccess = "true"))
		float initialSpeed = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ProjectileProperties", meta = (AllowPrivateAccess = "true"))
		float maxSpeed = 0.f;

	
};
