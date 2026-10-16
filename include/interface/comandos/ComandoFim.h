
//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOFIM_H
#define TESTE_COMANDOFIM_H

#include "Comando.h"
#include <string>
using namespace std;

class ComandoFim : public Comando {
public:
    ComandoFim(const string &linha);
    bool validaComando() override;
    void executaComando() override;
};

#endif