// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DotAnimInstance.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class DOT_API UDotAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
    bool isJumping;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
    bool isMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
    bool isCrouching;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
    bool isSwimming;
};
