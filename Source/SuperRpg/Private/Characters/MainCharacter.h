// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Characters/BaseCharacter.h"
#include "MainCharacter.generated.h"






UCLASS()
class AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Main|Inventory")
	TSubclassOf<UInventoryWidget> InventoryWidgetClass;

	UPROPERTY(BlueprintReadOnly, Category = "Main|Inventory")
	UInventoryWidget* InventoryWidget;

	UFUNCTION(BlueprintCallable, Category = "MainCharacter|Inventory")
	void ShowInventory();

	UFUNCTION(BlueprintCallable, Category = "MainCharacter|Inventory")
	void HideInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
