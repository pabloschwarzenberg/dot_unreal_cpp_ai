// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BirdAIController.h"
#include "LookAroundService.generated.h"

/**
 * 
 */
UCLASS()
class DOT_API ULookAroundService : public UBTService
{
	GENERATED_BODY()
public:
    ULookAroundService();
    
    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
    
protected:
    bool lastCanSeePlayer;
};
