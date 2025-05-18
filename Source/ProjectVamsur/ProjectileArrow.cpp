// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileArrow.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectileArrow::AProjectileArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    CollisionComponent->InitSphereRadius(8.0f);
    CollisionComponent->SetCollisionProfileName("Projectile");
    CollisionComponent->OnComponentHit.AddDynamic(this, &AProjectileArrow::OnHit);
    RootComponent = CollisionComponent;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->ProjectileGravityScale = 0.3f;

}

// Called when the game starts or when spawned
void AProjectileArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectileArrow::InitVelocity(const FVector& Velocity)
{
    if (ProjectileMovement)
    {
        ProjectileMovement->Velocity = Velocity;
    }
}

void AProjectileArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor != GetOwner())
    {
        UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr);
        Destroy(); // 단일 타격 후 제거
    }
}