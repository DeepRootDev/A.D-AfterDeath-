// Fill out your copyright notice in the Description page of Project Settings.


#include "TestInteract.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATestInteract::ATestInteract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	BoxMesh->SetupAttachment(RootComponent);
}

void ATestInteract::takeHit(FVector direction)
{


}

// Called when the game starts or when spawned
void ATestInteract::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestInteract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

