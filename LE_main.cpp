#include <iostream>
#include "LE_Generica.hpp"

using namespace std;

template<typename T, int MAX>
void menu() {
    LE_Generica<T, MAX> lista;
    cria(lista);
    int escolha;

    do {
        cout << "\nMENU:\n";
        cout << "1 - Inserir elemento\n";
        cout << "2 - Remover elemento\n";
        cout << "3 - Mostrar lista\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        if (escolha == 1) {
            if (!TemEspaco(lista)) {
                cout << "Lista cheia! Não é possível inserir mais elementos.\n";
                continue;
            }

            T elemento;
            int posicao;
            cout << "Digite o elemento a ser inserido: ";
            cin >> elemento;
            cout << "Digite a posição (1 a " << lista.cardinalidade + 1 << "): ";
            cin >> posicao;

            if (posicao >= 1 && posicao <= lista.cardinalidade + 1) {
                insere(lista, elemento, posicao);
            } else {
                cout << "Posição inválida!\n";
            }
        }
        else if (escolha == 2) {
            if (eh_vazia(lista)) {
                cout << "Lista vazia, impossível remover!\n";
                continue;
            }

            int posicao;
            cout << "Digite a posição do elemento a ser removido (1 a " << lista.cardinalidade << "): ";
            cin >> posicao;

            if (posicao >= 1 && posicao <= lista.cardinalidade) {
                retira(lista, posicao);
            } else {
                cout << "Posição inválida!\n";
            }
        }
        else if (escolha == 3) {
            if (eh_vazia(lista)) {
                cout << "Lista vazia!\n";
            } else {
                mostra(lista);
            }
        }
        else if (escolha != 4) {
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (escolha != 4);
}

int main() {
    int tipo;
    cout << "Escolha o tipo de dado para a lista (1 - Inteiro, 2 - Flutuante, 3 - Caractere): ";
    cin >> tipo;

    if (tipo == 1) {
        menu<int, 10>();
    }
    else if (tipo == 2) {
        menu<float, 10>();
    }
    else if (tipo == 3) {
        menu<char, 10>();
    }
    else {
        cout << "Tipo inválido selecionado.\n";
    }

    return 0;
}

