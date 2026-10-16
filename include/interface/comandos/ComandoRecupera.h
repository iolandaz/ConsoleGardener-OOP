//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDORECUPERA_H
#define TESTE_COMANDORECUPERA_H

#include "Comando.h"
#include <string>
class Controlador;

using namespace std;

class ComandoRecupera : public Comando {
    string nomeCopia;
    Controlador* controlador;

public:

    ComandoRecupera(const string &linha, Controlador* ctrl);

    bool validaComando() override;
    void executaComando() override;

    string getNomeCopia() const;
};

#endif
