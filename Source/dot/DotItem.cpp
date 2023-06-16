// Fill out your copyright notice in the Description page of Project Settings.


#include "DotItem.h"

// Sets default values
ADotItem::ADotItem(const FObjectInitializer& oi)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    box=oi.CreateDefaultSubobject<UBoxComponent>(this,"Box");
    RootComponent=box;
    static_mesh=oi.CreateDefaultSubobject<UStaticMeshComponent>(this,"Static Mesh");
    static_mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADotItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADotItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

