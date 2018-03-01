// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Launchable.h"
#include "LaunchMesh.generated.h"

UCLASS()
class FPSGAME_API ALaunchMesh : public AActor, public ILaunchable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchMesh();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* Mesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Launch")
	void Launch(FVector Direction);

	virtual void Launch_Implementation(FVector Direction) override;
	
	
};
