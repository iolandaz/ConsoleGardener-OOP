//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOLARGA_H
#define TESTE_COMANDOLARGA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoLarga : public Comando {
    Controlador* controlador;
public:
    ComandoLarga(const std::string &linha, Controlador* c);
    bool validaComando() override;
    void executaComando() override;
};

#endif
