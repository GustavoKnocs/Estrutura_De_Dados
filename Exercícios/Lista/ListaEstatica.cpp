#include "ListaEstatica.hpp"
#include <iostream>

using namespace std;

int main(){
    
    ListaEstatica ListaA, ListaB;
    int n, elemento;

    ListaA = cria();
    ListaB = cria();

    cout << "Insira o numero de elementos da lista 1: ";
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cout << "elemento " << i + 1 << ": ";
        cin >> elemento;
        insere(ListaA, elemento, i);
    }
    mostra(ListaA);
    cout << endl;

    cout << "Insira o numero de elementos da lista 2: ";
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cout << "elemento " << i + 1 << ": ";
        cin >> elemento;
        insere(ListaB, elemento, i);
    }
    mostra(ListaB);
    cout << endl;

    for (int i = 0; i <= numeroElementos (ListaA); i++)
        if (existeElemento (ListaB, umElemento (ListaA, i)))
        cout << umElemento(ListaA, i) << " eh elemento comum nas listas" << endl;
    
    return 0;
}