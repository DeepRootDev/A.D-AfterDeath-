// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include <Components/ProgressBar.h>
#include "ScreenHUDWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ADTEST_API UScreenHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UScreenHUDWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void UpdateForm(int value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextForm;
};
