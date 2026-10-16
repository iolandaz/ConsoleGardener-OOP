//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOPEGA_H
#define TESTE_COMANDOPEGA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoPega : public Comando {
    Controlador* controlador;
    int idAlvo;
public:
    ComandoPega(const std::string &linha, Controlador* c);
    bool validaComando() override;
    void executaComando() override;
};

#endif
