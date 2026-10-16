//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOCOLHE_H
#define TESTE_COMANDOCOLHE_H


#include "Comando.h"
#include <string>

class Controlador;

class ComandoColhe : public Comando {
    std::string posicao;
    Controlador* ctrlPtr;

public:
    ComandoColhe(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};

#endif
