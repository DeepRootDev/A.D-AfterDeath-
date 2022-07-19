// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ScreenHUD.h"
#include "MyDataAsset.h"
#include "Card.h"
#include "MyCharacter.generated.h"

UCLASS()
class ADTEST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	char inputList[5];

public:

	

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* HitDetect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AMyProjectile> throwableProjectile;

	UPROPERTY(EditAnywhere)
		UCard* currentOffenseCard;

	UPROPERTY(EditAnywhere)
		UCard* currentDefenseCard;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AMyProjectile> actualProjectile;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad1AnimPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad1Plane;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad2AnimPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad2Plane;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad3;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad3AnimPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad3Plane;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad4AnimPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Quad4Plane;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		float allQuadDist = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		float quad1Dist = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		float quad2Dist = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		float quad3Dist = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		float quad4Dist = 0.f;

	float inputResetTimerCurrent = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		float inputResetTimer = 5.f;

	class AMyProjectile* quad1Projectile;
	class AMyProjectile* quad2Projectile;
	class AMyProjectile* quad3Projectile;
	class AMyProjectile* quad4Projectile;

	void lift();

	void Shoot();

	void addLeftInput();
	
	void addRightInput();

	void checkOffenseCombo();

	void clearInputList();

	void attackForm();
	
	void defenseForm();
	
	void flightForm();

	void counterForm();

	void Block();

	void updateRockState();

	int rockState = 0;

	int currentForm = 0;

	float currentActionTimer = 0.f;

	float maxActionTimer = 0.f;

	bool isShooting = false;

	void updateShooting();

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class AHUD> menuHUD;

public:
	// Sets default values for this character's properties
	AMyCharacter();

private:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	class AScreenHUD* screenHUD;

	/** Called for side to side input */
	void MoveRight(float Value);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
