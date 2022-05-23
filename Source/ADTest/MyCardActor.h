// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCardActor.generated.h"

UCLASS()
class ADTEST_API AMyCardActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCardActor();

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
	
	bool getQuad1Spawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
