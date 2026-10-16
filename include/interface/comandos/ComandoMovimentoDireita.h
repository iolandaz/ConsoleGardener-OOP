//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOMOVIMENTODIREITA_H
#define TESTE_COMANDOMOVIMENTODIREITA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoDireita : public Comando {
    Controlador* ctrlPtr;
public:

    ComandoDireita(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};

#endif
