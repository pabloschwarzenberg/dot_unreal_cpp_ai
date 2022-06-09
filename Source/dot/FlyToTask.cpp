// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyToTask.h"

EBTNodeResult::Type UFlyToTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ABirdAIController* aiController = Cast<ABirdAIController>(OwnerComp.GetAIOwner());
    ACharacter* target=Cast<ACharacter>(aiController->sharedBlackboard->GetValueAsObject("Player"));
    if(target)
    {
        aiController->MoveToActor(target, 100.0f);
        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Failed;
}
