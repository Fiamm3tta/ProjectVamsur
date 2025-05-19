// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AttackInterval = 1.0f;
    LastAttackTime = -AttackInterval;
    OwnerCharacter = nullptr;

}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TryAutoFire(DeltaTime);

}

void AWeaponBase::SetOwnerCharacter(ACharacter* InOwner)
{
    OwnerCharacter = InOwner;
}

void AWeaponBase::SetAttackInterval(float Interval)
{
    AttackInterval = Interval;
}

bool AWeaponBase::CanFire() const
{
    float CurrentTime = GetWorld()->GetTimeSeconds();
    return (CurrentTime - LastAttackTime) >= AttackInterval;
}

void AWeaponBase::TryAutoFire(float DeltaTime)
{
    if (CanFire())
    {
        Fire();
        LastAttackTime = GetWorld()->GetTimeSeconds();
    }
}

void AWeaponBase::ApplyModifier(UWeaponModifier* Modifier)
{

}