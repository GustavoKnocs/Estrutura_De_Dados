#include <iostream>

using namespace std;

#define MAX_SIZE 10

struct Lista{
    int elements[MAX_SIZE];
    int n;
};

void inicializar_lista(Lista &lista){
    lista.n = 0;
}

bool lista_vazia(Lista &lista){
    return lista.n == 0;
}

bool verifica_espaco(Lista &lista){
    return lista.n < MAX_SIZE;
}

int numero_elementos(Lista &lista){
    return lista.n;
}

bool busca_valor(Lista &lista, int elemento){
    for (int i = 0; i < lista.n; i++){
        if(lista.elements[i] == elemento){
            return true;
        }
    }
    return false;    
}

bool posicao_valida(Lista &lista, int posicao){
    return posicao >= 0 and posicao < lista.n;
}

int get_elemento(Lista &lista, int posicao){
    if(posicao_valida(lista, posicao)){
        return lista.elements[posicao];
    }
    return -1;
}

int get_posicao(Lista &lista, int elemento){
    for (int i = 0; i < lista.n; i++){
       if(lista.elements[i] == elemento){
        return i;
       }
    }
    return -1;
}

void inserir_elemento(Lista &lista, int elemento){
    if(verifica_espaco(lista)){
        lista.elements[lista.n] = elemento;
        lista.n++;
    }
}

void retirar_elemento(Lista &lista, int elemento){
    int pos = get_posicao(lista, elemento);
    if (pos != -1){
        for (int i = pos; i < lista.n - 1; i++){
          lista.elements[i] = lista.elements[i+1];  
        }    
        lista.n--;
    } else{
        cout << "Elemento não encontrado!";
    }
}

void exibir_lista(Lista &lista){
    if(lista_vazia(lista)){
        cout << "A lista esta vazia";
    } else{
        cout << "[ ";
        for (int i = 0; i < lista.n; i++){
            cout << lista.elements[i] <<" "; 
        }
        cout << "]"; 
    }   
}

int main(){
    Lista lista;

    lista.n = 5; // Exemplo: 5 elementos na lista
    lista.elements[0] = 10;
    lista.elements[1] = 20;
    lista.elements[2] = 30;
    lista.elements[3] = 40;
    lista.elements[4] = 50;
    
    int num = numero_elementos(lista);
    cout << "A lista tem " << num << " elementos \n";
    int elemento = get_elemento(lista, 4);
    cout << "O elemento da posicao 5 e: " << elemento << "\n";
    int pos = get_posicao(lista, 20);
    cout << "A posicao do elemento 20 e: " << pos + 1 << "\n";
    inserir_elemento(lista, 33);
    exibir_lista(lista);
    cout << "\n";
    retirar_elemento(lista, 10);
    exibir_lista(lista);

    return 0;
}



