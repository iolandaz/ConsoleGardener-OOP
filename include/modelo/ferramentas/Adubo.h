//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_ADUBO_H
#define TESTE_ADUBO_H

#include "Ferramenta.h"

class Adubo : public Ferramenta {
public:
    Adubo(int idSerie);
    void usarFerramenta(int linha, int coluna) override;
    void descartarFerramenta(int desgaste) override;
};


#endif
