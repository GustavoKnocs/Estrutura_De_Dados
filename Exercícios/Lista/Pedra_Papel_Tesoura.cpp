#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Lista_SE.hpp"

// Função para gerar jogada aleatória
string geraJogada() {
    string opcoes[3] = {"Pedra", "Papel", "Tesoura"};
    return opcoes[rand() % 3];
}

// Função para determinar o vencedor da rodada
int determinaVencedor(string jogadaA, string jogadaB) {
    if (jogadaA == jogadaB) return 0;
    if ((jogadaA == "Pedra" && jogadaB == "Tesoura") ||
        (jogadaA == "Tesoura" && jogadaB == "Papel") ||
        (jogadaA == "Papel" && jogadaB == "Pedra"))
        return 1;
    return 2;
}

int main() {
    srand(time(NULL));
    char jogarNovamente;
    
    do {
        int n;
        cout << "Quantas rodadas deseja jogar? ";
        cin >> n;
        
        Lista_SE<string> jogadorA, jogadorB;
        cria(jogadorA);
        cria(jogadorB);
        
        int pontosA = 0, pontosB = 0; // Garantindo que os pontos são reiniciados a cada jogo
        
        for (int i = 0; i < n; i++) {
            string jogadaA = geraJogada();
            string jogadaB = geraJogada();
            
            insere(jogadorA, jogadaA, 1);
            insere(jogadorB, jogadaB, 1);
            
            int resultado = determinaVencedor(jogadaA, jogadaB);
            if (resultado == 1) pontosA++;
            else if (resultado == 2) pontosB++;
        }
        
        cout << "\nResultado Final:\n";
        if (pontosA > pontosB) cout << "Jogador A venceu com " << pontosA << " pontos!\n";
        else if (pontosB > pontosA) cout << "Jogador B venceu com " << pontosB << " pontos!\n";
        else cout << "Empate! Ambos fizeram " << pontosA << " pontos.\n";
        
        destroi(jogadorA);
        destroi(jogadorB);
        
        cout << "\nDeseja jogar novamente? (s/n): ";
        cin >> jogarNovamente;
    } while (jogarNovamente == 's' || jogarNovamente == 'S');
    
    return 0;
}

