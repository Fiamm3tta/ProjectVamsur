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

    FVector Forward = Cast<ACubeCharacter>(OwnerCharacter)->GetAimDirection();
    FVector MuzzleLocation = OwnerCharacter->GetActorLocation() + Forward * 10.0f;
    FRotator MuzzleRotation = Forward.Rotation();

    int32 Count = FMath::Max(1, NumSlashProjectiles);
    float AngleStep = (Count > 1) ? TotalAngle / (Count - 1) : 0.0f;

    for(int32 i = 0; i < Count; i++)
    {
        float AngleOffset = -TotalAngle / 2 + AngleStep * i;

        FRotator Rotated = Forward.Rotation();
        Rotated.Yaw += AngleOffset;

        FVector SlashDirection = Rotated.Vector();

        AProjectileSlash* Projectile = GetWorld()->SpawnActor<AProjectileSlash>(
            SlashProjectileClass,
            MuzzleLocation,
            MuzzleRotation
        );

        if (Projectile)
        {
            Projectile->InitVelocity(SlashDirection * SlashSpeed);
        }

    }
}