#include <stdio.h>
#include <stdlib.h>


typedef struct pilha {
    int max;
    int topo;
    char *itens; //ponteiro
    
} *Pilha;

Pilha pilha (int m) {
    Pilha P = (Pilha)malloc(sizeof(struct pilha));

    P->max = m;
    P->topo = -1;
    P->itens = (char *)malloc(m*sizeof(char));
    return P;
}


void empilha (char item, Pilha P) {
    P->topo++;
    P->itens[P->topo] = item;

}

void desempilha (Pilha P) {
    P->topo--; 
}

//pilha_int
typedef struct pilha_int {
    int max;
    int topo;
    int *itens; 
    
} *Pilha_int;

Pilha_int pilha_int (int m) {
    Pilha_int P = (Pilha_int)malloc(sizeof(struct pilha_int));

    P->max = m;
    P->topo = -1;
    P->itens = (int *)malloc(m*sizeof(int));
    return P;
}


void empilha_int (int item, Pilha_int P) {
    P->topo++;
    P->itens[P->topo] = item; 

}

void desempilha_int (Pilha_int P) {
    P->topo--; 

}


int vaziap(Pilha_int P) {
    return P->topo == -1;
}


//questoes

int eh_valido (char expressao[]) { 
    Pilha P = pilha(30);
    int i = 0;

    for (i = 0; expressao[i] != '\0'; i++) {
        //criar o caractere>
        char c = expressao[i];

        if (c == '{' || c == '(' || c == '[') {
            empilha(c, P);

        } else if (c == '}' || c == ')' || c == ']') {

            if (P->topo == -1) {
                free(P->itens); 
                free(P); 
                return 0;
            }

            char topo = P->itens[P->topo];

            if ((c == '}' && topo == '{') ||
                (c == ')' && topo == '(') ||
                (c == ']' && topo == '[')) { 
                desempilha(P);
            } else {
                free(P->itens);
                free(P);
                return 0;
            }


        }

    }

    int valido = (P->topo == -1);      
    free(P->itens);
    free(P);
    return valido;

}

// 2.3)
void inverter_ordem (Pilha P) {
    Pilha B = P;
    while (!(B->topo == -1)) {
        char topo = B->itens[B->topo];
        printf("%c", topo);
        desempilha(B);
    }
}


// 2.4)
void ordenar (Pilha_int P, int i) {
    if (vaziap(P)) {
        empilha_int(i, P);
        return;
    } else {
        int topo = P->itens[P->topo];
        Pilha_int B = pilha_int(P->max);
        while (!(vaziap(P))) {
            if (topo > i) {
                empilha_int(i, B);
            }
            desempilha_int(P);
            empilha_int(topo, B);
        }

        while  (!(vaziap(B))) {
            int topob = B->itens[B->topo];
            desempilha_int(B);
            empilha_int(topob, P);
        }
    }
}




int main () {
    char expressao[30] = "{m+(x+5)+3}";

    printf("%d\n", eh_valido(expressao));

    Pilha B = pilha(7);
    char palavra[] = "Bom dia";
    int i = 0;

    for (i=0; i < 7; i++) {
        empilha(palavra[i], B);
    }

    inverter_ordem(B);

    
    Pilha_int P = pilha_int(4);
    ordenar(P, 4);
    ordenar(P, 2);
    ordenar(P, 1);
    ordenar(P, 3);




    return 0;

}