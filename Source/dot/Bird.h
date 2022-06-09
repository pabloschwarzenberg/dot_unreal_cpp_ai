// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Bird.generated.h"

UCLASS()
class DOT_API ABird : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABird(const FObjectInitializer& oi);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category="IA")
    UBoxComponent* attack_range;
    
    UPROPERTY(EditAnywhere, Category = "IA")
    UBehaviorTree* behavior;
};
