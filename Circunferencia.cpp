#include <iostream>
#include <cmath>

using namespace std;

struct Circunferencia{
    double raio;
    double x, y;
};

// Construtor
Circunferencia cria_circunferencia(double r, double X, double Y) {
    Circunferencia c;
    c.raio = r;
    c.x = X;
    c.y = Y;
    return c;
}

double get_raio(Circunferencia c) {
    return c.raio;
}

double get_x(Circunferencia c) {
    return c.x;
}

double get_y(Circunferencia c) {
    return c.y;
}

double Calcula_Diametro(Circunferencia c) {
    return c.raio * 2;
}

double Calcula_Perimetro(Circunferencia c) {
    return 2 * c.raio * M_PI;
}

void set_raio(Circunferencia &c, double r) {
    c.raio = r;
}

void set_x(Circunferencia &c, double X) {
    c.x = X;
}

void set_y(Circunferencia &c, double Y) {
    c.y = Y;
}

bool menor(Circunferencia c1, Circunferencia c2) {
    return c1.raio < c2.raio;
}

bool maior(Circunferencia c1, Circunferencia c2) {
    return c1.raio > c2.raio;
}

bool igual(Circunferencia c1, Circunferencia c2) {
    return c1.raio == c2.raio;
}

bool mesma_posicao(Circunferencia c1, Circunferencia c2) {
    return c1.x == c2.x && c1.y == c2.y;
}

void imprime_circunferencia(Circunferencia c) {
    cout << "Raio: " << c.raio << " | Posição: (" << c.x << ", " << c.y << ")" << endl;
}

int main() {
    Circunferencia circ[5];
   
    // a) Criar as circunferências conforme o enunciado
    circ[0] = cria_circunferencia(10, 2, 3);  
    circ[1] = cria_circunferencia(12, 2, 3);  
    circ[2] = cria_circunferencia(15, 7, 10); 
    circ[3] = cria_circunferencia(get_raio(circ[0]) + 5, get_x(circ[0]), get_y(circ[0])); 
    circ[4] = cria_circunferencia(13, get_y(circ[2]) - 10, 9); 

    // b) Alterar o raio da primeira circunferência para mais 3 unidades
    set_raio(circ[0], get_raio(circ[0]) + 3);

    // c) Exibir o perímetro de todas as circunferências
    cout << "\nPerímetros das circunferências:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Circunferência " << i + 1 << " / Perímetro = " << Calcula_Perimetro(circ[i]) << endl;
    }

    // d) Identificar circunferências com a mesma posição
    cout << "\nCircunferências com a mesma posição:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (mesma_posicao(circ[i], circ[j])) {
                cout << "As circunferências " << i + 1 << " e " << j + 1 << " têm a mesma posição." << endl;
            }
        }
    }

    cout << "\nExibindo todas as circunferências:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Circunferência " << i + 1 << ": ";
        imprime_circunferencia(circ[i]);
    }

    return 0;
}
