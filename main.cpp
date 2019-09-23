#include <iostream>
#include <list>
#include <tuple>
#include <queue>
#include <time.h>
#include <iomanip>
#include <bfs.h>
#include <djikstra.h>
#include <calculomovimento.h>
#define INFINITO 10000000

void print(vector<int> const &input)
{
    for (auto it = input.cbegin(); it != input.cend(); it++)
    {
        std::cout << *it << ' ';
    }
}

using namespace std;
int main()
{
    vector<int> d;
    int v;
    double t;
    //CalculoMovimento c;
    Djikstra g(6);
    BFS b(6);

    b.addAresta(0, 1, 10, 0);            //addAresta(vertice, verticeadjacente,peso, direçao)
    b.addAresta(1, 0, 6, 2);               
    b.addAresta(1, 2, 7, 0);
    b.addAresta(1, 3, 7, 2);             //Direcoes: 0 - frente, 1 - trás, 2 - esquerda e 3 - direita.
    b.addAresta(2, 1, 1, 0);
    b.addAresta(3, 1, 4, 3);
    b.addAresta(3, 4, 4, 3);
    b.addAresta(3, 5, 4, 2);
    b.addAresta(4, 3, 8, 0);
    b.addAresta(5, 3, 2, 0);

    g.addAresta(0, 1, 10, 0);
    g.addAresta(1, 0, 6, 2);
    g.addAresta(1, 2, 7, 0);
    g.addAresta(1, 3, 7, 2);
    g.addAresta(2, 1, 1, 0);
    g.addAresta(3, 1, 4, 3);
    g.addAresta(3, 4, 4, 3);
    g.addAresta(3, 5, 4, 2);
    g.addAresta(4, 3, 8, 0);
    g.addAresta(5, 3, 2, 0);

    tie(d, v, t) = g.dijkstra(0,2);
    cout << "Direcoes do percurso pelo metodo Djikstra : "<< fixed;
    print(d);
    cout << endl;


    //tie(v, t) = c.movimentoDjikstra(g, 0, 2);
    /*tie(d, v, t) = g.dijkstra(0,2);
    cout << "Direcoes do percurso pelo metodo Djikstra : "<< fixed;
    print(d);
    cout << endl;
    cout << "Distancia total gerada pelo metodo Djikstra foi: "<< v << fixed;
    cout << endl;
    cout << "Tempo tomada pelo metodo Djikstra foi: "<< t << fixed;
    cout << " segundos " << endl;*/
        return 0;
}
