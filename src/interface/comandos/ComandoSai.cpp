//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoSai.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoSai::ComandoSai(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "sai";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd;
    ss >> extra;
    if (!extra.empty())
        erro = "O comando 'sai' não deve ter argumentos.";
}

bool ComandoSai::validaComando() {
    if (!erro.empty()) {
        valido = false;
        return false;
    }

    valido = true;
    erro = "";
    return true;
}

void ComandoSai::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {
        ctrlPtr->sairDoJardim();
    }
}