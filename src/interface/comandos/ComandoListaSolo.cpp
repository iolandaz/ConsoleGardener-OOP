#include "../../../include/interface/comandos/ComandoListaSolo.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>

using namespace std;

ComandoListaSolo::ComandoListaSolo(const string &linha, Controlador* ctrl)
    : ctrlPtr(ctrl), raio(0) {
    nome = "lsolo";
    valido = false;

    stringstream ss(linha);
    string cmd;
    ss >> cmd >> posicao;


    if (!(ss >> raio)) {
        raio = 0;
    }
}

bool ComandoListaSolo::validaComando() {
    if (posicao.length() != 2 || !isalpha(posicao[0]) || !isalpha(posicao[1])) {
        erro = "Formato invalido! Use: lsolo <lc> [raio]";
        return false;
    }
    if (raio < 0) {
        erro = "O raio nao pode ser negativo!";
        return false;
    }
    valido = true;
    return true;
}

void ComandoListaSolo::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {
        int l = tolower(posicao[0]) - 'a';
        int c = tolower(posicao[1]) - 'a';
        ctrlPtr->listarSolo(l, c, raio);
    }
}