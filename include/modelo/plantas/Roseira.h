//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_ROSEIRA_H
#define TESTE_ROSEIRA_H

#include "Planta.h"
#include "../Settings.h"

class Solo;

class Roseira : public Planta {
    int nutrientesInternos;
    int flores;

public:
    Roseira();
    Planta* clone() const override;

    CategoriaPlanta getCategoria() const override { return BONITA; }

    int getNutrientes() const override { return nutrientesInternos; }


    void crescer(Solo &solo) override;
    void regar(int agua) override;
    void colher() override;
    void beleza() override;
    char getSimbolo() const override;

    void setNutrientes(int n) { nutrientesInternos = n; }
    void setAgua(int a) { aguaInterna = a; }
    int getNutrientesInternos() const { return nutrientesInternos; }
};


#endif
