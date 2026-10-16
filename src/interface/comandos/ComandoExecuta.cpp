#include "../../../include/interface/comandos/ComandoExecuta.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

ComandoExecuta::ComandoExecuta(const string &linha, Controlador* ctrl) : controlador(ctrl) {
    nome = "executa";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd;
    ss >> cmd;
    ss >> nomeFicheiro;
}

bool ComandoExecuta::validaComando() {
    if (nomeFicheiro.empty()) {
        erro = "Falta indicar o nome do ficheiro a executar.";
        valido = false;
        return false;
    }
    valido = true;
    return true;
}

void ComandoExecuta::executaComando() {
    if (!valido || controlador == nullptr) return;

    ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        cout << "Erro: Nao foi possivel abrir o ficheiro '" << nomeFicheiro << "'" << endl;
        return;
    }

    string linhaLida;
    while (getline(ficheiro, linhaLida)) {
        if (linhaLida.empty() || linhaLida == "fim") continue;

        controlador->processarLinhaComando(linhaLida);
    }

    ficheiro.close();
}