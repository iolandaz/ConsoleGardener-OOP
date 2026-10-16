//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_REGADOR_H
#define TESTE_REGADOR_H

#include "Ferramenta.h"

class Regador : public Ferramenta {
    int aguaAtual;
public:
    Regador(int idSerie);
    void usarFerramenta(int linha, int coluna) override;
    void descartarFerramenta(int desgaste) override;

    int getAgua() const { return aguaAtual; }
};


#endif
