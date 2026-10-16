//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOLISTAAREA_H
#define TESTE_COMANDOLISTAAREA_H

#include "Comando.h"

class Controlador;

class ComandoListaArea : public Comando {
    Controlador* ctrlPtr;
public:
    ComandoListaArea(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};


#endif
