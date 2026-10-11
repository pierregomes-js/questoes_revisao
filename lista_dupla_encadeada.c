#include <stdio.h>
#include <stdlib.h>


// Define a estrutura do nó
struct No {
int dado;
    struct No* prox;
    struct No* prev;
};


// Função para criar um novo nó
struct No* novoNo(int dado) {
    struct No* no = (struct No*)malloc(sizeof(struct No));

    no->dado = dado;
    no->prox = NULL;
    no->prev = NULL;

    return no;
}


// Complete a Função para inserir um nó no início da lista
void inserirNoInicio(struct No** cabeca, int dado) {
    struct No* no = novoNo(dado);
    no->prox = *cabeca;

    if (*cabeca != NULL) {
        (*cabeca)->prev = no; //caso nao esteja vazia, agora terá nó antecessor
    }

    *cabeca = no;

}


// Complete a Função para exibir a lista do inicio até o
//final
void exibirLista(struct No* no) {

    while (no != NULL) {
        printf("%d\n", no->dado);
        no = no->prox;
    }
    printf("\n\n");

}


// Complete a Função para exibir a lista invertida(final até
//o inicio)
void exibirLista_inv(struct No* no) {

    if (no == NULL) exit(1);

    while (no->prox != NULL) { //percorrer até o ultimo, não totalmente.
        no = no->prox;
    }
    while (no != NULL) { //com o ultimo nó alcançado pelo while anterior, utilizamos seu prev para invertê-lo.
        printf("%d\n", no->dado);
        no = no->prev;
    }
    printf("\n\n");

}


// Função principal
int main() {

    struct No* cabeca = NULL;

    inserirNoInicio(&cabeca, 10);
    inserirNoInicio(&cabeca, 20);
    inserirNoInicio(&cabeca, 30);
    printf("Conteúdo da lista duplamente encadeada: ");

    exibirLista(cabeca);
    exibirLista_inv(cabeca);
    
    return 0;

}