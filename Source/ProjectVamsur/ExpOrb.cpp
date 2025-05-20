// Fill out your copyright notice in the Description page of Project Settings.


#include "ExpOrb.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CubeCharacter.h"

// Sets default values
AExpOrb::AExpOrb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->SetSphereRadius(32.0f);
    CollisionComponent->SetCollisionProfileName("OverlapAll");
    RootComponent = CollisionComponent;

}

// Called when the game starts or when spawned
void AExpOrb::BeginPlay()
{
	Super::BeginPlay();
	
	TargetPlayer = Cast<ACubeCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AExpOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!TargetPlayer) return;

    float Distance = FVector::Dist(GetActorLocation(), TargetPlayer->GetActorLocation());

    if (Distance <= AttractRadius)
    {
        FVector Direction = (TargetPlayer->GetActorLocation() - GetActorLocation()).GetSafeNormal();
        SetActorLocation(GetActorLocation() + Direction * MoveSpeed * DeltaTime);
    }
}

void AExpOrb::NotifyActorBeginOverlap(AActor* OtherActor)
{
    if (ACubeCharacter* Player = Cast<ACubeCharacter>(OtherActor))
    {
        Player->AddExp(ExpValue);
        Destroy();
    }
}

