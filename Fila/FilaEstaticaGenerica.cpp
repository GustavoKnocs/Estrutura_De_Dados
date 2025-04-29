#pragma once
#include <iostream>

using namespace std;

template<typename T, int MAX>
struct FilaEstaticaGenerica{
    int cardinalidade;
    T elemento[MAX];
    int inicio;
    int fim;
};

template<typename T, int MAX>
void cria(FilaEstaticaGenerica<T, MAX> &fila){
    int cardinalidade = 0;
    int inicio = MAX - 1;
    int fim = MAX - 1;
}

template<typename T, int MAX>
bool ehVazia(FilaEstaticaGenerica<T, MAX> &fila){
    return fila.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco(FilaEstaticaGenerica<T, MAX> &fila){
    return fila.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroElementos(FilaEstaticaGenerica<T, MAX> &fila){
    return fila.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento(FilaEstaticaGenerica<T, MAX> &fila, T elemento){
    for (int i = 1; i <= fila.cardinalidade; i++){
        if (fila.elemento[i] = elemento){
            return true;
        }
    }
    return false;
}

template<typename T, int MAX>
bool existePosicao(FilaEstaticaGenerica<T, MAX> &fila, int posicao){
    return posicao > 0 and posicao <= fila.cardinalidade;
}

template<typename T, int MAX>
T elemento(FilaEstaticaGenerica<T, MAX> &fila, int posicao){
    if (!existePosicao(fila,posicao)){
        throw "POSICAO INVALIDA";
    }
    if (fila.inicio + posicao <= MAX - 1){
        return fila.elemento[fila.inicio + posicao];
    }
    else
        return fila.elementos[posicao - MAX + fila.inicio];
}

template<typename T, int MAX>
int posicao(FilaEstaticaGenerica<T, MAX> &fila, T elemento){
    if (!existeElemento(fila,elemento)){
        throw "ELEMENTO NAO EXISTE NA LISTA";
    }
    
    pos = fila.inicio;
    for (int i = 1; i <= fila.cardinalidade; i++){
        pos++;
        if (pos > MAX - 1) pos = 0;
        if (fila.elemento[pos] == elemento){
            return i;
        }   
    }
}

template<typename T, int MAX>
T primeiro(FilaEstaticaGenerica<T, MAX> &fila){
    if (fila.inicio < MAX - 1){
        return fila.elemento[fila.inicio + 1];
    }
    else    
        return fila.elemento[0];
}

template<typename T, int MAX>
T ultimo(FilaEstaticaGenerica<T, MAX> &fila){
    return fila.elemento[fila.fim];
}

template<typename T, int MAX>
void insere(FilaEstaticaGenerica<T, MAX> &fila, T elemento){
    if (!temEspaco(fila)){
        throw "OVERFLOW";
    }

    fila.fim++;
    if (fila.fim > MAX - 1){
        fila.fim = 0;
    }
    fila.elemento[fila.fim] = elemento;
    fila.cardinalidade++
}

template<typename T, int MAX>
void retira(FilaEstaticaGenerica<T,MAX> &fila){
    if (ehVazia(fila)){
        throw "UNDERFLOW";
    }
    
    if (fila.inicio == MAX - 1){
        fila.inicio = 0;
    }
    else fila.inicio++;
    
    fila.cardinalidade--;
}

template<typename T, int MAX>
void mostra(FilaEstaticaGenerica<T, MAX> &fila){
    pos = fila.inicio;
    for (int i = 1; i <= fila.cardinalidade; i++){
        pos++;
        if (pos > MAX - 1) pos = 0;
        cout << fila.elemento[pos] << " "; 
    }
}