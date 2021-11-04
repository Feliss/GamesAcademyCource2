// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class UItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDataAsset")
	FName ItemName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDataAsset")
	TSoftClassPtr<AActor> ActorToUse;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDataAsset")
	UStaticMesh* MeshToUse;

};
