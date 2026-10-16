//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_CACTO_H
#define TESTE_CACTO_H

#include "Planta.h"
#include "../Settings.h"

class Solo;

class Cacto : public Planta {
    int instantesComMuitaAgua; // Para controlar a regra de morte por excesso de água
    int instantesSemNutrientes;

public:
    Cacto();
    Planta* clone() const override;


    void crescer(Solo &solo) override;
    void multiplicar(Solo &solo);

    void regar(int agua) override;
    void colher() override;
    void beleza() override;
    char getSimbolo() const override;
};


#endif
