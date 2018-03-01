// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = Mesh;
	

	AttractSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttractSphere"));
	AttractSphere->SetSphereRadius(5000);
	AttractSphere->SetupAttachment(Mesh);


	DestroySphere = CreateDefaultSubobject<USphereComponent>(TEXT("DestroySphere"));
	DestroySphere->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OverlapInnerSphere);
	DestroySphere->SetSphereRadius(100);
	DestroySphere->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent*> AttractComponents;
	AttractSphere->GetOverlappingComponents(AttractComponents);
	if (AttractComponents.Num() != 0)
	{
		for (UPrimitiveComponent* pc : AttractComponents)
		{
			pc->AddRadialForce(GetActorLocation(), AttractSphere->GetScaledSphereRadius(), -3000.0f, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}

}

void ABlackHole::OverlapInnerSphere(UPrimitiveComponent* opc, AActor* other, UPrimitiveComponent * oc, 
									int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(other)
	{
		other->Destroy();
	}
}

