#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Aresta
{
	int vertice1, vertice2, peso;

public:

	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1()
	{
		return vertice1;
	}

	int obterVertice2()
	{
		return vertice2;
	}

	int obterPeso()
	{
		return peso;
	}

	// sobrescrita do operador "<"
	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

class Grafo
{
	int V;//numero de vértices
	vector<Aresta> arestas; //vetor de arestas
	list<int> *adj; // lista de adjacencia

	vector<int> pai;//int *pai;
	vector<int> distancia;//int *distancia;
	vector<bool> atingido;

public:
	Grafo(int V)
	{
		this->V = V;
	}

	void adicionarAresta(int v1, int v2, double peso)
	{	
		adj[v1].push_back(v2);
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	//Implementar as funções do Dijkstra aqui
	void dijkstra()
	{
		for(int i = 0; i < V; i++)
		{
			pai.push_back(-1);
			distancia.push_back(std::numeric_limits<double>::max());	
			atingido.push_back(false);
		}
		distancia[0] = 0;


	}
};



int main(int argc, char *argv[]){
	int n; //quantidade de vertices

	int v1, v2;
	double p;

	while(!scanf("n=%d", &n)){ getchar();}
	n = int(n);

	while(getchar() != ':'){}
	getchar();

	//Recebe o grafo g
	Grafo g(n);

	//recebe a aresta (v1, v2) com peso p
	while(scanf("%d %d %lf", &v1, &v2, &p) != EOF){
		//armazena no grafo
		g.adicionarAresta(v1-1, v2-1, p);
	}

	g.dijkstra();
}