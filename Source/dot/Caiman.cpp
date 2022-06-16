// Fill out your copyright notice in the Description page of Project Settings.


#include "Caiman.h"

// Sets default values
ACaiman::ACaiman(const FObjectInitializer& oi)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    box=oi.CreateDefaultSubobject<UBoxComponent>(this,"Box");
    RootComponent=box;
    mesh=oi.CreateDefaultSubobject<UStaticMeshComponent>(this,"Mesh");
    mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACaiman::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACaiman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACaiman::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

