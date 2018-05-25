#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

class Grafo{
	int V;//número de vertices
	list<int> *adj; //ponteiro para um array contendo as listas de adjacencia
};


int main(void){
	//Declarações
	string dl, aux, format, data;
	int n;

	int v1, v2;
	float p;

	//Entrada de dados
	//cin >> dl;
	//cin >> format;
	//cin >> aux;
	
	//n = std::strtok(aux, "=");

	//isolando a quantidade de vertices n
	while(!scanf("n=%d", &n)){getchar();}
	n = int(n);

	//tratando entrada
	while(getchar() != ':'){}
	getchar();

	//receber o grafo
	int contador = 0;
	while(contador < n){
		//recebe a aresta (v1, v2) com peso p
		cin >> v1 >> v2 >> p;
		//armazenar no grafo
		
		contador++;
	}
	
	

	
	
}