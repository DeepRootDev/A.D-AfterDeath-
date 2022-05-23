// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCardActor.h"

// Sets default values
AMyCardActor::AMyCardActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool AMyCardActor::getQuad1Spawn()
{
	return quad1Spawn;
}

// Called when the game starts or when spawned
void AMyCardActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCardActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

