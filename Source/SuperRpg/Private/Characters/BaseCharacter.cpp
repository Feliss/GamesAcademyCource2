// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HitPoints = 100.f;
	DebuffDefence = 1.f;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABaseCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// Damage calculation
	float CalculatedDamage = DamageAmount * DebuffDefence;
	float NewHitPoint = FMath::Clamp(HitPoints - CalculatedDamage, 0.f, HitPoints);

	// Calculation the amount of damage actually applied
	float ActualDamage = HitPoints - NewHitPoint;
	
	// Apply damage
	HitPoints = NewHitPoint;

	OnTakeDamage(HitPoints);

	return ActualDamage;
}

void ABaseCharacter::GoToShelter()
{
	OnShelter.Broadcast(100.f);
}

void ABaseCharacter::CalculateCircle(float R, float& OutL, float& OutS, float& OutSsec)
{
	OutL = R * 2.f;

	OutS = R * R;

	OutSsec = R - 10.f;

	//UObject* Object = NewObject<UObject>();
	//Object->BeginDestroy();
}