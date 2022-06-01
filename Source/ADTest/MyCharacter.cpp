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
#include "Engine/DataAsset.h"
#include "MyCardActor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"




// Sets default values
AMyCharacter::AMyCharacter()
	: BaseTurnRate(45.f)
	, BaseLookUpRate(45.f)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	for (int i = 0; i < 5; i++)
	{
		inputList[i] = '\0';
	}

	HitDetect = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hit Detect"));
	HitDetect->SetupAttachment(RootComponent);

	Quad1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 1"));
	Quad2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 2"));
	Quad3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 3"));
	Quad4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 4"));

	Quad1AnimPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 1 Anim Point"));
	Quad2AnimPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 2 Anim Point"));
	Quad3AnimPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 3 Anim Point"));
	Quad4AnimPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 4 Anim Point"));

	Quad1Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 1 Plane"));
	Quad2Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 2 Plane"));
	Quad3Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 3 Plane"));
	Quad4Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Quad 4 Plane"));

	Quad1->SetupAttachment(RootComponent);
	Quad2->SetupAttachment(RootComponent);
	Quad3->SetupAttachment(RootComponent);
	Quad4->SetupAttachment(RootComponent);

	Quad1AnimPoint->SetupAttachment(RootComponent);
	Quad2AnimPoint->SetupAttachment(RootComponent);
	Quad3AnimPoint->SetupAttachment(RootComponent);
	Quad4AnimPoint->SetupAttachment(RootComponent);

	Quad1Plane->SetupAttachment(RootComponent);
	Quad2Plane->SetupAttachment(RootComponent);
	Quad3Plane->SetupAttachment(RootComponent);
	Quad4Plane->SetupAttachment(RootComponent);

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
void AMyCharacter::updateShooting()
{
	
	isShooting = true;
	
}
void AMyCharacter::lift()
{
}

