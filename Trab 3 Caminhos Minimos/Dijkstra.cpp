#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class No
{
	int vertice1, chave;
	bool atingido;
public:

	No(int v1)
	{
		vertice1 = v1;
		chave = -1;//distancia
		atingido = false;
	}

	int obterVertice1()
	{
		return vertice1;
	}

	int obterChave()
	{
		return chave;
	}

	// sobrescrita do operador "<"
	bool operator < (const No& no2) const
	{
		return (chave < No2.chave);
	}
};



class Grafo
{
	int V;//numero de vértices
	vector<Aresta> arestas; //vetor de arestas


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
		distancia[0] = 0;
		for(int i = 0; i < V; i++)
		{
			distancia.push_back(std::numeric_limits<double>::max());	
			atingido.push_back(false);
		}
		


	}
};



int main(int argc, char *argv[]){
	int n; //quantidade de vertices

	int v1, v2;
	double p;


	while(!scanf("n=%d", &n)){ getchar();}
	n = int(n);
	std::vector<No> vertices;
	for (int i = 0; i < n; i++)
	{
		vertices.push_back(No(i));
	}

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