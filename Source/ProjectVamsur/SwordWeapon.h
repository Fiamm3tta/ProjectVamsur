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

protected:
    // 검기 발사체 클래스 지정
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<AProjectileSlash> SlashProjectileClass;

    // 발사 거리/속도 등 조절
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float SlashSpeed = 1000.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float SlashRange = 1000.0f;
	
};
