//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOPLANTA_H
#define TESTE_COMANDOPLANTA_H

#include "Comando.h"
#include <string>

class Controlador;

class ComandoPlanta : public Comando {
    std::string posicao;
    char tipo;
    Controlador* ctrlPtr;

public:

    ComandoPlanta(const std::string &linha, Controlador* ctrl);

    bool validaComando() override;


    void executaComando() override;

    std::string getPosicao() const;
    char getTipo() const;
};
#endif
