// Fill out your copyright notice in the Description page of Project Settings.


#include "DotHUD.h"
#include "DotCharacter.h"

void ADotHUD::DrawHUD()
{
    Super::DrawHUD();
    if(hudFont)
    {
        ADotCharacter* dot = Cast<ADotCharacter>(GetOwningPawn());
        if(dot)
        {
            DrawText(FString::FromInt(dot->frutos),FColor::Black,200,120,hudFont,3,false);
            DrawText(FString::FromInt(dot->flores),FColor::Black,450,120,hudFont,3,false);
        }
    }
}
