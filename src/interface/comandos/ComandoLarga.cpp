#include "../../../include/interface/comandos/ComandoLarga.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoLarga::ComandoLarga(const string &linha, Controlador* c) : controlador(c) {
    nome = "larga";
    valido = true;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd;
    ss >> extra;

    if (!extra.empty()) {
        erro = "O comando 'larga' nao deve ter argumentos.";
        valido = false;
    }
}


bool ComandoLarga::validaComando() {
    return valido && erro.empty();
}


void ComandoLarga::executaComando() {
    if (!validaComando()) {
        cout << "Erro: " << erro << endl;
        return;
    }

    if (controlador == nullptr) return;

    Jardineiro& j = controlador->getJardineiro();

    if (j.getFerramentaAtual() == nullptr) {
        cout << "O jardineiro nao tem nada na mao para largar." << endl;
    } else {
        j.largarFerramentaDaMao();
        cout << "Ferramenta guardada na mochila!" << endl;
    }
}