void AMyCharacter::Shoot()
{
	
		//spawnedProjectile->setSpeed(5000.f);
		//SetActorRotation({ 0.0, FollowCamera->GetComponentRotation().Yaw, 0.0 });


	
		UE_LOG(LogTemp, Warning, TEXT("Cast is successful??"));
		if (currentOffenseCard->quad1Spawn == true)
		{
			GetWorld()->SpawnActor<AMyProjectile>(actualProjectile, Quad1->GetComponentLocation(), { 20.0, FollowCamera->GetComponentRotation().Yaw, 0.0 })->setSpeed(currentOffenseCard->initialSpeed, currentOffenseCard->maxSpeed);
		}
		
		if (currentOffenseCard->quad2Spawn == true)
		{
			GetWorld()->SpawnActor<AMyProjectile>(actualProjectile, Quad2->GetComponentLocation(), { 20.0, FollowCamera->GetComponentRotation().Yaw, 0.0 })->setSpeed(currentOffenseCard->initialSpeed, currentOffenseCard->maxSpeed);
		}
		if (currentOffenseCard->quad3Spawn == true)
		{
			GetWorld()->SpawnActor<AMyProjectile>(actualProjectile, Quad3->GetComponentLocation(), { 20.0, FollowCamera->GetComponentRotation().Yaw, 0.0 })->setSpeed(currentOffenseCard->initialSpeed, currentOffenseCard->maxSpeed);
		}
		if (currentOffenseCard->quad4Spawn == true)
		{
			GetWorld()->SpawnActor<AMyProjectile>(actualProjectile, Quad4->GetComponentLocation(), { 20.0, FollowCamera->GetComponentRotation().Yaw, 0.0 })->setSpeed(currentOffenseCard->initialSpeed, currentOffenseCard->maxSpeed);
		}
	
		
		
		//spawnedProjectile->Destroy();
	
	

}
void AMyCharacter::addLeftInput()
{
	int count = 0;

	while (count < 5)
	{
		if (inputList[count] == '\0')
		{
			inputList[count] = 'L';
			UE_LOG(LogTemp, Warning, TEXT("Added Left Input"));
			UE_LOG(LogTemp, Warning, TEXT("Input list currently %c %c %c %c %c"), inputList[0], inputList[1], inputList[2], inputList[3], inputList[4]);
			count = 5;
		}
		else
		{
			count += 1;
		}
	}
}
void AMyCharacter::addRightInput()
{
	int count = 0;

	while (count < 5)
	{
		if (inputList[count] == '\0')
		{
			inputList[count] = 'R';
			UE_LOG(LogTemp, Warning, TEXT("Added Right Input"));
			UE_LOG(LogTemp, Warning, TEXT("Input list currently %c %c %c %c %c"), inputList[0], inputList[1], inputList[2], inputList[3], inputList[4]);
			count = 5;
		}
		else
		{
			count += 1;
		}
	}
}
void AMyCharacter::checkCombo()
{
	
	int comboMatch[5] = { 0, 0, 0, 0, 0 };
	bool combo1Match = false;
	bool combo2Match = false;
	bool combo3Match = false;
	bool combo4Match = false;
	bool combo5Match = false;
	int executeCombo = 1;
	int maxComboInputs = 0;

	if (currentOffenseCard->input1L == true)
	{
		if (inputList[0] == 'L')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo1Match = true;
		}
		
	}
	

	if (currentOffenseCard->input1R == true)
	{
		if (inputList[0] == 'R')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo1Match = true;
		}
		
	}
	
	if (currentOffenseCard->input2L == true)
	{
		if (inputList[1] == 'L')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo2Match = true;
		}
		
	}
	
	if (currentOffenseCard->input2R == true)
	{
		if (inputList[1] == 'R')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo2Match = true;
		}
		
	}
	
	if (currentOffenseCard->input3L == true)
	{
		if (inputList[2] == 'L')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo3Match = true;
		}
		
	}
	
	if (currentOffenseCard->input3R == true)
	{
		if (inputList[2] == 'R')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo3Match = true;
		}
		
	}
	
	if (currentOffenseCard->input4L == true)
	{
		if (inputList[3] == 'L')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo4Match = true;
		}
		
	}
	
	if (currentOffenseCard->input4R == true)
	{
		if (inputList[3] == 'R')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo4Match = true;
		}
		
	}
	
	if (currentOffenseCard->input5L == true)
	{
		if (inputList[4] == 'L')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo5Match = true;
		}
	
	}

	if (currentOffenseCard->input5R == true)
	{
		if (inputList[4] == 'R')
		{
			//UE_LOG(LogTemp, Warning, TEXT("Combo Match"));
			combo5Match = true;
			
		}
		
	}
	

	if (combo1Match == true)
	{
		comboMatch[0] = 1;
	}
	if (combo2Match == true)
	{
		comboMatch[1] = 1;
	}
	if (combo3Match == true)
	{
		comboMatch[2] = 1;
	}
	if (combo4Match == true)
	{
		comboMatch[3] = 1;
	}
	if (combo5Match == true)
	{
		comboMatch[4] = 1;
	}

	UE_LOG(LogTemp, Warning, TEXT("Combo match currently %d %d %d %d %d"), comboMatch[0], comboMatch[1], comboMatch[2], comboMatch[3], comboMatch[4]);

	for (int i = 0; i < currentOffenseCard->inputNum; i++)
	{
		if (comboMatch[i] == 0)
		{
			executeCombo = 0;
		}
	}
	//executeCombo = true;
	
	UE_LOG(LogTemp, Warning, TEXT("maxcombo is currently %d"), maxComboInputs);

	if (executeCombo == 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Combo Executed"));
		updateShooting();
		clearInputList();
	}

}
void AMyCharacter::clearInputList()
{
	for (int i = 0; i < 5; i++)
	{
		inputList[i] = '\0';
	}
}
void AMyCharacter::attackForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(0);
	}
	currentForm = 0;
}
void AMyCharacter::defenseForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(1);
	}
	currentForm = 1;
}
void AMyCharacter::flightForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(2);
	}
	currentForm = 2;
}
void AMyCharacter::counterForm()
{
	if (screenHUD)
	{
		screenHUD->UpdateForm(3);
	}
	currentForm = 3;
}
void AMyCharacter::Block()
{
}
void AMyCharacter::updateRockState()
{

	switch (rockState)
	{
	case 0:
		//spawnedProjectile = GetWorld()->SpawnActor<AMyProjectile>(throwableProjectile, HitDetect->GetComponentLocation(), FollowCamera->GetComponentRotation());
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

	
	if (inputList[0] != '\0')
	{
		if (inputResetTimerCurrent < inputResetTimer)
		{
			inputResetTimerCurrent += DeltaTime;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Clearing input list"));
			clearInputList();
			inputResetTimerCurrent = 0.f;
		}
		checkCombo();
	}

	if (isShooting == true)
	{
		if (currentForm == 0)
		{

			if (currentOffenseCard->symbolTime > 0.f)
			{
				
				if (maxActionTimer > 0.f)
				{
					currentActionTimer += DeltaTime;
					if (currentActionTimer >= maxActionTimer)
					{
						currentActionTimer = 0.f;
						maxActionTimer = 0.f;
						Shoot();
						isShooting = false;
					}
				}
				else
				{
					maxActionTimer = currentOffenseCard->symbolTime;
					Quad1Plane->SetHiddenInGame(!currentOffenseCard->quad1Spawn);
					Quad2Plane->SetHiddenInGame(!currentOffenseCard->quad2Spawn);
					Quad3Plane->SetHiddenInGame(!currentOffenseCard->quad3Spawn);
					Quad4Plane->SetHiddenInGame(!currentOffenseCard->quad4Spawn);
				}
			}
			else
			{
				Shoot();
				isShooting = false;
			}
			
		}
	}
	else
	{
		Quad1Plane->SetHiddenInGame(true);
		Quad2Plane->SetHiddenInGame(true);
		Quad3Plane->SetHiddenInGame(true);
		Quad4Plane->SetHiddenInGame(true);
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	//PlayerInputComponent->BindAction("Rock", IE_Pressed, this, &AMyCharacter::updateShooting);
	PlayerInputComponent->BindAction("LeftInput", IE_Pressed, this, &AMyCharacter::addLeftInput);
	PlayerInputComponent->BindAction("RightInput", IE_Pressed, this, &AMyCharacter::addRightInput);

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

