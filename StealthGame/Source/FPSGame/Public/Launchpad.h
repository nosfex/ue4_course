// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Launchpad.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
UCLASS()
class FPSGAME_API ALaunchpad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchpad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LaunchPad")
	float LaunchForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LaunchPad")
	float LaunchPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LaunchPad")
	UParticleSystem* LaunchParticles;


	UFUNCTION()
	void OverlapLaunchpad(UPrimitiveComponent* opc, AActor* other, UPrimitiveComponent * oc,
	int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
