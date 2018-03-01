// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

UCLASS()
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Spectator")
	TSubclassOf<AActor> SpectatingViewpointClass;
public:

	AFPSGameMode();

	UFUNCTION(BlueprintImplementableEvent, Category = GameplayMission)
	void OnMissionCompleted(APawn* InstigatorPawn);
	void CompleteMission(APawn* InstigatorPawn);
};



