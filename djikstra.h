#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include <iostream>
#include <list>
#include <tuple>
#include <queue>
#include <vector>
#define INFINITO 10000000
#pragma once

using namespace std;

class Djikstra
{
private:
    int V;
    list<tuple<int, int, int> > * adj;

public:
    Djikstra();
    Djikstra(int V);
    //~Grafo();
    void addAresta(int v1, int v2, int custo, int direcao);
    tuple <vector<int>,int, double> dijkstra(int orig, int dest);
};


#endif // DJIKSTRA_H
