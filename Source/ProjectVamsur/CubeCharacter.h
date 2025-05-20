// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CubeCharacter.generated.h"

UCLASS()
class PROJECTVAMSUR_API ACubeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACubeCharacter();

	void RotateTowardsCursor(float DeltaTime);
	
	FVector GetAimDirection() const;

	void MoveHorizontal(float Value);

    void MoveVertical(float Value);

	void AddExp(int32 Amount);
		
	void LevelUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	AWeaponBase* EquippedWeapon;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	TSubclassOf<AWeaponBase> WeaponClassToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevel = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevel = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    float CurrentExp = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    float ExpToLevelUp = 100.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
