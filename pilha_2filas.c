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

    No *temp = f->inicio; 
    int item = temp->item; 
    f->inicio = temp->next;


    if (f->inicio == NULL) f->fim = NULL; 
    free(temp); 

    return item; 

}




void inicializarPilha(Pilha *p) {
    inicializarFila(&p->f1);
    inicializarFila(&p->f2);

}

int pilhaVazia(Pilha *p) { 
    return filaVazia(&p->f1);

}

void push(Pilha *p, int item) {
    addFila(&p->f2, item);

    while (!filaVazia(&p->f1)) {

        addFila(&p->f2, removeFila(&p->f1)); 

    }
    
    Fila aux = p->f1;
    p->f1 = p->f2;
    p->f2 = aux;

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