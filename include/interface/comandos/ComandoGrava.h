//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOGRAVA_H
#define TESTE_COMANDOGRAVA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoGrava : public Comando {
    std::string nomeCopia;
    Controlador* controlador;

public:

    ComandoGrava(const std::string &linha, Controlador* ctrl);

    bool validaComando() override;
    void executaComando() override;

    std::string getNomeCopia() const;
};

#endif