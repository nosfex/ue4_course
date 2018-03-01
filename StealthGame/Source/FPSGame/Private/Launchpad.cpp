// Fill out your copyright notice in the Description page of Project Settings.

#include "Launchpad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Launchable.h"
#include "FPSCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALaunchpad::ALaunchpad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh")); 
	
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	
	CollisionBox->SetBoxExtent(FVector(200.0f));
	SetRootComponent(CollisionBox);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALaunchpad::OverlapLaunchpad);

	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALaunchpad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaunchpad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaunchpad::OverlapLaunchpad(UPrimitiveComponent* opc, AActor* other, UPrimitiveComponent * oc,
	int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (other->GetClass()->ImplementsInterface(ULaunchable::StaticClass()))
	{
		FRotator ActorRotation = GetActorRotation();
		ActorRotation.Pitch += LaunchPitch;
		FVector ImpulseDirection = ActorRotation.Vector() * LaunchForce;
 		ILaunchable* launch = Cast<ILaunchable>(other);
		launch->Execute_Launch(other, ImpulseDirection);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), LaunchParticles, GetActorLocation());
	}
}

