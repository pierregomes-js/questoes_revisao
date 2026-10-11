#include <iostream>
#include <stack>

using namespace std;

int main() {
    std::stack<int> pilha;

    // Inserção de elementos (push)
    pilha.push(20);
    pilha.push(40);
    pilha.push(60);
    // Estado atual (topo a base) : 60, 40, 20;

    // Verificação de vazio (empty)
    if (!pilha.empty()) {
        // Acesso ao elemento do topo (top)
        cout << "Elemento no topo: " << pilha.top() << "\n"; // Imprime 60
    }

    // Remoção de elemento (pop)
    pilha.pop(); // Remove o 60
    
    cout << "Novo topo apos o pop: " << pilha.top() << "\n"; // Imprime 40

    return 0;
}