// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnemyCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class PROJECTVAMSUR_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float TimeSinceLastSpawn = 0.0f;

	void SpawnWave();

	UPROPERTY()
    AActor* TargetPlayer;

	UPROPERTY(EditAnywhere, Category = "Spawner")
    TSubclassOf<AEnemyCharacter> EnemyClass;

    UPROPERTY(EditAnywhere, Category = "Spawner")
    float SpawnInterval = 5.0f;

    UPROPERTY(EditAnywhere, Category = "Spawner")
    int32 SpawnCountPerWave = 3;

    UPROPERTY(EditAnywhere, Category = "Spawner")
    float SpawnRadius = 1000.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
