#include <stdio.h>
#include <stdlib.h>

//fila com 2 pilhas

//estruturas> 

typedef struct no {
    int item;
    struct no *next;

} No;


typedef struct {
    No *topo;

} Pilha;


typedef struct {
    Pilha entrada, saida;

} Fila;


//funções>

void inicializar(Pilha *p) {
     p->topo = NULL; 

}


int pilhaVazia(Pilha *p) {
    return p->topo == NULL; 
    
}

void empilha(Pilha *p, int item) {
    No *novo = (No*) malloc(sizeof(No));
    novo->item = item;
    novo->next = p->topo;
    p->topo = novo;
    printf("Empilhou item %d\n", item);

}


int desempilha(Pilha *p) {
    No *temp = p->topo;
    int item = temp->item;
    printf("\nDesempilhou item %d\n", item);
    p->topo = temp->next;
    free(temp);
    return item;
}




void inicializarFila(Fila *f) {
    inicializar(&f->entrada);
    inicializar(&f->saida);

}

void entrarFila(Fila *f, int item) {
    empilha(&f->entrada, item);

}


int sairFila(Fila *f) {
    if (pilhaVazia(&f->saida)) {

        while (!pilhaVazia(&f->entrada)) {
            empilha(&f->saida, desempilha(&f->entrada));

        }

    }

    return desempilha(&f->saida);
}


int main() {

    Fila f;
    inicializarFila(&f);

    entrarFila(&f, 10);
    entrarFila(&f, 20);
    entrarFila(&f, 30);

    printf("%d\n", sairFila(&f));
    printf("%d\n", sairFila(&f));

    entrarFila(&f, 40);
    sairFila(&f);

    return 0;


}