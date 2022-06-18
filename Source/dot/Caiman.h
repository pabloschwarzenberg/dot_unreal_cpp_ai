// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "Curves/CurveFloat.h"
#include "Caiman.generated.h"

UCLASS()
class DOT_API ACaiman : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACaiman(const FObjectInitializer& oi);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category="Character")
    UBoxComponent* box;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category="Character")
    UStaticMeshComponent* mesh;
    
    UPROPERTY()
    UTimelineComponent* timeline;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    UCurveFloat* curve;

    FOnTimelineFloat InterpFunction{};
    FOnTimelineEventStatic onTimelineFinishedCallback{};

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    float range;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    int direction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    int duration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    int speed;
    
    UFUNCTION()
    void timelineAnimate(float val);
    
    UFUNCTION()
    void timelineFinished();
    
private:
    FVector start;
};
