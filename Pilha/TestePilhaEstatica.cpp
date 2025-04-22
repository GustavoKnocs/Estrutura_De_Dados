#include <iostream>
#include "PilhaEstaticaGenerica.hpp"

using namespace std;

const int NUM_PILHAS = 50;
const int TAM_PILHA = 10;
const int MAX_ELEM_PILHA = 100;

int main(){
    PilhaEstaticaGenerica<int, MAX_ELEM_PILHA> pilhas[NUM_PILHAS];

    for (int i = 0; i < NUM_PILHAS; i++){
        cria(pilhas[i]);
    }

    int num;
    
    do{
        do
        {
            cout << "Insira um numero dentro do intervalo '0 a 499' / Insira um numero negativo caso nao queira mais inserir.\n";
            cin >> num;
            
            if (num > 499){
                cout << "Entrada Invalida\n";
            }    
        } while (num > 499);
        
        if (num < 0){
            break;
        }
        
        int indice_pilha = num / TAM_PILHA;
        inserir(pilhas[indice_pilha], num);
    } while (num > 0);
    
    for (int i = 0; i < NUM_PILHAS; i++){
        cout << "Pilha " << i + 1 << " Intervalo " << i*10 << " - " << ((i + 1) * 10) - 1<< ": ";
        if (ehVazia(pilhas[i])){
            cout << "Pilha Vazia";
        } else{
            mostra(pilhas[i]);
        }  
        cout << endl;
    }
    return 0;
}