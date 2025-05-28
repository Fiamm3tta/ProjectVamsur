// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeaponType.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    None     UMETA(DisplayName = "None"),
    Sword    UMETA(DisplayName = "Sword"),
    Bow      UMETA(DisplayName = "Bow"),
    Staff    UMETA(DisplayName = "Staff")
};