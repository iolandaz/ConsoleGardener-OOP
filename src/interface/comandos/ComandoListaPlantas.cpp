#include "../../../include/interface/comandos/ComandoListaPlantas.h"
#include "../../../include/controlador/Controlador.h"

ComandoListaPlantas::ComandoListaPlantas(const std::string &linha, Controlador* ctrl)
    : ctrlPtr(ctrl) {
    nome = "lplantas";
    valido = true;
}

bool ComandoListaPlantas::validaComando() {
    return true;
}

void ComandoListaPlantas::executaComando() {
    if (ctrlPtr != nullptr) {
        ctrlPtr->listarPlantas();
    }
}