//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_ERVADANINHA_H
#define TESTE_ERVADANINHA_H

#include "Planta.h"
#include "../Settings.h"

class Solo;

class ErvaDaninha : public Planta {
    int nutrientesInternos;
    int contadorInstantes;

public:
    ErvaDaninha();

    CategoriaPlanta getCategoria() const override { return FEIA; }

    void incrementarContador() { contadorInstantes++; }
    void resetContador() { contadorInstantes = 0; }
    int getContador() const { return contadorInstantes; }

    void crescer(Solo &solo) override;
    void regar(int agua) override;
    void colher() override;
    void beleza() override;
    char getSimbolo() const override;
    Planta* clone() const override { return new ErvaDaninha(*this); }
};


#endif 
