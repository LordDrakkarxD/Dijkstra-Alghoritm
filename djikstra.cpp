#include <iostream>
#include <list>
#include <tuple>
#include <queue>
#include <time.h>
#include <iomanip>
#include "djikstra.h"
#define INFINITO 10000000

using namespace std;

Djikstra::Djikstra(int V)
{
    this->V = V;
    adj = new list<tuple<int, int, int> >[V];
}

void Djikstra::addAresta(int v1, int v2, int custo, int direcao)
{
    adj[v1].push_back(make_tuple(v2, custo, direcao));
}

tuple <vector<int>, int, double> Djikstra::dijkstra(int orig, int dest)
{
    int visitou = 0;
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false);

    vector<int> direcoes;
    int dist[V];
    int visitados[V];

    // fila de prioridades de pair (distancia, vértice)
    priority_queue < tuple<int, int, int>,
            vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

    // inicia o vetor de distâncias e visitados
    for(int i = 0; i < V; i++)
    {
        dist[i] = INFINITO;
        visitados[i] = false;
    }

    // a distância de orig para orig é 0
    dist[orig] = 0;
    // insere na fila
    pq.push(make_tuple(dist[orig], orig, orig));

    // loop do algoritmo
    while(!pq.empty())
    {
        tuple<int, int, int> p = pq.top();
        int u = get<1>(p);

        pq.pop(); // remove da fila

        // verifica se o vértice não foi expandido

        if(visitados[u] == false)
        {
            // marca como visitado
            visitados[u] = true;

            list<tuple<int, int, int> >::iterator it;

            // percorre os vértices "v" adjacentes de "u"
            for(it = adj[u].begin(); it != adj[u].end(); it++)
            {
                // obtém o vértice adjacente e o custo da aresta
                int v = get<0>(*it);
                int custo_aresta = get<1>(*it);
                int direcao = get<2>(*it);
                // relaxamento (u, v)
                if(dist[v] > (dist[u] + custo_aresta))
                {
                    direcoes.push_back(direcao);

                    dist[v] = dist[u] + custo_aresta;
                    pq.push(make_tuple(dist[v], v, v));
                }

            }

        }
    }
    // retorna a distância mínima até o destino
    time(&end);
    double time_taken = double(end - start);
    return make_tuple(direcoes, dist[dest], time_taken);
}
