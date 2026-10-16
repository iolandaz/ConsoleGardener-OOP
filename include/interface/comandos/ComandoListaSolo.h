//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOLISTASOLO_H
#define TESTE_COMANDOLISTASOLO_H
#include "Comando.h"
#include <string>

class Controlador;

class ComandoListaSolo : public Comando {
    std::string posicao;
    int raio;
    Controlador* ctrlPtr;

public:
    ComandoListaSolo(const std::string &linha, Controlador* ctrl);
    bool validaComando() override;
    void executaComando() override;
};

#endif
