#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct elemento{
	int cod;
	char nome[23];
	elemento *prox;
};


struct elemento *inicio=NULL,*fim=NULL;

//anexar a lista B ao final da Lista A
void anexa(struct elemento *A, struct elemento *B){
	

	while (A->prox != NULL) {
		A = A->prox;
	}

	A->prox = B;


	
}

struct elemento *no(int v,char n[23],struct elemento *p) {
	   
	struct elemento *novo= (struct elemento *)malloc(sizeof(struct elemento));	

	novo->cod=v;
	strcpy(novo->nome,n);
	novo->prox=p;
	return novo;
	
}


// adicionar ao final da lista
//complete o codigo
void addFinal(int c,char n[23]) {
    struct elemento *novo= no(c,n,NULL);

	if (inicio == NULL) {
		inicio = novo;
		fim = novo;
	} else {
		fim->prox = novo;
		fim = novo;
	}

	
	
}

// adicionar no inicio da lista
//complete o codigo
void addInicio(int c,char n[23]){
   struct elemento *novo= no(c,n,NULL);

   if (inicio == NULL) {
		inicio = novo;
		fim = novo;
   } else {

		novo->prox = inicio;
		inicio = novo;
   }

   

}


//adicionar ordenado (use codigo como a chave de ordenacao)
//complete o codigo

//corrigir
void addOrdenado(int c, char n[23]){
	struct elemento *novo= no(c,n,NULL);
	elemento *atual = inicio;


	if (inicio == NULL) { //ser o primeiro e ultimo
		inicio = novo;
		fim = novo;
	} else {
		if (novo->cod < atual->cod) { //menor que o do inicio
			novo->prox = atual;
			inicio = novo;
			return;
			
		} else {
			

			while (atual != NULL) {
				

				elemento *proximo = atual->prox;
				if (proximo == NULL) {//adicionar no fim

					atual->prox = novo;
					fim = novo;
					break;
				}


				if (proximo->cod > novo->cod) { // no meio
					atual->prox = novo;
					novo->prox = proximo;
					break;
				}


				atual = atual->prox;

			}
		}

	}


	
}

//mostrar todos os elementos da lista (do inicio ao final)
//complete o codigo
void mostra (){

	elemento *p = inicio;

	while (p != NULL) {

		cout << p->cod << " - ";
		cout << p->nome << "\n";
		p = p->prox;
	}
	
}

// remover um elemento da lista (procure o elemento pelo codigo)
// "cod" recebe o valor procurado
//complete o codigo
int remove(int cod){
	elemento *atual = inicio;

	if (atual->cod == cod) {
		inicio = atual->prox;
		free(atual);
		return 1;
	}

	while (atual != NULL) {

		elemento *sucessor = atual->prox;

		if (sucessor == NULL) {
			return 0;
		}

		if (sucessor->cod == cod) {
			atual->prox = sucessor->prox;
			free(sucessor);
			return 1;
		}


		if (sucessor->prox == NULL) {
			return 0;
		}

		atual = atual->prox;

	}
	return 0;
			  	
} 

// procura a ocorrencia de um elemento na lista
// "cod" � o valor procurado
//complete o codigo		
int procura(int cod){
	elemento *atual = inicio;

	while (atual != NULL) {
		if (atual->cod == cod) {
			return 1;
		}

		atual = atual->prox;


	}
	return 0;
	
}

//destruir a lista completa
//complete o codigo

void destroi(struct elemento *a){	    
	while (a != NULL) {
		elemento *x = a;
		a = a->prox;
		free(x);
	}
}

//complete o codigo
void inverterLista(){
	elemento *anterior = NULL;
	elemento *proximo = NULL;
	elemento *atual = inicio;

	while (atual != NULL) {
		proximo = atual->prox;
		atual->prox = anterior;
		anterior = atual;

		atual = proximo;
	}

	elemento *aux= fim;
	fim = inicio;
	inicio = aux;

}

int main(){
	addOrdenado(23,"Ana");
	addOrdenado(55, "Breno");
	addOrdenado(28, "Pierre");
	mostra();
	
	
	
	return 0;
}
