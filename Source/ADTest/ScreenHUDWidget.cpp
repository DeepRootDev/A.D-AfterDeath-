// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenHUDWidget.h"

UScreenHUDWidget::UScreenHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}
void UScreenHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UScreenHUDWidget::UpdateForm(int value)
{
	if (TextForm)
	{
		switch (value)
		{
		case 0:
			TextForm->SetText(FText::FromString("Attack Form"));
			break;
		case 1:
			TextForm->SetText(FText::FromString("Defense Form"));
			break;
		case 2:
			TextForm->SetText(FText::FromString("Flight Form"));
			break;
		case 3:
			TextForm->SetText(FText::FromString("Counter Form"));
			break;
		case 4:
			TextForm->SetText(FText::FromString("Evasive Form"));
			break;
		}
	}
	
}
