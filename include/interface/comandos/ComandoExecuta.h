//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOEXECUTA_H
#define TESTE_COMANDOEXECUTA_H

#include "Comando.h"
#include <string>
class Controlador;

class ComandoExecuta : public Comando {
    std::string nomeFicheiro;
    Controlador* controlador;

public:
    ComandoExecuta(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;

    std::string getNomeFicheiro() const;
};

#endif
