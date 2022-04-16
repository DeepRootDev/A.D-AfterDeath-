// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestInteract.generated.h"

UCLASS()
class ADTEST_API ATestInteract : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestInteract();

	void takeHit(FVector direction);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = BoxMesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* BoxMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
