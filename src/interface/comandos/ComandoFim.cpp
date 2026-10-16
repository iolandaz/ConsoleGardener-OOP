//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoFim.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoFim::ComandoFim(const string &linha) {
    nome = "fim";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd;
    ss >> extra;
    if (!extra.empty())
        erro = "O comando 'fim' não deve ter argumentos.";
}

bool ComandoFim::validaComando() {
    if (!erro.empty()) {
        valido = false;
        return false;
    }

    valido = true;
    erro = "";
    return true;
}

void ComandoFim::executaComando() {
    if (!valido) {
        cout << "Erro: comando 'fim' inválido (" << erro << ")" << endl;
        return;
    }

}