// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraActor.generated.h"

UCLASS()
class PROJECTVAMSUR_API AAuraActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraActor();

	void ActivateAura(float Duration);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
    class USphereComponent* Area;

    UPROPERTY(EditDefaultsOnly)
    float DamagePerTick = 10.0f;

    UPROPERTY(EditDefaultsOnly)
    float TickInterval = 1.0f;

    FTimerHandle TickTimer;
    FTimerHandle LifetimeTimer;

    void DealDamage();
    void EndAura();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
