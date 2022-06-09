// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BirdAIController.h"
#include "FlyToTask.generated.h"

/**
 * 
 */
UCLASS()
class DOT_API UFlyToTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
    
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
