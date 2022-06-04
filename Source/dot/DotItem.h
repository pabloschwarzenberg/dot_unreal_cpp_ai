// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DotItem.generated.h"

UCLASS()
class DOT_API ADotItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADotItem(const FObjectInitializer& oi);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category="Character")
    UBoxComponent* box;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category="Character")
    UStaticMeshComponent* static_mesh;
};
