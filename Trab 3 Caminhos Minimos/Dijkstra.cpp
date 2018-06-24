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
	int vertice;
	double chave;
	bool atingido;
public:

	No(int v)
	{
		vertice = v;
		chave = std::numeric_limits<double>::max();//distancia
		atingido = false;
	}

	void atingir()
	{
		this->atingido = true;
	}

	void setChave(double chave)
	{
		this->chave = chave;
	}

	int obterVertice()
	{
		return vertice;
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

class Aresta
{
	No no1, no2;
	double peso;
public:

	Aresta(No no1, No no2, double peso)
	{
		this->no1 = no1;
		this->no2 = no2;
		this->peso = peso;
	}

	double obterPeso()
	{
		return peso;
	}
};


class heap
{
	std::vector<No> H;
	double ultimo;
public:
	heap()
	{	
		H.push_back(0);
		ultimo = 0;
	}

	void pai(int i){
		return (i >> 1);
	}

	void esquerda(int i)
	{
		return (i << 1);
	}

	void direita(int i)
	{
		return (i << 1) + 1;
	}

	void descer(int i)
	{
		int e = i.esquerda();
		int d = i.direita();
		int menor;
		if(e <= this->ultimo and this->H[e].obterChave() < this->H[i].obterChave()){
			menor = e;
		}else{
			menor = i;
		}
		if(d <= this->ultimo and this->H[d].obterChave() < this->H[menor].obterChave()){
			menor = d;
		}

		if (menor != i){
			No aux = this->H[i];
			this->H[i] = this->H[menor];
			this->H[menor] = aux;
			this->descer(menor);
		}
	}

	No removerMinimo()
	{
		if (this->ultimo == 0){
			return NULL;
		}
		No minimo = this->H[1];
		this->H[1] = this->H[this->ultimo];
		this->ultimo -= 1;
		if(this->ultimo >= 1){
			this->descer(1);
		}
		this->H.pop_back(this->ultimo + 1);
		return minimo;
	}

	void incluir(No v, double k){
		this->ultimo ++;
		this->H.push_back(v);
		this->aumentarPrioridade(v, k);
	}

	void aumentarPrioridade(No u, double k){
		int i = 0;
		while( i < this->H.size() and this->H[i] != u) 
		{
			i++;
		}
		if !(k > this->H[i].obterChave()){
			this->H[i].setChave(k);

			while(i >= 2 and H[pai(i)].obterChave() > H[i].obterChave()){
				No aux = H[i];
				H[i] = H[pai(i)];
				H[pai(i)] = aux;
				i = pai(i);
			}
		}

	}
	double pegaPeso(int vertice){
		for (int i = 0; i < H.size(); i++)
		{
			if(H[i].vertice == vertice){
				return H[i].obterChave();
			}
		}
		return 0;
	}
};


class Grafo
{
	int V;//numero de vértices
	vector<Aresta> arestas; //vetor de arestas
	list<No> *adj;
	vector<bool> pertenceHeap;//vetor auxiliar para verificar se pertence à Heap


public:
	Grafo(int V)
	{
		this->V = V;
		adj = new list<No>[V];
		for (int i = 0; i < V; i++)
		{
			pertenceHeap.push_back(false);
		}
	}	

	double obterPeso(int v1, int v2)
	{
		for (int i = 0; i < arestas.size(); i++)
		{
			if(arestas[i].no1.vertice == v1 and arestas[i].no2.vertice == n2){
				return arestas[i].obterPeso();
			}
		}
	}

	void adicionarAresta(int v1, int v2, double peso)
	{	
		No n1 = No(v1);
		No n2 = No(v2)
		Aresta aresta(n1, n2, peso);
		arestas.push_back(aresta);
		adj[v1].push_back(n2);
	}

	//Implementar as funções do Dijkstra aqui
	void dijkstra(vector<No> vertices)
	{
		vertices[0].atingir();
		vertices[0].setChave(0.000);
		heap hp = heap();
		//percorrer vizinhos
		No no; //auxiliar
		for(int i = 0; i < adj[0].size(); i++){
			
			adj[0][i].atingir();
			adj[0][i].
			hp.incluir(adj[0][i], obterPeso(0, adj[0][i].obterVertice()));
			pertenceHeap[adj[0][i].obterVertice()] = true;
		}
		while(hp != [0]){
			no = hp.removerMinimo();
			vertices[no.vertice] = no.obterChave(); //distancia[u] = u.chave
			for (int i = 0; i < this->adj[no.obterVertice()].size(); i++) //Para cada v E N(u)
			{
				if(!adj[no.obterVertice()][i].atingido){ //Se não atingido
					adj[no.obterVertice()][i].atingir();
					hp.incluir(adj[no.obterVertice()][i], obterPeso(no.obterVertice(), adj[no.obterVertice()][i].obterVertice()));
					pertenceHeap[adj[no.obterVertice()][i].obterVertice()] = true;
				}else{

					double pesoOutroCaminho = vertices[no.obterVertice()] + obterPeso(no.obterVertice(), adj[no.obterVertice()][i].obterVertice());
					if (pertenceHeap[adj[no.obterVertice()][i].obterVertice()] and 
						pesoOutroCaminho < hp.pegaPeso(adj[no.obterVertice()][i].obterVertice())){
							hp.aumentarPrioridade(adj[no.obterVertice()][i], pesoOutroCaminho);
					}
				}
			}
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

	g.dijkstra(vertices);


	for (int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].obterChave() == std::numeric_limits<double>::max()){
			cout << i << " INFINITO" << endl;
		}else{
		std::cout.precision(3);
		cout << i << " ";
		std::cout << std::fixed << vertices[i].obterChave() << endl;
		}
	}
}