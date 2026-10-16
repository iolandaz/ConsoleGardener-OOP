//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoColhe.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>

using namespace std;

ComandoColhe::ComandoColhe(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "colhe";
    valido = false;
    stringstream ss(linha);
    string cmd;
    ss >> cmd >> posicao;
}

bool ComandoColhe::validaComando() {
    if (posicao.length() != 2 || !isalpha(posicao[0]) || !isalpha(posicao[1])) {
        erro = "Posicao invalida. Use algo como 'colhe aa'.";
        return false;
    }
    valido = true;
    return true;
}

void ComandoColhe::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {
        int l = tolower(posicao[0]) - 'a';
        int c = tolower(posicao[1]) - 'a';
        ctrlPtr->colher(l, c);
    }
}
