//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_FERRAMENTAZ_H
#define TESTE_FERRAMENTAZ_H

#include "Ferramenta.h"

class FerramentaZ : public Ferramenta{
public:
    FerramentaZ(int idSerie);
    void usarFerramenta(int linha, int coluna) override;
    void descartarFerramenta(int desgaste) override;
};


#endif
