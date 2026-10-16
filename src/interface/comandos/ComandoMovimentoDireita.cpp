#include "../../../include/interface/comandos/ComandoMovimentoDireita.h"
#include "../../../include/controlador/Controlador.h" // Incluir para usar o ctrlPtr
#include <sstream>

using namespace std;

ComandoDireita::ComandoDireita(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "d";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd >> extra;

    if (!extra.empty())
        erro = "O comando 'd' nao deve ter argumentos.";
}

bool ComandoDireita::validaComando() {
    return erro.empty();
}

void ComandoDireita::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {

        ctrlPtr->moverJardineiro('d');
    }
}