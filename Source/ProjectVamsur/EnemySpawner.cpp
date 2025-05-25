// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyCharacter.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	TargetPlayer = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceLastSpawn += DeltaTime;

    if (TimeSinceLastSpawn >= SpawnInterval)
    {
        SpawnWave();
        TimeSinceLastSpawn = 0.0f;
    }
}

void AEnemySpawner::SpawnWave()
{
    if (!EnemyClass || !TargetPlayer) return;

    for (int32 i = 0; i < SpawnCountPerWave; ++i)
    {
        FVector PlayerLoc = TargetPlayer->GetActorLocation();
        FVector RandomOffset = FMath::VRand() * FMath::FRandRange(300.0f, SpawnRadius);
        FVector SpawnLocation = PlayerLoc + RandomOffset;
        SpawnLocation.Z = PlayerLoc.Z;

        FActorSpawnParameters SpawnParams;
        GetWorld()->SpawnActor<AEnemyCharacter>(EnemyClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
    }
}