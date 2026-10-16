#include "../../../include/interface/comandos/ComandoApaga.h"
#include "../../../include/controlador/Controlador.h"
#include <iostream>
#include <sstream>

using namespace std;

ComandoApaga::ComandoApaga(const string &linha, Controlador* ctrl) : controlador(ctrl) {
    nome = "apaga";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd;
    ss >> cmd;
    ss >> nomeCopia;
}

bool ComandoApaga::validaComando() {
    if (nomeCopia.empty()) {
        erro = "Falta indicar o nome da cópia a apagar.";
        valido = false;
        return false;
    }
    valido = true;
    return true;
}

void ComandoApaga::executaComando() {
    if (!valido) {
        cout << "Erro: comando 'apaga' inválido (" << erro << ")" << endl;
        return;
    }

    if (controlador != nullptr) {

        controlador->apagarGrava(nomeCopia);
    }
}