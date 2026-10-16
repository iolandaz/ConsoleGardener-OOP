#include "../../../include/interface/comandos/ComandoGrava.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>

using namespace std;


ComandoGrava::ComandoGrava(const string &linha, Controlador* ctrl) : controlador(ctrl) {
    nome = "grava";
    valido = false;

    stringstream ss(linha);
    string cmd;
    ss >> cmd;
    ss >> nomeCopia;
}

bool ComandoGrava::validaComando() {
    if (nomeCopia.empty()) {
        erro = "Falta o nome da copia.";
        return false;
    }
    valido = true;
    return true;
}

void ComandoGrava::executaComando() {
    if (valido && controlador != nullptr) {
        controlador->gravarJardim(nomeCopia);
    }
}