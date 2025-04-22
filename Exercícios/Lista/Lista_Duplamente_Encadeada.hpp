#pragma once
#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
    T elemento;
    Nodo<T>* proximo;
    Nodo<T>* anterior;
};

template<typename T>
struct Lista_Duplamente_Encadeada{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

template<typename T>
void cria(Lista_Duplamente_Encadeada<T>& lista){
    lista.cardinalidade = 0;
    lista.inicio = 0;
    lista.fim = 0 
}

template<typename T>
void destroi(Lista_Duplamente_Encadeada<T>& lista){
    Nodo<T>* p;
    while(lista.inicio != nullptr){
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
    lista.fim = nullptr
}

template<typename T>
bool ehVazia(Lista_Duplamente_Encadeada<T>& lista){
    return lista.cardinalidade = 0;
}

template<typename T>
int NumeroElementos(Lista_Duplamente_Encadeada<T>& lista){
    return lista.cardinalidade;
}

template<typename T>
bool ExisteElemento(Lista_Duplamente_Encadeada<T>& lista, T elemento){
    Nodo<T>*p = lista.inicio
    while (p != nullptr){
        if(p->elemento == elemento){
            return true;
        }
        p = p->proximo;
    }   
    return false;
}

template<typename T>
bool ExistePosicao(Lista_Duplamente_Encadeada<T>& lista, int posicao){
    return ((posicao >= 1) and (posicao <= lista.cardinalidade))
}

template<typename T>
T UmElemento(Lista_Duplamente_Encadeada<T>& lista, int posicao){
    
}