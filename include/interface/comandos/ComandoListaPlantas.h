//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOLISTAPLANTAS_H
#define TESTE_COMANDOLISTAPLANTAS_H

#include "Comando.h"

class Controlador;

class ComandoListaPlantas : public Comando {
    Controlador* ctrlPtr;
public:

    ComandoListaPlantas(const std::string &linha, Controlador* ctrl);

    bool validaComando() override;


    void executaComando() override;
};

#endif
