// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SplitSlashModifier.h"

// Sets default values
ACubeCharacter::ACubeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 스프링암 생성
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 800.0f; 
    CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
    CameraBoom->bUsePawnControlRotation = false; 

    // 카메라 생성
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom);
    FollowCamera->bUsePawnControlRotation = false; 
	
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ACubeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
    if (WeaponClassToSpawn)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = this;

        FVector SpawnLocation = GetActorLocation();
        FRotator SpawnRotation = GetActorRotation();

        EquippedWeapon = GetWorld()->SpawnActor<AWeaponBase>(
            WeaponClassToSpawn,
            SpawnLocation,
            SpawnRotation,
            SpawnParams
        );

        if (EquippedWeapon)
        {
            EquippedWeapon->SetOwnerCharacter(this);

            USplitSlashModifier* Modifier = NewObject<USplitSlashModifier>(this);
            Modifier->ApplyToWeapon(EquippedWeapon);
        }
    }

    
}

// Called every frame
void ACubeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateTowardsCursor(DeltaTime);
}

// Called to bind functionality to input
void ACubeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ACubeCharacter::MoveHorizontal);
    PlayerInputComponent->BindAxis("MoveForward", this, &ACubeCharacter::MoveVertical);
}

void ACubeCharacter::MoveHorizontal(float Value)
{
    AddMovementInput(FVector::RightVector, Value);
}

void ACubeCharacter::MoveVertical(float Value)
{
    AddMovementInput(FVector::ForwardVector, Value);
}

FVector ACubeCharacter::GetAimDirection() const
{
    APlayerController* PC = Cast<APlayerController>(GetController());
    if (!PC) return FVector::ForwardVector;

    FVector WorldLocation, WorldDirection;
    if (PC->DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
    {
        FVector Start = WorldLocation;
        FVector End = Start + WorldDirection * 10000.0f;

        FHitResult Hit;
        FCollisionQueryParams Params;
        Params.AddIgnoredActor(this);

        if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
        {
            FVector ToHit = (Hit.Location - GetActorLocation());
            ToHit.Z = 0.0f;
            return ToHit.GetSafeNormal();
        }
        else
        {
            FVector ToCursor = (End - GetActorLocation());
            ToCursor.Z = 0.0f;
            return ToCursor.GetSafeNormal();
        }
    }

    return FVector::ForwardVector;
}


void ACubeCharacter::RotateTowardsCursor(float DeltaTime)
{
    FVector AimDir = GetAimDirection();
    if (!AimDir.IsNearlyZero())
    {
        FRotator TargetRotation = AimDir.Rotation();
        FRotator CurrentRotation = GetActorRotation();

        FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, 10.0f);
        SetActorRotation(NewRotation);
    }
}

void ACubeCharacter::AddExp(int32 Amount)
{
    CurrentExp += Amount;
    UE_LOG(LogTemp, Display, TEXT("Get %d Exp"), Amount);
    if (CurrentExp >= ExpToLevelUp)
    {
        LevelUp();
    }
}

void ACubeCharacter::LevelUp()
{
    if(MaxLevel > CurrentLevel)
    {
        CurrentLevel += 1;
    }
}