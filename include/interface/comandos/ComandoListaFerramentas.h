//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOLISTAFERRAMENTAS_H
#define TESTE_COMANDOLISTAFERRAMENTAS_H

#include "Comando.h"
#include "../../controlador/Controlador.h" // Precisamos do controlador
#include <string>

class ComandoLferr : public Comando {
    Controlador &controlador;
public:
    
    ComandoLferr(const std::string &linha, Controlador &c);

    bool validaComando() override;
    void executaComando() override;
};

#endif