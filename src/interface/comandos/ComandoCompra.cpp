//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoCompra.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoCompra::ComandoCompra(const string &linha, Controlador* c)
    : controlador(c), tipoAlvo('\0') {
    nome = "compra";
    valido = false;

    stringstream ss(linha);
    string cmd;
    ss >> cmd; // "compra"

    if (ss >> tipoAlvo) {

        if (tipoAlvo == 'g' || tipoAlvo == 'a' || tipoAlvo == 't' || tipoAlvo == 'z') {
            valido = true;
        } else {
            erro = "Tipo de ferramenta invalido (use: g, a, t ou z).";
        }
    } else {
        erro = "Deve indicar o tipo (ex: compra g).";
    }
}

bool ComandoCompra::validaComando() {
    return valido && controlador != nullptr;
}

void ComandoCompra::executaComando() {
    if (!validaComando()) {
        cout << "Erro: " << erro << endl;
        return;
    }
    controlador->comprarFerramenta(tipoAlvo);
}