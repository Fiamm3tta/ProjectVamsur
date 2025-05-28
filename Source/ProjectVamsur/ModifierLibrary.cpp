// Fill out your copyright notice in the Description page of Project Settings.


#include "ModifierLibrary.h"
#include "WeaponModifier.h"

TMap<EWeaponType, TArray<TSubclassOf<UWeaponModifier>>> UModifierLibrary::ModifierMap;
bool UModifierLibrary::bInitialized = false;

void UModifierLibrary::InitializeModifiers()
{
    if (bInitialized) return;

    // common

    // sword

    // bow

    // staff

    bInitialized = true;
}

TArray<TSubclassOf<UWeaponModifier>> UModifierLibrary::GetFilteredModifiers(EWeaponType WeaponType)
{
    InitializeModifiers();

    static TArray<TSubclassOf<UWeaponModifier>> Result;
    Result.Reset();

    Result.Append(ModifierMap.FindOrAdd(EWeaponType::None));
    Result.Append(ModifierMap.FindOrAdd(WeaponType));
    return Result;
}
