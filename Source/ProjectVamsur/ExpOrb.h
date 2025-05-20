// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExpOrb.generated.h"

class USphereComponent;
class ACubeCharacter;

UCLASS()
class PROJECTVAMSUR_API AExpOrb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExpOrb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
    USphereComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, Category = "Exp")
    int32 ExpValue = 10;

    UPROPERTY(EditAnywhere, Category = "Exp")
    float AttractRadius = 500.0f;

    UPROPERTY(EditAnywhere, Category = "Exp")
    float MoveSpeed = 300.0f;

    UPROPERTY()
    ACubeCharacter* TargetPlayer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
