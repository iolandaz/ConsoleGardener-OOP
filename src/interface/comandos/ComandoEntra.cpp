//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoEntra.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoEntra::ComandoEntra(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "entra";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd;
    ss >> cmd;
    ss >> posicao;
}

bool ComandoEntra::validaComando() {
    if (posicao.empty() || posicao.length() != 2) {
        erro = "Posição inválida. Deve ter exatamente 2 letras (ex: fb).";
        valido = false;
        return false;
    }

    if (!islower(posicao[0]) || !islower(posicao[1])) {
        erro = "A posição deve ser composta por letras minúsculas.";
        valido = false;
        return false;
    }

    valido = true;
    erro = "";
    return true;
}

void ComandoEntra::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {
        int l = posicao[0] - 'a';
        int c = posicao[1] - 'a';
        ctrlPtr->entrarNoJardim(l, c);
    }
}

string ComandoEntra::getPosicao() const {
    return posicao;
}