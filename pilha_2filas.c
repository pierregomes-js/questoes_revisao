#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int item;
    struct no *next;

} No;

typedef struct {
    No *inicio, *fim;

} Fila;


typedef struct {
    Fila f1;
    Fila f2;

} Pilha;




void inicializarFila(Fila *f) {
    f->inicio = NULL; 
    f->fim = NULL; 
}


int filaVazia(Fila *f) { 
    return f->inicio == NULL;

}



void addFila(Fila *f, int item) {
    No *novo = (No*) malloc(sizeof(No));
    novo->item = item;
    novo->next = NULL;


    if (filaVazia(f)) {
        f->inicio = novo; 
        f->fim = novo;
    
    } else {
        f->fim->next = novo;  //add no fim
        f->fim = novo; 
    }


}


int removeFila(Fila *f) {

    No *temp = f->inicio; //1> selecionar o inicio
    int item = temp->item; //2>selecionar o item (que será alterado apos o andamento do inicio ao proximo)
    f->inicio = temp->next; //inicio se torna o proximo


    if (f->inicio == NULL) f->fim = NULL; //caso a fila só tinha 1 elemento, inicio se torna null. logo, fim também terá que apontar para null

    free(temp); //libera o antigo inicio

    return item; //retorna o item novo como o início

}




void inicializarPilha(Pilha *p) {
    inicializarFila(&p->f1);
    inicializarFila(&p->f2);

}

int pilhaVazia(Pilha *p) { 
    return filaVazia(&p->f1);

}

void push(Pilha *p, int item) {
    addFila(&p->f2, item); //salva o fim

    while (!filaVazia(&p->f1)) {

        addFila(&p->f2, removeFila(&p->f1)); //o elemento que seria o inicio na fila 1 torna-se o fim na fila 2

    }
    
    Fila aux = p->f1;
    p->f1 = p->f2;
    p->f2 = aux; //troca de valores entre as filas com ajuda de fila aux

}


int pop(Pilha *p) {
    return removeFila(&p->f1); 

}




int main () {

    Pilha f;

    inicializarPilha(&f);
    push(&f, 15);
    push(&f, 54);
    push(&f, 2);
    printf("Desempilha %d \n", pop(&f));
    printf("Desempilha %d \n", pop(&f));
    printf("Desenpilha %d \n", pop(&f));

    return 0;

}