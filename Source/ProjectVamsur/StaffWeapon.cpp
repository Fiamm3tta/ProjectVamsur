// Fill out your copyright notice in the Description page of Project Settings.


#include "StaffWeapon.h"
#include "AuraActor.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "CubeCharacter.h"

AStaffWeapon::AStaffWeapon()
{
    AttackInterval = 6.0f; // 오라가 유지되는 시간과 발사 주기를 다르게
    WeaponType = "Staff";
}

void AStaffWeapon::Fire()
{
    if (!AuraClass || !OwnerCharacter) return;

    FVector AimDir = Cast<ACubeCharacter>(OwnerCharacter)->GetAimDirection();
    FVector Location = OwnerCharacter->GetActorLocation();
    FRotator Rotation = FRotator::ZeroRotator;

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = OwnerCharacter;

    AAuraActor* Aura = GetWorld()->SpawnActor<AAuraActor>(AuraClass, Location, Rotation, SpawnParams);
    if (Aura)
    {
        Aura->ActivateAura(AuraDuration);
    }

    UE_LOG(LogTemp, Log, TEXT("[%s] Aura Fired!"), *GetName());
}