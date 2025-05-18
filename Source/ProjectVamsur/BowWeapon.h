// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "BowWeapon.generated.h"

class AProjectileArrow;

UCLASS()
class PROJECTVAMSUR_API ABowWeapon : public AWeaponBase
{
	GENERATED_BODY()
	
public:
    ABowWeapon();

    virtual void Fire() override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<AProjectileArrow> ArrowProjectileClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float ArrowSpeed = 1500.0f;
};
