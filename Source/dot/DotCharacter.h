// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DotAnimInstance.h"
#include "FrutoDotItem.h"
#include "FlorDotItem.h"
#include "DotCharacter.generated.h"

UCLASS()
class DOT_API ADotCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADotCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    void MoveX(float delta);
    void MoveY(float delta);
    
    void DotCrouch();
    void DotJump();
    void DotCrouchStop();
    
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,AActor* OtherActor,
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                        const FHitResult& Sweep);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
    UDotAnimInstance* animBP;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
    int flores;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
    int frutos;
};
