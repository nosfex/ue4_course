// Fill out your copyright notice in the Description page of Project Settings.

#include "LaunchMesh.h"


// Sets default values
ALaunchMesh::ALaunchMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent( Mesh );
}

// Called when the game starts or when spawned
void ALaunchMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaunchMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaunchMesh::Launch_Implementation(FVector Direction)
{
	Mesh->AddImpulse(Direction, NAME_None, true);
}

