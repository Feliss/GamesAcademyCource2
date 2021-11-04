// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "InventoryWidget")
	void ShowForCharacter(ABaseCharacter* BaseCharacter);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "InventoryWidget")
	void Hide();
};
