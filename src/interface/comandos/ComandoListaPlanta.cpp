//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoListaPlanta.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>

using namespace std;

ComandoListaPlanta::ComandoListaPlanta(const string &linha, Controlador* ctrl)
    : ctrlPtr(ctrl) {
    nome = "lplanta";
    valido = false;

    stringstream ss(linha);
    string cmd;
    ss >> cmd;
    ss >> posicao;
}

bool ComandoListaPlanta::validaComando() {
    if (posicao.length() != 2 || !isalpha(posicao[0]) || !isalpha(posicao[1])) {
        erro = "Posicao invalida. Use duas letras (ex: lplanta ab).";
        return false;
    }
    valido = true;
    return true;
}

void ComandoListaPlanta::executaComando() {
    if (!validaComando() || ctrlPtr == nullptr) return;

    int l = tolower(posicao[0]) - 'a';
    int c = tolower(posicao[1]) - 'a';

    ctrlPtr->detalhesPlanta(l, c);
}