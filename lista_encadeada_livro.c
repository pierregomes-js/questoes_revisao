//questoes do livro de listas encadeadas
//progamas comentados > versao recursiva


#include<stdlib.h>
#include<stdio.h>
#define fmt "%d "

typedef int Item;

typedef struct no {
    Item item;
    struct no *prox;

} *Lista;


Lista no(Item x, Lista p) {
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;

    return n;
}


//exibir 
void exibir(Lista p) {
    while (p != NULL) {
        printf("%d", p->item);
        p = p->prox;
    }
}


//juntar
void anexar(Lista *A, Lista B) { 
    if (B == NULL) { 
        return;
    }

    while (*A != NULL) {
        A = (&(*A)->prox);
    
    }

    *A = B; 
}


//destruir
void destruir(Lista *L) {
    while (*L != NULL) { 
        Lista n = *L; 
        *L = n->prox; 
        free(n); 
    }
}


// int tam(Lista L) {
//     if (L == NULL ) {
//         return 0;
//     }

//     return 1 + tam(L->prox);
// }

int tam(Lista L) {
    int tamanho = 0;

    while(L != NULL) {
        tamanho++;
        L = L->prox;
    }

    return tamanho;
}


// int pert(Item x, Lista L) {
//     if (L == NULL) return 0;
//     if (x == L->item) return 1;
//     return pert(x, L->prox);
// }


int pert(Item x, Lista L) {
    while (L != NULL) {
        if (x == L->item) return 1;
        L = L->prox;
    }
    return 0;
}


// Lista clone(Lista L) {
//     if (L == NULL) return NULL;
//     return no(L->item, clone(L->prox));
// }

Lista clone(Lista L) {

    Lista clone_lista;

    while (L != NULL) {
        clone_lista = no(L->item, L->prox);
        L = L->prox;
    }

    return clone_lista;
}


// void exibe_inv(Lista L) { 
//     if (L == NULL) 
//     exibe_inv(L->prox); 
//     printf(fmt, L->item); 
// }

void exibe_inv(Lista L) { 
    while (L != NULL) {
        exibe_inv(L->prox);
        printf(fmt, L->item);
        L = L->prox;
    }
}


// Lista criar_inv(Lista L) { 
//     if (L == NULL) return;
//     exibe_inv(L->prox); //empilhar
    // Lista invertida = criar_inv(L->prox); //passo recursivo
    // Lista novo = no(L->item, NULL); //ultimo elemento
    // anexar(&invertida, novo);
// }

//9.4)
Lista criar_inv(Lista L) { 
    if (L == NULL ) return NULL; 

    Lista invertida = criar_inv(L->prox); 
    Lista novo = no(L->item, NULL); 
    anexar(&invertida, novo);

    return invertida;

}


// int ocorrencias(Item x, Lista L) {
//     if (L == NULL) return 0;
//     if (L->item == x) return 1 + ocorrencias(x, L->prox);
//     return 0 + ocorrencias(x, L->prox);
// }

int ocorrencias(Item x, Lista L) {
    int i = 0;

    while (L != NULL) {
        if (L->item == x) {
            i++;
        }
        L = L->prox;
    }

    return i;
}


// int ultimo(Lista L) {
//     if (L->prox == NULL) return L->item;
//     ultimo(L->prox);
// }

int ultimo(Lista L) {
    while (L != NULL) {
        if (L->prox == NULL) {
            return L->item;
        }
        L = L->prox;
    }

}


// int soma(Lista L) {
//     if (L == NULL) return 0;
//     return L->item + soma(L->prox);
// }

int soma(Lista L) {
    int soma = 0;
    while (L != NULL) {
        soma += L->item;
        L = L->prox;
    }
    return soma;

}

//9.6
void substitui_recursiva(Item x, Item y, Lista L) {
    if (L == NULL) return;
    if (L->item == x) L->item = y;
    substitui_recursiva(x, y, L->prox);
}


void substitui(Item x, Item y, Lista L) {
    while (L != NULL) {
        if (L->item == x) L->item = y;
        L = L->prox;

    }
}

//questao 5)
void inverte_em_lista (Lista *L) {
    Lista proximo;
    Lista atual = *L;
    Lista anterior = NULL;

    while (atual != NULL) {
        proximo = atual->prox; 
        atual->prox = anterior; 
        anterior = atual; 
        atual = proximo; 
    }

    *L = anterior;

}


// int igual(Lista A, Lista B) {
//     if (A == NULL && B == NULL) return 1; 
//     if (A == NULL || B == NULL) return 0; 
//     if (A->item != B->item) return 0; 

//     return igual(A->prox, B->prox); 
// }


int igual(Lista A, Lista B) {
    while (A != NULL) {
        if (A->item != B->item) return 0;
        A = A->prox;
    }
    if (A == NULL && B == NULL) {
        return 1;
    } else {
        return 0;
    }

}


// int enesimo(int n, Lista L) {
//     if (L == NULL) exit(1); //erro fatal
//     if (n == 1) return L->item;
//     return enesimo(n-1, L->prox);

// }


int enesimo(int n, Lista L) {

    while (L != NULL) {
        if (n == 1) return L->item;
        L = L->prox;
        n--;
    }

    exit(1);

}


//9.9)
typedef int Itemp;

typedef struct pilha {
    Itemp itemp;
    struct pilha *proxp;
} *Pilha;

Pilha nop (Itemp x, Pilha P) {
    Pilha y = (Pilha)malloc(sizeof(struct pilha));
    y->itemp = x;
    y->proxp = P;

    return y;
}


void empilha(Itemp x, Pilha *P) {
    *P = nop(x, *P);
}

Itemp desempilha(Pilha *P) {
    if (*P == NULL) {
        printf("Erro fatal > pilha vazia. \n");
        exit(1);
    }//pilha vazia;

    Pilha topo = *P; 
    Itemp x = topo->itemp; 
    *P = topo->proxp;
    free(topo);
    return x; 

}


//9.10))
typedef int Itemf;

typedef struct fila {
    Itemf itemf;
    struct fila *proxf;

} *Fila;

Fila nof(Itemf f, Fila A) {
    Fila y = (Fila)malloc(sizeof(struct fila));
    y->itemf = f;
    y->proxf = A;

    return y;
}


void enfileira(Itemf x, Fila *F) {
    if (*F == NULL) {
        Fila y = nof(x, NULL); 
        y->proxf = y;  
        *F = y; 

    } else {
        Fila y = nof(x, (*F)->proxf); 
        (*F)->proxf = y; 
        *F = y;
    }
}

void exibirpilha(Pilha P) {
    while (P != NULL) {
        printf("%d", P->itemp);
        P = P->proxp;
    }
}


Item desenfileira(Fila *F) {
    if (*F == NULL) { 
        exit(1);
    }

    Fila y = (*F)->proxf; 
    Itemf x = y->itemf;

    if (y == *F) {*F = NULL;
    } else {
        (*F)->proxf = y->proxf;
    }
    
    free(y);
    return x; 

}



int main() {
    Lista I = no(3, no(1, no(5, NULL)));
    exibir(I);

    printf("\n");

    Fila F = NULL;
    enfileira(2, &F);
    enfileira(4, &F);
    enfileira(8, &F);

    printf("\n");

    Pilha P = nop(9, nop(9, nop(0, NULL)));
    exibirpilha(P);

    printf("\n");
    Lista X = criar_inv(I);
    exibir(X);


    return 0;
}