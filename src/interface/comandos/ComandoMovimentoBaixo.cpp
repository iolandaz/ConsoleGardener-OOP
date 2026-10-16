#include "../../../include/interface/comandos/ComandoMovimentoBaixo.h"
#include "../../../include/controlador/Controlador.h"
#include <sstream>

using namespace std;

ComandoBaixo::ComandoBaixo(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "b";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd >> extra;

    if (!extra.empty())
        erro = "O comando 'b' nao deve ter argumentos.";
}

bool ComandoBaixo::validaComando() {
    return erro.empty();
}

void ComandoBaixo::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {

        ctrlPtr->moverJardineiro('b');
    }
}