//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOMOVIMENTOCIMA_H
#define TESTE_COMANDOMOVIMENTOCIMA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoCima : public Comando {
    Controlador* ctrlPtr;
public:

    ComandoCima(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};


#endif
