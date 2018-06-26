#include <stdio.h>
#include <float.h>
#include <stdlib.h>

typedef struct no{
	struct No* prox;
	double peso;
	int vertice;
	int indice; //indice na heap
} No;

typedef struct graph{
	No** LA;
	int tamanho;
} GraphLA;


typedef struct minHeap{
	No** valores;
	int comprimento;
	int tamanho;
	
} MinHeap;

//funções do grafo

No* AlocaNo(int i, double peso){
	No* no = (No*)malloc(sizeof(no));
	no->vertice = i;
	no->peso = chave;
	no->prox = NULL;
	return no;
}

GraphLA* AlocaGrafo(int t){
	GraphLA* g = (GraphLA*)malloc(sizeof(GraphLA));
	g->LA = (No**)malloc(sizeof(No*) * t);
	g->tamanho = t;

	for(int i, i < t, i++){
		g->LA[i] = NULL;
	}

	return g;
}

void InserirNo(GraphLA* g, No* n, int indice){
	if(g != NULL && n != NULL){
		if(g->LA[indice] == NULL){
			g->LA[indice] = n;	
		}else{
			n->prox = g->LA[indice]
			g->LA[indice] = n;
		}
		
	}
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
		int indicepai = h->valores[pai]->indice;
		int indiceI = h->valores[i]->indice;

		//faz a troca
		h->valores[pai] = h->valores[i];
		h->valores[i] = aux;
		//devolve os indices originais
		h->valores[pai]->indice = indicepai;
		h->valores[i]->indice = indiceI;
		
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
		u->indice = h->tamanho;
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
		h->valores[0] = h->valores[h->tamanho];
		h->valores[0]->indice = 0;
		h->tamanho -= 1;
		Descer(h, 0);
		return min;
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
	
	while(getchar() != ':'){}
	getchar();

	while(scanf("%d %d %lf", &v1, &v2, &peso) != EOF){
		//printf("%d %d %.3lf\n", v1, v2, peso);

	}
	
}