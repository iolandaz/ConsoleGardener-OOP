//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoPlanta.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>

using namespace std;

ComandoPlanta::ComandoPlanta(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "planta";
    valido = false;
    tipo = '\0';

    stringstream ss(linha);
    string cmd;
    ss >> cmd;
    ss >> posicao;
    ss >> tipo;
}

bool ComandoPlanta::validaComando() {
    if (posicao.length() != 2 || !isalpha(posicao[0]) || !isalpha(posicao[1])) {
        erro = "Posicao invalida. Use duas letras (ex: ab).";
        return false;
    }

    char t = tolower(tipo);
    if (t != 'c' && t != 'r' && t != 'e' && t != 'x') {
        erro = "Tipo de planta invalido (c, r, e, x).";
        return false;
    }

    valido = true;
    return true;
}

void ComandoPlanta::executaComando() {
    if (!validaComando() || ctrlPtr == nullptr) return;


    int l = tolower(posicao[0]) - 'a';
    int c = tolower(posicao[1]) - 'a';


    ctrlPtr->plantar(l, c, tipo);
}