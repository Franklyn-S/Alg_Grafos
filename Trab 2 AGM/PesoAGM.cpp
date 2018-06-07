#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
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

		double obterPeso()
		{
			return peso;
		}

		//Sobrescrita do operador "<"
		bool operator < (const Aresta& aresta2) const
		{
			return (peso < aresta2.peso);
		}
};

class Grafo
{
	int V; //número de vértices
	vector<Aresta> arestas;// vetor de arestas

public:
	Grafo(int V)
	{
		this->V = V;
	}

	void adicionarAresta(int v1, int v2, double peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	//função que busca o subconjunto de um elemento "i"
	int buscar(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}
	void kruskal()
	{
		vector<Aresta> arvore;

		// ordena as arestas pelo menor peso
		sort(arestas.begin(), arestas.end());

		// aloca memória para criar "V" subconjuntos
		int * subset = new int[V];

		// inicializa todos os subconjuntos como conjuntos de um único elemento
		memset(subset, -1, sizeof(int) * V);

		int size_arestas = arestas.size();

		for(int i = 0; i < size_arestas; i++)
		{
			int v1 = buscar(subset, arestas[i].obterVertice1());
			int v2 = buscar(subset, arestas[i].obterVertice2());

			if(v1 != v2)
			{
				// se forem diferentes é porque NÃO forma ciclo, insere no vetor
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2); // faz a união
			}
		}
		int size_arvore = arvore.size();
		double soma = 0.0;//iniciando resultado

		for(int i = 0; i < size_arvore; i++)
		{	
			//Esses comentarios mostram as arestas da AGM e seus respectivos pesos
			//int v1 = arvore[i].obterVertice1();
			//int v2 = arvore[i].obterVertice2();
			//cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
			soma += arvore[i].obterPeso();
		}
		std::cout.precision(3);
		std::cout << std::fixed << soma << endl; //soma dos pesos da AGM
	}
};




int main(int argc, char *argv[]){

	int n; //quantidade de vertices

	int v1, v2;
	float p;

	//isolando a quantidade de vertices n
	while(!scanf("n=%d", &n)){getchar();}
	n = int(n);

	//tratando entrada
	while(getchar() != ':'){}
	getchar();

	//receber o grafo g
	Grafo g(n);

	//recebe a aresta (v1, v2) com peso p
	while(scanf("%d %d %f", &v1, &v2, &p) != EOF){
		//armazena no grafo
		g.adicionarAresta(v1-1, v2-1, p);
	}

	g.kruskal();
return 0;
}