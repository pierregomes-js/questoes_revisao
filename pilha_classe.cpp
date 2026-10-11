
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


// usando uma classe No
class No{
    
    public:
        char nome;
        No *prox;

        No(char n){
            nome = n;
            prox = NULL;
        }
};


class Pilha{

    public:
        No *topo;

        Pilha(){
            topo = NULL;
        }

        
    void push(char n){
        No *novo = new No(n);
        novo->prox = topo;
        topo = novo;
    }

    
    char pop(){ //incompleta
        No *temp = topo;
        char n = temp->nome;
        topo = topo->prox;
        delete temp;

        return n;
    }

    int isEmpty(){
        return (topo == NULL);
    }

};

int main(){
    Pilha *p=new Pilha();
    p->push('A');
    cout << "emplihando " <<  p->topo->nome << endl;
    p->push('B');
    cout << "emplihando " <<  p->topo->nome << endl;
    
    p->push('C');
    cout << "emplihando " <<  p->topo->nome << endl;

    p->isEmpty();
    // Desempilhe e mostre os itens desempilhados
    cout << "desemplihando " <<  p->pop() << endl;
    cout << "desemplihando " << p->pop() << endl;
    cout << "desemplihando " << p->pop() << endl;


}