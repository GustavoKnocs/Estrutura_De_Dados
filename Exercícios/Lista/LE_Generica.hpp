#pragma once
#include <iostream>

using namespace std;

template <typename T, int MAX>
struct LE_Generica{
    int cardinalidade;
    T elementos[MAX];
};

template <typename T, int MAX>
void cria(LE_Generica<T, MAX> &lista){
    lista.cardinalidade = 0;
}

template <typename T, int MAX>
bool eh_vazia(LE_Generica<T, MAX> &lista){
    return lista.cardinalidade == 0;
}

template <typename T, int MAX>
bool TemEspaco(LE_Generica<T, MAX> &lista){
    return lista.cardinalidade < MAX;
}

template <typename T, int MAX>
int NumeroElementos(LE_Generica<T, MAX> &lista){
    return lista.cardinalidade;
}

template <typename T, int MAX>
bool ExisteElemento(LE_Generica<T, MAX> &lista, T elemento){
    for (int i = 0; i < lista.cardinalidade; i++)
    {
        if (lista.elementos[i] == elemento){
            return true;
        }
    }
    return false;
}

template <typename T, int MAX>
bool ExistePosicao(LE_Generica<T, MAX> &lista, int posicao){
    return ((posicao >= 1) and (posicao <= lista.cardinalidade));
}

template <typename T, int MAX>
T UmElemento(LE_Generica<T, MAX> &lista, int posicao){
    return lista.elementos[posicao];
}

template <typename T, int MAX>
int Posicao(LE_Generica<T, MAX> &lista, T elemento){
    if (!ExisteElemento(lista, elemento)){
        throw "ELEMENTO NAO ESTA NA LISTA";
    }
    for (int i = 0; i < lista.cardinalidade; i++){
        if (lista.elementos[i] == elemento){
            return i + 1;
        }
    }
}

template <typename T, int MAX>
void insere(LE_Generica<T, MAX> &lista, T elemento, int posicao){
    if(lista.cardinalidade == MAX){
        throw "OVERFLOW";
    }
    if(posicao < 1 || posicao > lista.cardinalidade + 1){
        throw "POSICAO INVALIDA";
    }
    for (int i = lista.cardinalidade; i >= posicao; i--){
        lista.elementos[i] = lista.elementos[i - 1];
    }
    lista.elementos[posicao - 1] = elemento;
    lista.cardinalidade++;
}

template <typename T, int MAX>
void retira(LE_Generica<T, MAX> &lista, int posicao){
    if(lista.cardinalidade == 0){
        throw "UNDERFLOW";}
    if(posicao < 1 || posicao > lista.cardinalidade){
        throw "POSICAO INVALIDA";}
    for (int i = posicao; i < lista.cardinalidade; i++){
        lista.elementos[i - 1] = lista.elementos[i];
    }
    lista.cardinalidade--;
}

template <typename T, int MAX>
void mostra(LE_Generica<T, MAX> &lista){
    for (int i = 0; i < lista.cardinalidade; i++){
        cout << lista.elementos[i] << " ";
    }
    cout << endl;
}

template <typename T, int MAX>
void ordena(LE_Generica<T, MAX> &lista){
    for (int i = 0; i < lista.cardinalidade - 1; i++){
        bool trocou = false;
        for (int j = 0; j < lista.cardinalidade - i - 1; j++) {
            if (lista.elementos[j] > lista.elementos[j + 1]){
                T aux = lista.elementos[j];
                lista.elementos[j] = lista.elementos[j + 1];
                lista.elementos[j + 1] = aux;
                trocou = true;
            }
        }
        if (!trocou)
            break;
    }
}

template <typename T, int MAX>
void Menor_e_Maior(LE_Generica<T, MAX> &lista){
    if (lista.cardinalidade == 0){
        throw "UNDERFLOW";
    }
    T maior = lista.elementos[0];
    T menor = lista.elementos[0];
    for (int i = 0; i < lista.cardinalidade; i++){
        if (lista.elementos[i] < menor){
            menor = lista.elementos[i];
        }
        if (lista.elementos[i] > maior){
            maior = lista.elementos[i];
        }
    }
}

template <typename T, int MAX>
void RemoverDuplicados(LE_Generica<T, MAX> &lista){
    for (int i = 0; i < lista.cardinalidade; i++)
    {
        T elemento = lista.elementos[i];
        for (int j = i + 1; j < lista.cardinalidade; j++){
            if (lista.elementos[j] == elemento){
                for (int k = j; k < lista.cardinalidade - 1; k++){
                    lista.elementos[k] = lista.elementos[k + 1]; 
                }
                lista.cardinalidade--;
                j--;   
            }
        }
    }
}
