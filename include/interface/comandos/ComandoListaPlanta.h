//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOLISTAPLANTA_H
#define TESTE_COMANDOLISTAPLANTA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoListaPlanta : public Comando {
    std::string posicao;
    Controlador* ctrlPtr;

public:
    ComandoListaPlanta(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};

#endif
