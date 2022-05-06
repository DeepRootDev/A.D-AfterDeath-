// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "MyProjectile.h"
#include "ScreenHUD.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMyCharacter::AMyCharacter()
	: BaseTurnRate(45.f)
	, BaseLookUpRate(45.f)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	HitDetect = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hit Detect"));
	HitDetect->SetupAttachment(RootComponent);

	Quad1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 1"));
	Quad2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 2"));
	Quad3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 3"));
	Quad4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 4"));

	Quad1->SetupAttachment(RootComponent);
	Quad2->SetupAttachment(RootComponent);
	Quad3->SetupAttachment(RootComponent);
	Quad4->SetupAttachment(RootComponent);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

void AMyCharacter::lift()
{
}

void AMyCharacter::Shoot()
{
	if (spawnedProjectile)
	{
		//spawnedProjectile->setSpeed(5000.f);
		//SetActorRotation({ 0.0, FollowCamera->GetComponentRotation().Yaw, 0.0 });
		GetWorld()->SpawnActor<AMyProjectile>(actualProjectile, HitDetect->GetComponentLocation(), { 0.0, FollowCamera->GetComponentRotation().Yaw, 0.0 });
		spawnedProjectile->Destroy();
	}
	
}
void AMyCharacter::attackForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(0);
	}
}
void AMyCharacter::defenseForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(1);
	}
}
void AMyCharacter::flightForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(2);
	}
}
void AMyCharacter::counterForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(3);
	}
}
void AMyCharacter::Block()
{
}
void AMyCharacter::updateRockState()
{

	switch (rockState)
	{
	case 0:
		spawnedProjectile = GetWorld()->SpawnActor<AMyProjectile>(throwableProjectile, HitDetect->GetComponentLocation(), FollowCamera->GetComponentRotation());
		//spawnedProjectile->setSpeed(0.f);
		rockState = 1;
		break;
	case 1:
		Shoot();
		rockState = 0;
		break;
	}
}

void AMyCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMyCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	Quad1->SetRelativeLocation(FVector(0.f, quad1Dist, 0.f));
	screenHUD = Cast<AScreenHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

	if (screenHUD)
	{
		screenHUD->UpdateForm(0);
	}
}

void AMyCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AMyProjectile* spawnedProj = Cast<AMyProjectile>(throwableProjectile);

	switch (rockState)
	{
	case 0:
		
		
		break;
	case 1:
		if (spawnedProjectile)
		{
			spawnedProjectile->SetActorLocation(HitDetect->GetComponentLocation());
		}
		
		break;
	}

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Rock", IE_Pressed, this, &AMyCharacter::updateRockState);

	PlayerInputComponent->BindAction("Attack Form", IE_Pressed, this, &AMyCharacter::attackForm);
	PlayerInputComponent->BindAction("Defense Form", IE_Pressed, this, &AMyCharacter::defenseForm);
	PlayerInputComponent->BindAction("Flight Form", IE_Pressed, this, &AMyCharacter::flightForm);
	PlayerInputComponent->BindAction("Counter Form", IE_Pressed, this, &AMyCharacter::counterForm);
	PlayerInputComponent->BindAction("Block", IE_Pressed, this, &AMyCharacter::Block);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMyCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacter::LookUpAtRate);
}

