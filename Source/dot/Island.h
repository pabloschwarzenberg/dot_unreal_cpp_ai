// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Brick.h"
#include "Grid.h"
#include "Island.generated.h"

UCLASS()
class DOT_API AIsland : public AActor
{
	GENERATED_BODY()
	
public:	
	AIsland(const FObjectInitializer& oi);
    virtual ~AIsland();

    virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PCG")
    UBoxComponent* box;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PCG")
    UStaticMeshComponent* mesh;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "PCG")
    TSubclassOf<ABrick> brick_class;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PCG")
    float brick_size;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PCG")
    FString logfile;
    
    void Create();

private:
    int cells;
    class ABrick*** bricks;
};
