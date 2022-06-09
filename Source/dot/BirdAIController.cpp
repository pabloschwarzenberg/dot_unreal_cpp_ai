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
    sightConfig->SetMaxAge(5.0f);
    senses->ConfigureSense(*sightConfig);
    senses->SetDominantSense(sightConfig->GetSenseImplementation());

    senses->OnTargetPerceptionUpdated.AddDynamic(this,&ABirdAIController::PlayerSeen);
    
    canSeePlayer=false;
    location=FVector(0,0,0);
    sharedBlackboard=CreateDefaultSubobject<UBlackboardComponent>("sharedBlackboard");
}

void ABirdAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ABirdAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    
    ABird* bird = Cast<ABird>(InPawn);
    if(bird && bird->behavior)
    {
        sharedBlackboard->InitializeBlackboard(*bird->behavior->BlackboardAsset);
        RunBehaviorTree(bird->behavior);
    }
}

void ABirdAIController::PlayerSeen(AActor* actor, FAIStimulus stimulus)
{
    ADotCharacter* dot;
    
    dot=Cast<ADotCharacter>(actor);
    if(dot)
    {
        sharedBlackboard->SetValueAsObject("Player",dot);
        if(stimulus.WasSuccessfullySensed())
        {
            location=stimulus.StimulusLocation;
            canSeePlayer=true;
            UE_LOG(LogTemp,Warning,TEXT("IS Seen %f"),stimulus.GetAge());
        }
        else
        {
            location=stimulus.StimulusLocation;
            canSeePlayer=false;
            UE_LOG(LogTemp,Warning,TEXT("IS Lost %f"),stimulus.GetAge());
            
        }
    }
}
