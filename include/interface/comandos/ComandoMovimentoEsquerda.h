//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOMOVIMENTOESQUERDA_H
#define TESTE_COMANDOMOVIMENTOESQUERDA_H
#include "Comando.h"
#include <string>

class Controlador;
class ComandoEsquerda : public Comando {
    Controlador* ctrlPtr;
public:
    ComandoEsquerda(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};


#endif
