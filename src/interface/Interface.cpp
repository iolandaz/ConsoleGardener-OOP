//
// Created by Utilizador on 25/10/2025.
//

#include "../../include/interface/Interface.h"
#include <iostream>

using namespace std;

void Interface::mostraMensagem(const std::string &msg) const {
    cout << msg << endl;
}

void Interface::mostraErro(const std::string &erro) const {
    cout << "Erro: " << erro << endl;
}

void Interface::mostraTexto() const {
    cout << "Introduza Comando: ";
}

string Interface::leLinha() const {
    string linha;
    getline(cin, linha);
    return linha;
}

void Interface::mostraJardim(const Jardim &jardim, int instante, int jLinha, int jColuna) const {
    cout << "\n--- JARDIM (Instante: " << instante << ") ---" << endl;

    // Cabeçalho das colunas: 4 espaços para alinhar com a margem esquerda
    cout << "    ";
    for (int col = 0; col < jardim.getColunas(); col++) {
        cout << (char)('A' + col) << " ";
    }
    cout << endl;

    for (int i = 0; i < jardim.getLinhas(); i++) {
        // Margem esquerda: Espaço + Letra + Dois Espaços
        cout << " " << (char)('A' + i) << "  ";

        for (int j = 0; j < jardim.getColunas(); j++) {
            // Se as coordenadas baterem, desenha o J
            if (i == jLinha && j == jColuna) {
                cout << "* ";
            } else {
                // Caso contrário, pede o icon ao jardim (-, T, G, etc)
                cout << jardim.getIcon(i, j) << " ";
            }
        }
        cout << endl;
    }
}