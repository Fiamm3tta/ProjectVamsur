// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponModifier.h"
#include "SplitSlashModifier.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTVAMSUR_API USplitSlashModifier : public UWeaponModifier
{
	GENERATED_BODY()

public:

    virtual void ApplyToWeapon_Implementation(class AWeaponBase* Weapon) override;
	
};
