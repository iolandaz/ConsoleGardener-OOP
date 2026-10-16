//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/ComandoCriarJardim.h"

ComandoCriarJardim::ComandoCriarJardim(int l, int c)
{
    linhas = l;
    colunas = c;
    valido = false;
    erro = "";
}

bool ComandoCriarJardim::validaComando()
{
    if (linhas <= 0 || colunas <= 0)
    {
        erro = "Dimensoes invalidas (devem ser maiores que 0)";
        valido = false;
        return false;
    }

    if (linhas > 26 || colunas > 26)
    {
        erro = "Dimensoes maximas permitidas sao 26x26";
        valido = false;
        return false;
    }

    valido = true;
    return true;
}

void ComandoCriarJardim::executaComando() {
}
