// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "SwordWeapon.generated.h"

class AProjectileSlash;

UCLASS()
class PROJECTVAMSUR_API ASwordWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
    ASwordWeapon();

    virtual void Fire() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slash")
    int32 NumSlashProjectiles = 1; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slash")
    float TotalAngle = 0.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float SlashSpeed = 1000.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float SlashRange = 1000.0f;

protected:

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<AProjectileSlash> SlashProjectileClass;
	
};
