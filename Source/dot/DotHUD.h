// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DotHUD.generated.h"

/**
 * 
 */
UCLASS()
class DOT_API ADotHUD : public AHUD
{
	GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
    UFont* hudFont;

public:
    virtual void DrawHUD() override;	
};
