// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Widgets/InventoryWidget.h"
#include "BaseCharacter.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShelterDelegate, float, Height);




UCLASS()
class ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics")
	float DebuffDefence;

	// Max Hit Point of chacter
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics")
	float MaxHitPoints;

	// Hit Point of chacter
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics")
	float HitPoints;
	
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, EditAnywhere, Category = "Main|Behaviour")
	FShelterDelegate OnShelter;

	UFUNCTION(BlueprintCallable, Category = "MainCharacter|Damage")
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable, Category = "MainCharacter|Damage")
	void GoToShelter();

	UFUNCTION(BlueprintCallable, Category = "MainCharacter|Damage")
	void CalculateCircle(float R, float& OutL, float& OutS, float& OutSsec);

	// Implemented in Blueprints
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "MainCharacter|Damage")
	void OnTakeDamage(float TotalHitPoints);

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Math")
	static FQuat RotatorToQuat(const FRotator& Rotator);
};
