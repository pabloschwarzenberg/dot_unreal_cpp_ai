// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"

// Sets default values
ABird::ABird(const FObjectInitializer& oi)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    UCapsuleComponent* capsula;
	PrimaryActorTick.bCanEverTick = true;
    attack_range=oi.CreateDefaultSubobject<UBoxComponent>(this,"Attack Range");
    attack_range->SetBoxExtent(FVector(3,3,3));
    attack_range->SetupAttachment(RootComponent);
    capsula=GetCapsuleComponent();
    capsula->SetCapsuleSize(11,11,true);
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

