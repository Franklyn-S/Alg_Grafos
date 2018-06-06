#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Aresta{
	int v1, v2;
	double peso;

public:

	Aresta(int v1, int v2, double peso)
	{
		this->v1 = v1;
		this->v2 = v2;
		this->peso = peso;
	}
	int obterVertice1()
	{
		return v1;
	}

	int obterVertice2()
	{
		return v2;
	}

	int obterPeso()
	{
		return peso;
	}

	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

class Grafo
{
	int V;//numero de vértices
	vector<Aresta> arestas; //Vetor de arestas
	vector<int> pai;//int *pai;
	vector<int> distancia;//int *distancia;

public:
	Grafo(int V)
	{
		this->V = V;
		pai.resize(V); //pai = (int *)malloc(V * sizeof(int));
		pai.assign(V,0);
		distancia.resize(V); //distancia = (int *)malloc(V * sizeof(int));
		distancia.assign(V,0);
	}

	void adicionarAresta(int v1, int v2, double peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	//Implementar as funções do Dijkstra aqui
	void dijkstra()
	{
		for(int i = 0; i < V; i++)
		{
			pai.at(i) = -1;
			distancia.at(i)	 = std::numeric_limits<double>::max();	
			cout << distancia.at(i) << endl;
		}
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