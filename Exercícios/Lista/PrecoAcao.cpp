#include "ListaEstatica.hpp"
#include <iostream>
#include <time.h>


using namespace std;

int main(){
    ListaEstatica lista;
    int minutos, ultimopreco;

    srand(time(NULL));

    lista = cria();
    insere(lista, rand()%3 + 5, 0);
    mostra(lista);
    cout << endl;

    minutos = 0;

    while (minutos < 360){
        minutos += 20;
        ultimopreco = umElemento(lista, numeroElementos(lista) - 1);
        insere(lista, ultimopreco + rand()%7 - 3, numeroElementos(lista));
        mostra(lista);
        cout<<endl;
    }
    
    return 0;
}