// Fill out your copyright notice in the Description page of Project Settings.


#include "BowWeapon.h"
#include "ProjectileArrow.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "CubeCharacter.h"

ABowWeapon::ABowWeapon()
{
    AttackInterval = 0.8f; // 검보다 조금 빠르게 설정
    WeaponType = "Bow";
}

void ABowWeapon::Fire()
{
    if (!ArrowProjectileClass || !OwnerCharacter) return;

    FVector AimDir = Cast<ACubeCharacter>(OwnerCharacter)->GetAimDirection();
    FVector MuzzleLocation = OwnerCharacter->GetActorLocation() + OwnerCharacter->GetActorForwardVector() * 100.0f;
    FRotator MuzzleRotation = OwnerCharacter->GetActorRotation();

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = OwnerCharacter;

    AProjectileArrow* Projectile = GetWorld()->SpawnActor<AProjectileArrow>(
        ArrowProjectileClass,
        MuzzleLocation,
        MuzzleRotation,
        SpawnParams
    );

    if (Projectile)
    {
        FVector LaunchDirection = OwnerCharacter->GetActorForwardVector();
        Projectile->InitVelocity(LaunchDirection * ArrowSpeed);
    }

    UE_LOG(LogTemp, Log, TEXT("[%s] Bow Fired!"), *GetName());
}