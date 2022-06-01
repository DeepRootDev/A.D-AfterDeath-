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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 1", meta = (AllowPrivateAccess = "true"))
		bool input1L = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 1", meta = (AllowPrivateAccess = "true"))
		bool input1R = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 2", meta = (AllowPrivateAccess = "true"))
		bool input2L = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 2", meta = (AllowPrivateAccess = "true"))
		bool input2R = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 3", meta = (AllowPrivateAccess = "true"))
		bool input3L = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 3", meta = (AllowPrivateAccess = "true"))
		bool input3R = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 4", meta = (AllowPrivateAccess = "true"))
		bool input4L = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 4", meta = (AllowPrivateAccess = "true"))
		bool input4R = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 5", meta = (AllowPrivateAccess = "true"))
		bool input5L = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Input 5", meta = (AllowPrivateAccess = "true"))
		bool input5R = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input Number", meta = (AllowPrivateAccess = "true"))
		int inputNum = 0;

	//int comboInputs[10] = {input1L, input1R, input2L, input2R, input3L, input3R, input4L, input4R, input5L, input5R};
};
