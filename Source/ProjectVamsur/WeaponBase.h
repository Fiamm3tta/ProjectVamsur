// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class PROJECTVAMSUR_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 마지막 공격 시간
    float LastAttackTime;

    // 공격 간격 (초)
    float AttackInterval;

    // 소유 플레이어
    UPROPERTY()
    ACharacter* OwnerCharacter;

    // 무기 타입: "Sword", "Bow", "Staff"
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponType;

    // 현재 시간과 공격 간격을 기반으로 자동 발사 체크
    bool CanFire() const;

    // 내부용 자동 발사 트래킹
    void TryAutoFire(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 무기 발사 인터페이스
    virtual void Fire() PURE_VIRTUAL(AWeaponBase::Fire, );

    // 소유자 설정
    void SetOwnerCharacter(ACharacter* InOwner);

    // 공격 주기 설정
    void SetAttackInterval(float Interval);

    // 강화 효과 적용
    virtual void ApplyModifier(class UWeaponModifier* Modifier);

    FName GetWeaponType() const { return WeaponType; }
};
