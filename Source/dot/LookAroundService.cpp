// Fill out your copyright notice in the Description page of Project Settings.


#include "LookAroundService.h"

ULookAroundService::ULookAroundService()
{
    bCreateNodeInstance = true;
    lastCanSeePlayer=false;
}

void ULookAroundService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    ABirdAIController* aiController =
    Cast<ABirdAIController>(OwnerComp.GetAIOwner());
    if(aiController)
    {
        aiController->sharedBlackboard->SetValueAsBool("CanSeePlayer",aiController->canSeePlayer);
        if(lastCanSeePlayer!=aiController->canSeePlayer)
        {
            aiController->sharedBlackboard->SetValueAsVector("Location",aiController->location);
        }
        lastCanSeePlayer=aiController->canSeePlayer;
        UE_LOG(LogTemp, Warning, TEXT("Blackboard data is set"));
    }
}
