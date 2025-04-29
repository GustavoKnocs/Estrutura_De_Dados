#include <iostream>

using namespace std;

template<typename T, int MAX>
struct LE_Generica_Teste{
    int cardinalidade;
    T elementos[MAX];
};

template<typename T, int MAX>
void cria(LE_Generica_Teste<T, MAX> &lista){
    lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia(LE_Generica_Teste<T, MAX> &lista){
    return lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool temEspaco(LE_Generica_Teste<T, MAX> &lista){
    return lista.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroElementos(LE_Generica_Teste<T, MAX> &lista){
    return lista.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento(LE_Generica_Teste<T, MAX> &lista, T elemento){
    for (int i = 0; i < lista.cardinalidade; i++){
        if(elemento == lista.elementos[i]){
            return true;
        }
    }
    return false;    
}

template<typename T, int MAX>
bool existePosicao(LE_Generica_Teste<T, MAX> &lista, int posicao){
    return (posicao >= 1) and (posicao <= lista.cardinalidade);
}

template<typename T, int MAX>
T umElemento(LE_Generica_Teste<T, MAX> &lista, int posicao){
    if(!existePosicao){
        throw "POSICAO INVALIDA";
    }
    return lista.elementos[posicao];
}

template<typename T, int MAX>
int umaPosicao(LE_Generica_Teste<T, MAX> &lista, T elemento){
    if (!existeElemento){
        throw "ELEMENTO INVALIDO";
    }
    for (int i = 1; i < lista.cardinalidade; i++){
        if (elemento == lista.elementos[i]){
            return i;
        } 
    }
}

template<typename T, int MAX>
void insere(LE_Generica_Teste<T, MAX> &lista, T elemento, int posicao){
    if (lista.cardinalidade = MAX){
        throw "OVERFLOW";
    }
    if (posicao < 1 or posicao > lista.cardinalidade + 1){
        throw "POSICAO INVALIDA";   
    }
    for (int i = posicao; i < lista.cardinalidade; i++){
        lista.elementos[i + 1] = lista.elementos[i];
    }
    lista.elementos[posicao - 1] = elemento;
    lista.cardinalidade++;
}

template<typename T, int MAX>
int retira(LE_Generica_Teste<T, MAX> &lista, int posicao){
    if (lista.cardinalidade == 0){
        throw "UNDERFLOW"
    }
    
    if (!existePosicao){
        throw "POSICAO INVALIDA";
    }
    for (int i = posicao; i < lista.cardinalidade; i++){
        lista.elementos[i] = lista.elementos[i+1];
    }
    lista.cardinalidade--; 
}
