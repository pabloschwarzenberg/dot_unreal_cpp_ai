// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

// Sets default values
ABrick::ABrick(const FObjectInitializer& oi)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    box = oi.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Box"));
    RootComponent = box;
    mesh = oi.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
    mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

