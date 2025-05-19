// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraActor.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"


// Sets default values
AAuraActor::AAuraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Area = CreateDefaultSubobject<USphereComponent>(TEXT("AuraArea"));
    Area->InitSphereRadius(300.0f);
    Area->SetCollisionProfileName("OverlapAllDynamic");
    RootComponent = Area;
}

// Called when the game starts or when spawned
void AAuraActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAuraActor::ActivateAura(float Duration)
{
    GetWorldTimerManager().SetTimer(TickTimer, this, &AAuraActor::DealDamage, TickInterval, true);
    GetWorldTimerManager().SetTimer(LifetimeTimer, this, &AAuraActor::EndAura, Duration, false);
}

void AAuraActor::DealDamage()
{
    TArray<AActor*> OverlappingActors;
    Area->GetOverlappingActors(OverlappingActors, ACharacter::StaticClass());

    for (AActor* Actor : OverlappingActors)
    {
        if (Actor && Actor != GetOwner())
        {
            UGameplayStatics::ApplyDamage(Actor, DamagePerTick, GetInstigatorController(), this, nullptr);
        }
    }
}

void AAuraActor::EndAura()
{
    Destroy();
}
