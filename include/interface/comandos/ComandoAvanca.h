//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOAVANCA_H
#define TESTE_COMANDOAVANCA_H
#include "Comando.h"
#include <string>
using namespace std;

class ComandoAvanca : public Comando {
    int instantes;

public:
    ComandoAvanca(const string &linha);
    bool validaComando() override;
    void executaComando() override;

    int getInstantes() const;
};

#endif
