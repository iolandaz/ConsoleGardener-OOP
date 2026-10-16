//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoMovimentoEsquerda.h"
#include "../../../include/controlador/Controlador.h" // Necessário para usar o ponteiro
#include <sstream>

using namespace std;

ComandoEsquerda::ComandoEsquerda(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "e";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd >> extra;

    if (!extra.empty())
        erro = "O comando 'e' nao deve ter argumentos.";
}

bool ComandoEsquerda::validaComando() {
    return erro.empty();
}

void ComandoEsquerda::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {
        ctrlPtr->moverJardineiro('e');
    }
}