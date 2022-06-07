// Fill out your copyright notice in the Description page of Project Settings.


#include "BirdAIController.h"

ABirdAIController::ABirdAIController()
{
    senses=CreateDefaultSubobject<UAIPerceptionComponent>("senses");
    sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("sight");
    sightConfig->SightRadius = 600.0f;
    sightConfig->LoseSightRadius = 700.0f;
    sightConfig->PeripheralVisionAngleDegrees = 340.0f;
    sightConfig->DetectionByAffiliation.bDetectEnemies = true;
    sightConfig->DetectionByAffiliation.bDetectNeutrals = true;
    sightConfig->DetectionByAffiliation.bDetectFriendlies = true;
    sightConfig->SetMaxAge(10.0f);
    senses->ConfigureSense(*sightConfig);
    senses->SetDominantSense(sightConfig->GetSenseImplementation());

    behaviorTree=CreateDefaultSubobject<UBehaviorTreeComponent>("behaviour");

    sharedBlackboard=CreateDefaultSubobject<UBlackboardComponent>("sharedBlackboard");
}

void ABirdAIController::BeginPlay()
{
    Super::BeginPlay();
    if(ensure(senses))
        senses->OnTargetPerceptionUpdated.AddDynamic(this,&ABirdAIController::PlayerSeen);
}

void ABirdAIController::PlayerSeen(AActor* actor, FAIStimulus stimulus)
{
    ADotCharacter* dot;
    
    dot=Cast<ADotCharacter>(actor);
    if(dot)
    {
        if(stimulus.WasSuccessfullySensed())
        {
            sharedBlackboard->SetValueAsObject("Player",dot);
            sharedBlackboard->SetValueAsVector("Destination",stimulus.StimulusLocation);
            sharedBlackboard->SetValueAsBool("CanSeePlayer",true);
            UE_LOG(LogTemp,Warning,TEXT("IS Seen %f"),stimulus.GetAge());
        }
        else
        {
            UE_LOG(LogTemp,Warning,TEXT("IS Lost %f"),stimulus.GetAge());
        }
    }
}

