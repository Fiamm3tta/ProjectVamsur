// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "StaffWeapon.generated.h"

class AAuraActor;

UCLASS()
class PROJECTVAMSUR_API AStaffWeapon : public AWeaponBase
{
	GENERATED_BODY()
	
public:
    AStaffWeapon();

    virtual void Fire() override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<AAuraActor> AuraClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float AuraDuration = 5.0f;
};
