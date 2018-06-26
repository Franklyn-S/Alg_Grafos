#include <stdio.h>
#include <float.h>
#include <stdlib.h>

typedef struct no{
	struct no* prox;
	double peso;
	int vertice;
	//int indice; //indice na heap
} No;

typedef struct graph{
	No* LA;
	int tamanho;
} GraphLA;


typedef struct minHeap{
	No** valores;
	int comprimento;
	int tamanho;
	
} MinHeap;

//funções do grafo

No* AlocaNo(int i, double peso){
	No* no = (No*)malloc(sizeof(No));
	no->vertice = i;
	no->peso = peso;
	no->prox = NULL;
	//no->indice = -1;
	return no;
}

GraphLA* AlocaGrafo(int t){
	GraphLA* g = (GraphLA*)malloc(sizeof(GraphLA));
	g->LA = (No*)malloc(sizeof(No) * t);
	g->tamanho = t;

	for(int i = 0; i < t; i++){
		g->LA[i].vertice = i;
		g->LA[i].peso = DBL_MAX;
		g->LA[i].prox = NULL;
	}

	return g;
}

void InserirNo(GraphLA* g, No* n, int i){
        n->prox = g->LA[i].prox;
        g->LA[i].prox = n;
}


//funções da heap

int pai(int i){
	return i >> 1;
}

int esquerda(int i){
	return i << 1;
}

int direita(int i){
	return (i << 1) + 1;
}

void Trocar(MinHeap* h, int i, int pai){
	if(h != NULL){
		No* aux = (No*)malloc(sizeof(No));

		aux = h->valores[pai];

		//guarda os indices originais na heap
		//int indicepai = h->valores[pai]->indice;
		//int indiceI = h->valores[i]->indice;

		//faz a troca
		h->valores[pai] = h->valores[i];
		h->valores[i] = aux;
		//devolve os indices originais
		//h->valores[pai]->indice = indicepai;
		//h->valores[i]->indice = indiceI;
		
		free(aux);
	}
}


void DiminuirChave(MinHeap* h, int i, double chave){
	if(h != NULL && chave < h->valores[i]->peso){
		h->valores[i]->peso = chave;

		while(i > 1 && h->valores[pai(i)]->peso > h->valores[i]->peso){
			Trocar(h, i, pai(i));
			i = pai(i);
		}
	}
}


void InserirChave(MinHeap* h, No* u, double chave){
	if(h != NULL && u != NULL){
		h->tamanho += 1;
		//u->indice = h->tamanho;
		h->valores[h->tamanho] = u;
		h->valores[h->tamanho]->peso = DBL_MAX;
		DiminuirChave(h, h->tamanho, chave);
	}
	
}

void Descer(MinHeap* h, int i){
	if(h != NULL){
		int e = esquerda(i);
		int d = direita(i);
		int menor = 0;
		if(e <= h->tamanho && h->valores[e] < h->valores[i]){
			menor = e;
		}else{
			menor = i;
		}

		if(d <= h->tamanho && h->valores[d] < h->valores[menor]){
			menor = d;
		}
		while(menor != i){
			Trocar(h, i, menor);
			Descer(h, menor);
		}
	}
	
}

No* ExtrairMinHeap(MinHeap* h){
	if(h != NULL && h->tamanho >=0){
		No* min = h->valores[0];
		//min->indice = -1;
		h->valores[0] = h->valores[h->tamanho];
		//h->valores[0]->indice = 0;
		h->tamanho -= 1;
		Descer(h, 0);
		return min;
	}
}

int HeapVazia(MinHeap* h){
	if (h->tamanho == -1){
		return 1;
	}
	return 0;
}

int ChecaExiste(MinHeap* h, int valor){
	if(h != NULL){
		for (int i = 0; i <= h->tamanho; i++){
			if(h->valores[i]->vertice == valor)
				return i+1;
		}
		return 0;
	}
}

MinHeap* BuildMinHeap(int n){
	MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
	h->valores = (No**)malloc(sizeof(No*) * n);
	h->comprimento = n;
	h->tamanho = -1;
}

int main(){
	int n;
	int v1, v2;
	double peso;

	while(!scanf("n=%d", &n)){
		getchar();
	}

	
	GraphLA* g = AlocaGrafo(n);
	int* atingido = (int*)malloc(sizeof(int) * n);
	double* distancia = (double*)malloc(sizeof(double) * n);
	

	while(getchar() != ':'){}
	getchar();
	
	while(scanf("%d %d %lf", &v1, &v2, &peso) != EOF){
		//printf("%d %d %.3lf\n", v1, v2, peso);
		InserirNo(g , AlocaNo((v2-1), peso), v1-1);
	}

	
	//ALGORITMO DE DIJKSTRA
	for(int v = 0; v < n; v++){
		atingido[v] = 0;
		distancia[v] = DBL_MAX;
	}

	MinHeap* heap = BuildMinHeap(n);	
	atingido[0] = 1;
	distancia[0] = 0.000;
	No* v = (No*)malloc(sizeof(No));
	v = g->LA;

	while(v != NULL){
		atingido[v->vertice] = 1;
		InserirChave(heap, v, v->peso);
		v = v->prox;
	}
	
	No* u = (No*)malloc(sizeof(No));
	while(!HeapVazia(heap)){
		u = ExtrairMinHeap(heap);s
		distancia[u->vertice] = u->peso;
		v = (g->LA)+(u->vertice);
		while(v != NULL){
			if(!atingido[v->vertice]){
				atingido[v->vertice] = 1;
				InserirChave(heap, v, v->peso + distancia[u->vertice]);
			}else{
				int aux = ChecaExiste(heap, v->vertice);
					//v->indice > 1										//v->indice
				if( aux && distancia[u->vertice] + v->peso < heap->valores[aux]->peso){
					DiminuirChave(heap, aux, distancia[u->vertice] + v->peso);
				}	
			}

			v = u->prox;
		}
	}
	
	//printa o resultado
	for(int i = 0; i < n; i++){
		if(distancia[i] == DBL_MAX){
			printf("%d INFINITO", i+1);
		}else{
			printf("%d %.3lf\n", i+1, distancia[i]);
		}
	}
}