// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISense.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AIPerceptionComponent.h"
#include <Perception/AISenseConfig_Sight.h>
#include "Perception/AIPerceptionTypes.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Bird.h"
#include "DotCharacter.h"
#include "BirdAIController.generated.h"
/**
 * 
 */
UCLASS()
class DOT_API ABirdAIController : public AAIController
{
	GENERATED_BODY()

public:
    ABirdAIController();
    
    virtual void OnPossess(APawn* InPawn) override;
    
    virtual void BeginPlay() override;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
    UAIPerceptionComponent* senses;
    
    UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="AI")
    UAISenseConfig_Sight* sightConfig;
        
    UFUNCTION()
    void PlayerSeen(AActor* actor, FAIStimulus stimulus);

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
    bool canSeePlayer;

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
    FVector location;
     
    UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="AI")
    UBlackboardComponent* sharedBlackboard;
};
