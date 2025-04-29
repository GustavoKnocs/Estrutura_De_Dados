#include <iostream>
#include "LE_Generica.hpp"

using namespace std;

int main(){
    
    struct Produto{
        string nome;
        double preco;
    };
    
    LE_Generica <Produto, 10> estoque;
    cria(estoque);
    int opcao;
    do{
        cout << "-----Escolha uma das opcoes-----\n";
        cout << "1- Insira um Produto\n";
        cout << "2- Remover um Produto\n";
        cout << "3- Exibir os Produtos\n";
        cout << "4- Sair\n";
        cout << "opcao: ";
        cin >> opcao;
        cin.ignore();
    
        switch(opcao){
            case 1: {
                Produto p;
                cout << "Informe o nome do produto: ";
                getline(cin, p.nome);
                cout << "Informe o preco do produto: ";
                cin >> p.preco;
                cout << estoque.cardinalidade;
                if (TemEspaco(estoque)) {
                    insere(estoque, p, NumeroElementos(estoque) + 1);
                    cout << "Produto inserido com sucesso!\n";
                } else {
                    cout << "Estoque cheio! Não é possível adicionar mais produtos.\n";
                }
            break;
            }
            case 2: {
                int pos;
                cout << "Informe a posicao do produto: ";
                cin >> pos;
                retira(estoque, pos); 
            break;
            } 
            case 3: {
                for (int i = 0; i < NumeroElementos(estoque); i++){
                    Produto p = UmElemento(estoque,i);
                    cout << "Nome: " << p.nome << " | Preco: R$" << p.preco; 
                }
                ;
            break;
            }     
            case 4: {
                cout << "saindo...";
            break;
            } 
            default:
                cout << "opcao invalida, insira um numero entre 1 e 4"; 
        }
    } while (opcao != 4);

    return 0;
}
            

    

