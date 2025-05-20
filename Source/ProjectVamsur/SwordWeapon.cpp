// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordWeapon.h"
#include "ProjectileSlash.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "CubeCharacter.h"

ASwordWeapon::ASwordWeapon()
{
    AttackInterval = 1.0f;
    WeaponType = "Sword";
}

void ASwordWeapon::Fire()
{
    if (!SlashProjectileClass || !OwnerCharacter) return;

    FVector AimDir = Cast<ACubeCharacter>(OwnerCharacter)->GetAimDirection();
    FVector MuzzleLocation = OwnerCharacter->GetActorLocation() + AimDir * 100.0f;
    FRotator MuzzleRotation = AimDir.Rotation();

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = OwnerCharacter;

    AProjectileSlash* Projectile = GetWorld()->SpawnActor<AProjectileSlash>(
        SlashProjectileClass,
        MuzzleLocation,
        MuzzleRotation,
        SpawnParams
    );

    if (Projectile)
    {
        Projectile->InitVelocity(AimDir * SlashSpeed);
    }

    UE_LOG(LogTemp, Log, TEXT("[%s] Sword Slash Fired!"), *GetName());
}