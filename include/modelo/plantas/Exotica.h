#ifndef TESTE_EXOTICA_H
#define TESTE_EXOTICA_H

#include "Planta.h"

class Solo;

class Exotica : public Planta {
    int nutrientesInternos;
public:
    Exotica();


    void crescer(Solo &solo) override;
    void regar(int agua) override;
    void colher() override;
    void beleza() override;
    char getSimbolo() const override { return 'x'; }
    Planta* clone() const override { return new Exotica(*this); }
    
    // Getters necessários para a lógica de morte
    int getNutrientesInternos() const { return nutrientesInternos; }
};

#endif