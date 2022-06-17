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
    timeline=oi.CreateDefaultSubobject<UTimelineComponent>(this,"Timeline");
    timeline->SetLooping(false);
    InterpFunction.BindUFunction(this, FName{ TEXT("timelineAnimate") });
    onTimelineFinishedCallback.BindUFunction(this, FName{ TEXT("timelineFinished") });
    range=200;
    direction=1;
}

// Called when the game starts or when spawned
void ACaiman::BeginPlay()
{
	Super::BeginPlay();
    if(curve)
    {
        timeline->AddInterpFloat(curve, InterpFunction, FName{ TEXT("AnimateXYZ") });
        timeline->PlayFromStart();
    }
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

void ACaiman::timelineAnimate(float val)
{
    FVector target=GetActorLocation()+FVector(direction*val*range,0,0);
    
    SetActorLocation(target);
}

void ACaiman::timelineFinished()
{
    direction*=-1;
    if(direction==-1)
    {
        mesh->SetWorldRotation(FRotator(0,180,0));
    }
    else
    {
        mesh->SetWorldRotation(FRotator(0,0,0));
    }
    timeline->PlayFromStart();
}
