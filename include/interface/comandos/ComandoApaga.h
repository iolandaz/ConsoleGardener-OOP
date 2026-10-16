//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOAPAGA_H
#define TESTE_COMANDOAPAGA_H

#include "Comando.h"
#include <string>
class Controlador;

using namespace std;

class ComandoApaga : public Comando {
    string nomeCopia;
    Controlador* controlador;

public:

    ComandoApaga(const string &linha, Controlador* ctrl);

    bool validaComando() override;
    void executaComando() override;
};



#endif
