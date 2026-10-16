//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOSAI_H
#define TESTE_COMANDOSAI_H

#include "Comando.h"
#include <string>
using namespace std;

class Controlador;

class ComandoSai : public Comando {
    Controlador* ctrlPtr;
public:
    ComandoSai(const string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};

#endif
