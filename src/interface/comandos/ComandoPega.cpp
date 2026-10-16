#include "../../../include/interface/comandos/ComandoPega.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoPega::ComandoPega(const string &linha, Controlador* c) : controlador(c), idAlvo(-1) {
    nome = "pega";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd;
    ss >> cmd;

    if (!(ss >> idAlvo)) {
        erro = "Deve indicar um numero de serie valido. Ex: pega 7";
    } else {
        valido = true;
    }
}

bool ComandoPega::validaComando() {
    return valido && erro.empty();
}

void ComandoPega::executaComando() {
    if (!validaComando()) {
        cout << "Erro: " << erro << endl;
        return;
    }

    Jardineiro& j = controlador->getJardineiro();


    bool encontrou = false;
    for (auto* f : j.getInventario()) {
        if (f->getID() == idAlvo) {
            encontrou = true;
            break;
        }
    }

    if (encontrou) {
        j.trocarFerramenta(idAlvo);
        cout << "O jardineiro agora tem a ferramenta [ID: " << idAlvo << "] na mao." << endl;
    } else {
        cout << "Erro: O jardineiro nao transporta nenhuma ferramenta com o numero de serie " << idAlvo << "." << endl;
    }
}