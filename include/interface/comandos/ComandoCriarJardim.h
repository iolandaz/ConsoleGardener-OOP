//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDOCRIARJARDIM_H
#define TESTE_COMANDOCRIARJARDIM_H

#include "Comando.h"

class ComandoCriarJardim : public Comando {
    int linhas;
    int colunas;

public:
    ComandoCriarJardim(int l, int c);

    bool validaComando() override;
    void executaComando() override;
    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
};


#endif
