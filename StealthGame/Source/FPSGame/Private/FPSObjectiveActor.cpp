// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSObjectiveActor.h"
#include "FPSCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);

}

void AFPSObjectiveActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}
// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
	PlayEffects();
}



void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	PlayEffects();
	AFPSCharacter * Character = Cast<AFPSCharacter>(OtherActor);
	if (Character) // Cast succeeded
	{
		Character->bIsCarryingObjective = true;

		Destroy();
	}
}

