//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOENTRA_H
#define TESTE_COMANDOENTRA_H

#include "Comando.h"
#include <string>

class Controlador;

using namespace std;

class ComandoEntra : public Comando {
    string posicao; // posição onde o jardineiro entra
    Controlador* ctrlPtr;

public:
    ComandoEntra(const string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;

    string getPosicao() const;
};

#endif
