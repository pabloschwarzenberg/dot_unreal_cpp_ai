// Fill out your copyright notice in the Description page of Project Settings.


#include "BoolConditionDecorator.h"

bool UBoolConditionDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    UBlackboardComponent* blackboard=OwnerComp.GetBlackboardComponent();
    if(blackboard)
    {
        if(blackboard->IsKeyOfType<UBlackboardKeyType_Bool>(blackboard->GetKeyID(Key)))
        {
            bool value;
            value=blackboard->GetValueAsBool(Key);
            return value;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

