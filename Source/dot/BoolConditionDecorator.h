// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BoolConditionDecorator.generated.h"

/**
 * 
 */
UCLASS()
class DOT_API UBoolConditionDecorator : public UBTDecorator
{
	GENERATED_BODY()
public:
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
    FName Key;
    
protected:

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
