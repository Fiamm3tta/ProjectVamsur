// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeaponType.h"
#include "ModifierLibrary.generated.h"

class UWeaponModifier;

UCLASS()
class PROJECTVAMSUR_API UModifierLibrary : public UObject
{
	GENERATED_BODY()
	
public:
    
    UFUNCTION(BlueprintCallable, Category = "Modifier")
    static TArray<TSubclassOf<UWeaponModifier>> GetFilteredModifiers(EWeaponType WeaponType);

private:
    static TMap<EWeaponType, TArray<TSubclassOf<UWeaponModifier>>> ModifierMap;
    
	static bool bInitialized;

	static void InitializeModifiers();
};
