#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct aluno{
	int mat;
	string nome;	
}Aluno; 

Aluno lista[30];
int qtd = 0;

void incluirDesordenado(Aluno e){

	lista[qtd] = e;
	qtd++;

}

//retorna a posicao do elemento procurado
int procura(int mat){	
	int i;

	for (i = 0; i < qtd; i++) {
		if (lista[i].mat == mat) {
			return i;
		} 
	}
	
	return -1; //pos invalida

}

//recebe a posicao e imprime o elemento na tela
void mostrar(int pos) {
	cout << "matricula: "<< lista[pos].mat << " nome: " << lista[pos].nome << endl;
}

//mostra TODOS os elementos da lista
void mostra(){	
	int i;

	for (i = 0; i < qtd; i++) {
		cout << "matricula: "<< lista[i].mat << " nome: " << lista[i].nome << endl;
	}
}

//estrat�gia 1: colocar o ultimo elemento da lista na posi��o do elemento removido
void remover00(int pos){
	aluno ultimo = lista[qtd-1];
	lista[pos] = ultimo;
	qtd--;


}

//estrat�gia 2: mover TODOS os elementos que est�o AP�S  o elemento que deve ser removido UMA POSI��O A FRENTE.
void remover01(int pos){
	int i;

	for (i = pos; i < qtd-1; i++) {
		aluno sucessor = lista[i+1];
		lista[i] = sucessor;
	}
	qtd--;
}

int main(){
	Aluno novoaluno;
	novoaluno.mat = 35;
	novoaluno.nome = "João";

	Aluno novoaluno2;
	novoaluno2.mat = 41;
	novoaluno2.nome = "Julia";

	incluirDesordenado(novoaluno);
	incluirDesordenado(novoaluno2);

	mostrar(0);
	cout << " " << endl; 
	
	mostra();

	return 0;
	
}