#include <stdio.h>
#include <iostream>
#include <vector>

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

public:
	Grafo(int V)
	{
		this.V = V;
	}

	void adicionarAresta(int v1, int v2, double peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	//Implementar as funções do Dijkstra aqui
}



int main(int argc, char *argv[]){
	int n; //quantidade de vertices

	int v1, v2;
	double p;

	while(!scanf("n=%d", &n)){ getchar();}
	n = int(n);

	while(getchar() != ':'){}
	getchar();
}