// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Launchable.generated.h"
/**
 * 
 */
UINTERFACE(BlueprintType)
class FPSGAME_API ULaunchable : public UInterface
{
public:
	GENERATED_BODY()
};

class FPSGAME_API ILaunchable
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Launch")

		void Launch(FVector Direction);
};
