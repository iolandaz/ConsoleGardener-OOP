#include "../../../include/interface/comandos/ComandoRecupera.h"
#include "../../../include/controlador/Controlador.h" // Importante para o compilador conhecer os métodos
#include <sstream>
#include <iostream>

using namespace std;


ComandoRecupera::ComandoRecupera(const string &linha, Controlador* ctrl) : controlador(ctrl) {
    nome = "recupera";
    valido = false;
    erro = "";
    nomeCopia = "";

    stringstream ss(linha);
    string cmd;
    ss >> cmd;
    ss >> nomeCopia;
}

bool ComandoRecupera::validaComando() {
    if (nomeCopia.empty()) {
        erro = "Falta indicar o nome da copia a recuperar.";
        valido = false;
        return false;
    }

    valido = true;
    erro = "";
    return true;
}

void ComandoRecupera::executaComando() {
    if (!valido) {
        cout << "Erro: comando 'recupera' invalido (" << erro << ")" << endl;
        return;
    }

    if (controlador != nullptr) {
        controlador->recuperarJardim(nomeCopia);
    }
}

string ComandoRecupera::getNomeCopia() const {
    return nomeCopia;
}