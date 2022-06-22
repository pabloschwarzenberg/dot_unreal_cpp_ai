// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class DOT_API Node
{
public:
    int id;
    int d;
    int p;
};
/**
 * 
 */
class DOT_API Graph
{
public:
    Graph(int nodes);
    virtual ~Graph();

    bool isConnected(int u, int v);
    int cost(int u, int v);
    void buildGrid();
    const Node& get(int i);
    void prim(int s);
    FString serialize();

    const static int INFINITE_COST = 1024*1024*1024;

protected:
    void initialize();
    void addNeighbour(int nodo, int fila, int columna);

private:
    Node* V;
    int nodes;
    int** adj;
};
