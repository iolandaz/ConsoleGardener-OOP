//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOCOMPRA_H
#define TESTE_COMANDOCOMPRA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoCompra : public Comando {
    Controlador* controlador;
    char tipoAlvo;
public:
    ComandoCompra(const std::string &linha, Controlador* c);
    bool validaComando() override;
    void executaComando() override;
};

#endif