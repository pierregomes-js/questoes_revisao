#include <iostream>
#include <queue>
using namespace std;

int main() {
    std::queue<int> fila;

    // Inserção de elementos (push)
    fila.push(77);
    fila.push(23);
    fila.push(89);
    // Estado atual (frente para tras): 77, 23, 89;

    // Verificação de vazio (empty)
    if (!fila.empty()) {
        // Acesso ao primeiro elemento (front)
        cout << "Primeiro elemento (inicio): " << fila.front() << "\n"; // Imprime 77
    }

    // Remoção de elemento (pop)
    fila.pop(); // Remove o 10
    
    cout << "Novo inicio apos o pop: " << fila.front() << "\n"; // Imprime 23

    return 0;
}