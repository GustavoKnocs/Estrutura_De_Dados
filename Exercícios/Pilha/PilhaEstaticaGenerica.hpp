#pragma once
#include <iostream>

using namespace std;

template<typename T, int MAX>
struct PilhaEstaticaGenerica{
    int top;
    T elementos[MAX];
};

template<typename T, int MAX>
void cria(PilhaEstaticaGenerica<T,MAX> &pilha){
    pilha.top = 0;
}

template<typename T, int MAX>
bool ehVazia(PilhaEstaticaGenerica<T,MAX> &pilha){
    return pilha.top == 0;
}

template<typename T, int MAX>
bool temEspaco(PilhaEstaticaGenerica<T,MAX> &pilha){
    return pilha.top < MAX;
}

template<typename T, int MAX>
int numElementos(PilhaEstaticaGenerica<T,MAX> &pilha){
    return pilha.top;
}

template<typename T, int MAX>
bool existeElemento(PilhaEstaticaGenerica<T,MAX> &pilha, T elemento){
   for (int i = 0; i < pilha.top; i++){
        if (elemento == i){
            return true;
        }  
   }
   return false;
}

template<typename T, int MAX>
bool existePosicao(PilhaEstaticaGenerica<T,MAX> &pilha, int posicao){
    if (posicao >= 0 and posicao < pilha.top){
        return true;
    }
    return false;
}

template<typename T, int MAX>
T elemento(PilhaEstaticaGenerica<T,MAX> &pilha, int posicao){
    return pilha.elementos[pilha.top - posicao];
}

template<typename T, int MAX>
int posicao(PilhaEstaticaGenerica<T,MAX> &pilha, T elemento){
    if (!existeElemento(pilha, elemento)){
        throw "Elemento Inexistente";
    }
    
    for (int i = 0; i < pilha.top; i++){
        if (pilha.elementos[i] == elemento){
            return i;
        }
    }
}

template<typename T, int MAX>
T topo(PilhaEstaticaGenerica<T,MAX> &pilha){
    return pilha.elementos[pilha.top - 1];
}

template<typename T, int MAX>
void inserir(PilhaEstaticaGenerica<T,MAX> &pilha, T elemento){
    if (!temEspaco(pilha)){
        throw "OVERFLOW";
    }

    pilha.elementos[pilha.top] = elemento;
    pilha.top++;
}

template<typename T, int MAX>
void retirar(PilhaEstaticaGenerica<T,MAX> &pilha){
    if (ehVazia){
        throw "UNDERFLOW";
    }
    
    pilha.top--;
}

template<typename T, int MAX>
void mostra(PilhaEstaticaGenerica<T,MAX> &pilha){
    for (int i = 0; i < pilha.top; i++){
        cout << pilha.elementos[i] << " ";
    }  
}