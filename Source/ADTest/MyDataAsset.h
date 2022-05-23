// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ADTEST_API UMyDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	bool isCard = true;
};
