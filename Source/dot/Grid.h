// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DOT_API Grid
{
public:
    Grid(int cells);
    virtual ~Grid();
    void build();
    bool isBrick(int row, int col);
    FString serialize();

private:
    int cells;
    char** m;
};

void error_fatal(const char* mensaje);
