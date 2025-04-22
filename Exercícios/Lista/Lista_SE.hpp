#pragma once
#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
   T elemento;
   Nodo<T> *proximo; 
};

template<typename T>
struct Lista_SE{
    int cardinalidade;
    Nodo<T> *primeiro;
};

template <typename T>
void cria(Lista_SE<T>& lista){
    lista.cardinalidade = 0;
    lista.primeiro = nullptr;
}

template <typename T>
void destroi(Lista_SE<T>& lista){
    Nodo<T> *p;
    while (lista.primeiro != nullptr){
        p = lista.primeiro;
        lista.primeiro = lista.primeiro->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}

template <typename T>
bool ehVazia(const Lista_SE<T>& lista){
    return lista.cardinalidade = 0;
}

template <typename T>
int numeroElementos(const Lista_SE<T>& lista){
    return lista.cardinalidade;
}

template <typename T>
bool existeElemento(const Lista_SE<T>& lista, T elemento){
    Nodo<T> *p = lista.primeiro;
    while (p != nullptr){
        if (p->elemento == elemento){
            return true;
        }
        p = p->proximo;
    }
    return false;   
}

template <typename T>
bool existePosicao(const Lista_SE<T>& lista, int posicao){
    return (posicao >= 1) and (posicao <= lista.cardinalidade);
}

template <typename T>
T umElemento(const Lista_SE<T>& lista, int posicao){
    if (!existePosicao(lista, posicao)){
        throw "POSICAO INVALIDA";
    }
    Nodo<T> *p = lista.primeiro;
    int contador = 1;

    while (contador < posicao){
        contador++;
        p = p->proximo;
    }
    return p->elemento;
}

template <typename T>
int posicao(const Lista_SE<T>& lista, T elemento){
    if (!existeElemento(lista, elemento)){
        throw "ELEMENTO INVALIDO";
    }
    Nodo<T> *p = lista.primeiro;

    int indice = 1;
    while (p != nullptr){
        if (p->elemento == elemento){
            return indice;
        }
        p = p->proximo;
        indice++;
    } 
}

template<typename T>
void insere(Lista_SE<T>& lista, T elemento, int posicao){
    if ((posicao < 1) or (posicao > lista.cardinalidade + 1)){
        throw "POSICAO INVALIDA";
    }
    Nodo<T> *q = new Nodo<T>;
    q->elemento = elemento;
    q->proximo = nullptr;

    if (lista.primeiro = nullptr){
        lista.primeiro = q;
    }
    else{
        if (posicao = 1){
            q->proximo = lista.primeiro;
            lista.primeiro = q;
        }
        else{
            Nodo<T> *p = lista.primeiro;
            int contador = 1;
            while (contador != posicao - 1){
                p = p->proximo;
            }
            q->proximo = p->proximo;
            p->proximo = q;   
        }
   }
   lista.cardinalidade++;
}

template<typename T>
void retira(Lista_SE<T> &lista, int posicao){
    if (lista.cardinalidade == 0) {
        throw "UNDERFLOW";
    }
    if (posicao < 1 || posicao > lista.cardinalidade) {
        throw "POSICAO INVALIDA";
    }
    Nodo<T> *q = lista.primeiro;
    if (posicao == 1){
        lista.primeiro = lista.primeiro->proximo;
    }
    else {
        Nodo<T> *p = lista.primeiro;
        int contador = 1;
        while (contador < posicao){
            p = p->proximo;
            contador++;
        }
        q = p->proximo;
        p->proximo = q->proximo;
    }
    delete q;
    lista.cardinalidade--;
}