#include "../../../include/interface/comandos/ComandoMovimentoCima.h"
#include "../../../include/controlador/Controlador.h" // Necessário para aceder ao ctrlPtr
#include <sstream>

using namespace std;

ComandoCima::ComandoCima(const string &linha, Controlador* ctrl) : ctrlPtr(ctrl) {
    nome = "c";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd >> extra;

    if (!extra.empty())
        erro = "O comando 'c' nao deve ter argumentos.";
}

bool ComandoCima::validaComando() {
    return erro.empty();
}

void ComandoCima::executaComando() {
    if (validaComando() && ctrlPtr != nullptr) {

        ctrlPtr->moverJardineiro('c');
    }
}