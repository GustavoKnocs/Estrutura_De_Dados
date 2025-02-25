#include "LE_Generica.hpp"
#include <iostream>

using namespace std;

int main(){
    struct Produto{
        string nome;
        float preco;
    };
    
    LE_Generica<Produto, 10> estoque;
    cria(estoque);

    int opcao;
    do{
        cout << "MENU:" << endl;
        cout << "1 - Inserir Produto" << endl;
        cout << "2 - Remover Produto" << endl;
        cout << "3 - Exibir Produtos" << endl;
        cout << "4 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                Produto p;
                int posicao;
                cout << "Digite o nome do produto: ";
                cin >> p.nome;
                cout << "Digite o preco do produto: ";
                cin >> p.preco;
                cout << "Digite a posicao do produto: ";
                cin >> posicao;
                
                try {
                    insere(estoque, p, posicao);
                    cout << "Produto inserido com sucesso!" << endl;
                } catch (const char* msg) {
                    cout << msg << endl;
                }
                break;
            }
            case 2: {
                int posicao;
                cout << "Digite a posicao do produto a ser removido: ";
                cin >> posicao;
                
                try {
                    retira(estoque, posicao);
                    cout << "Produto removido com sucesso!" << endl;
                } catch (const char* msg) {
                    cout << msg << endl;
                }
                break;
            }
            case 3: {
                if (eh_vazia(estoque)) {
                    cout << "Estoque vazio!" << endl;
                } else {
                    for (int i = 0; i < estoque.cardinalidade; i++) {
                        cout << "Produto: " << estoque.elementos[i].nome << ", Preco: " << estoque.elementos[i].preco << endl;
                    } 
                }
                break;
            }
            case 4: {
                cout << "Saindo..." << endl;
                break;
            }
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 4);

    return 0;
}