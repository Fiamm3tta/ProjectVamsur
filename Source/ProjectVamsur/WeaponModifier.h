// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeaponModifier.generated.h"

class AWeaponBase;
class ACubeCharacter;

UCLASS(Abstract, Blueprintable)
class PROJECTVAMSUR_API UWeaponModifier : public UObject
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintNativeEvent, Category = "Modifier")
    void ApplyToWeapon(AWeaponBase* Weapon);

    UFUNCTION(BlueprintNativeEvent, Category = "Modifier")
    void ApplyToCharacter(ACubeCharacter* Character);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Modifier Info")
    FText ModifierName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Modifier Info")
    FText ModifierDescription;
	
};
