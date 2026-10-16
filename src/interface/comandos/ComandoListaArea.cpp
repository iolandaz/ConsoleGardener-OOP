#include "../../../include/interface/comandos/ComandoListaArea.h"
#include "../../../include/controlador/Controlador.h"

ComandoListaArea::ComandoListaArea(const std::string &linha, Controlador* ctrl)
    : ctrlPtr(ctrl) {
    nome = "larea";
    valido = true;
}

bool ComandoListaArea::validaComando() {
    return true;
}

void ComandoListaArea::executaComando() {
    if (ctrlPtr != nullptr) {
        ctrlPtr->listarAreaOcupada();
    }
}