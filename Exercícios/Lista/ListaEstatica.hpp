#pragma once
#include <iostream>

using namespace std;

const int tamanho = 1000;

struct ListaEstatica{
    int cardinalidade;
    int elementos[tamanho];
};

ListaEstatica cria(){
    ListaEstatica lista;
    lista.cardinalidade = 0;
    return lista;
}

bool ehVazia(ListaEstatica lista){
    return lista.cardinalidade == 0;
}

bool temEspaco(ListaEstatica lista){
    return lista.cardinalidade < tamanho;
}

int numeroElementos(ListaEstatica lista){
    return lista.cardinalidade;
}

bool existeElemento(ListaEstatica lista, int elemento){
    for (int i = 0; i < lista.cardinalidade; i++){
        if (elemento == lista.elementos[i]){
            return true;
        }
    }
    return false;
}

bool existePosicao(ListaEstatica lista, int posicao){
    return (posicao >= 0) and (posicao <= lista.cardinalidade);
}

int umElemento(ListaEstatica lista, int posicao){
    return lista.elementos[posicao];
}

int posicao(ListaEstatica lista, int elemento){
    for (int i = 0; i < lista.cardinalidade; i++){
        if (elemento == lista.elementos[i]){
            return i;
        }
    }   
}

void insere(ListaEstatica &lista, int elemento, int posicao){
    for (int i = posicao; i < lista.cardinalidade; i++){
        lista.elementos[i+1] = lista.elementos[i];
    }
    lista.elementos[posicao] = elemento;
    lista.cardinalidade++;
}

void retira(ListaEstatica &lista, int posicao){
    for (int i = posicao; i < lista.cardinalidade; i++){
        lista.elementos[i] = lista.elementos[i + 1];
    }
    lista.cardinalidade--;
}

void mostra(ListaEstatica lista){
    cout << "[ ";
    for (int i = 0; i < lista.cardinalidade; i++){
        cout << lista.elementos[i] << " ";
    }
    cout << "]";
}