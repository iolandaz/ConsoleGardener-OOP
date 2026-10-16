//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_TESOURA_H
#define TESTE_TESOURA_H

#include "Ferramenta.h"

class Tesoura : public Ferramenta{
public:
    Tesoura(int idSerie);
    void usarFerramenta(int linha, int coluna) override;
    void descartarFerramenta(int desgaste) override;
};


#endif
