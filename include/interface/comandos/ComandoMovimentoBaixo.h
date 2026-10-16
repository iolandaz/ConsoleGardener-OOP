//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOMOVIMENTOBAIXO_H
#define TESTE_COMANDOMOVIMENTOBAIXO_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoBaixo : public Comando {
    Controlador* ctrlPtr;
public:

    ComandoBaixo(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};

#endif
