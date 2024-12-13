// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph.h"
#include "Queue.h"

using namespace std;

void error_fatal(const char* s)
{   
    FString mensaje(s);
    //UE_LOG(LogTemp, Fatal, TEXT("%s"),mensaje.GetCharArray().GetData());
    UE_LOG(LogTemp, Fatal, TEXT("%hs"),s);
}

bool operator<(Node a, Node b)
{
    if (a.d < b.d)
        return true;
    else
        return false;
}

bool operator==(Node a, Node b)
{
    if (a.id == b.id)
        return true;
    else
        return false;
}

Graph::Graph(int nodes)
{
    int i, j;

    this->nodes = nodes;
    this->V = new Node[nodes];
    if (this->V == nullptr)
        error_fatal("Error creando Graph");
    initialize();
    adj = new int*[nodes];
    if (adj == nullptr)
        error_fatal("Error creando matriz de adyacencia");
    for (i = 0; i < nodes; i++)
    {
        adj[i] = new int[nodes];
        if (adj[i] == nullptr)
            error_fatal("Error creando matriz de adyacencia");
        for (j = 0; j < nodes; j++)
            adj[i][j] = -1;
    }
}

Graph::~Graph()
{
    int i;

    if (V != nullptr)
        delete V;
    if (adj != nullptr)
    {
        for (i = 0; i < nodes; i++)
            delete adj[i];
        delete adj;
    }
}

void Graph::addNeighbour(int nodo, int fila, int columna)
{
    int vecino;
    int nodos_grilla = (int)sqrt(nodes);

    if (fila < 0 || fila >= nodos_grilla || columna < 0 || columna >= nodos_grilla)
        return;

    vecino = fila * nodos_grilla + columna;
    if (adj[nodo][vecino] == -1 && adj[vecino][nodo] == -1)
    {
        adj[nodo][vecino] = rand() % 100;
        adj[vecino][nodo] = adj[nodo][vecino];
    }
}

void Graph::buildGrid()
{
    int i;
    int fila;
    int columna;
    int nodos_grilla = (int)sqrt(nodes);

    srand((int)time(NULL));
    for (i = 0; i < nodes; i++)
    {
        columna = i % nodos_grilla;
        fila = (i - columna) / nodos_grilla;

        addNeighbour(i, fila, columna + 1);
        addNeighbour(i, fila, columna - 1);
        addNeighbour(i, fila + 1, columna);
        addNeighbour(i, fila - 1, columna);
    }
}

void Graph::initialize()
{
    int i;
    for (i = 0; i < nodes; i++)
    {
        V[i].id = i;
        V[i].d = Graph::INFINITE_COST;
        V[i].p = -1;
    }
}

bool Graph::isConnected(int u, int v)
{
    if (adj[u][v] == -1)
        return false;
    else
        return true;
}

int Graph::cost(int u, int v)
{
    return adj[u][v];
}

void Graph::prim(int s)
{
    int v;
    Node u;
    Queue<Node> Q;
    initialize();
    V[s].d = 0;

    for (v = 0; v < nodes; v++)
        Q.encolar(V[v]);

    while (!Q.vacia())
    {
        u = Q.minimo();
        Q.extraer(u);
        for (v = 0; v < nodes; v++)
        {
            if (isConnected(u.id, v))
            {
                if (Q.contiene(V[v]) && cost(u.id, v) < V[v].d)
                {
                    V[v].d = cost(u.id, v);
                    V[v].p = u.id;
                }
            }
        }
    }
}

FString Graph::serialize()
{
    int i;
    FString buffer;
    for (i = 0; i < nodes; i++)
    {
        buffer+=FString::Printf(TEXT("%d, p=%d, c=%d\n"),i,V[i].p,V[i].d);
    }
    return buffer;
}

const Node& Graph::get(int i)
{
    return V[i];
}
