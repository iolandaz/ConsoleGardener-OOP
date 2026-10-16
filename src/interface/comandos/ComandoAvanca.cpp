//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoAvanca.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoAvanca::ComandoAvanca(const string &linha) {
    nome = "avanca";
    valido = false;
    erro = "";
    instantes = 1;

    stringstream ss(linha);
    string cmd;
    ss >> cmd; // lê "avanca"

    if (!(ss >> instantes)) {
        instantes = 1; // se não conseguir ler número, assume 1
    }
}

bool ComandoAvanca::validaComando() {
    if (instantes <= 0) {
        erro = "Número de instantes inválido (deve ser > 0).";
        valido = false;
        return false;
    }

    valido = true;
    erro = "";
    return true;
}

void ComandoAvanca::executaComando() {
    if (!valido) {
        cout << "Erro: comando 'avanca' inválido (" << erro << ")" << endl;
        return;
    }


    cout << "Avançar " << instantes << " instante(s) no simulador." << endl;
}

int ComandoAvanca::getInstantes() const {
    return instantes;
}
