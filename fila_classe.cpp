#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
class No{
    public:
        char nome;
        No *prox;

        No(char n){
            nome = n;
            prox = NULL;
        }
};


class Fila {
    public:
        No *inicio;
        No *fim;
        
        Fila(){
            inicio = NULL;
            fim = NULL;
        }

        void inserir(char n){
            No *novo = new No(n);

            if (inicio == NULL) {
                inicio = novo;
                fim = novo;

            } else {
                fim->prox = novo;
                fim = novo;
            }
        }

        char apagar(){
            No *temp = inicio;
            char nome = temp->nome;
            inicio = temp->prox;
            if (inicio == NULL) fim == NULL;
            delete temp;
            
            return nome;
        }


        bool isEmpty(){
            return (inicio == NULL);
        }


    void apagaTodos(){
        while (!isEmpty()){
            apagar();
        }
    }
};


int main(){
    Fila *f1=new Fila();
    f1->inserir('A');
    cout << "enfila " << f1->fim->nome << endl;
    f1->inserir('B');
    cout << "enfila " << f1->fim->nome << endl;
    f1->inserir('C');
    cout << "enfila " << f1->fim->nome << endl;
    
    // desenfile e mostre os itens desenfileirados
    cout << "desenfila " << f1->apagar() << endl;
    cout << "desenfila " << f1->apagar() << endl;
    cout << "desenfila " << f1->apagar() << endl;
}