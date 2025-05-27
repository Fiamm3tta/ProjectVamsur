// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitSlashModifier.h"
#include "SwordWeapon.h"

void USplitSlashModifier::ApplyToWeapon_Implementation(AWeaponBase* Weapon)
{
    if (ASwordWeapon* Sword = Cast<ASwordWeapon>(Weapon))
    {
        Sword->TotalAngle += 30.0f;
        Sword->NumSlashProjectiles += 2;
    }
}