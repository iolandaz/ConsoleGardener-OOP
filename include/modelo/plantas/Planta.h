//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_PLANTA_H
#define TESTE_PLANTA_H
#include <string>
#include "TipoPlanta.h"

class Solo;

using namespace std;

enum CategoriaPlanta { FEIA, NEUTRA, BONITA };

class Planta {
protected: // Mudar para protected para os filhos (Roseira, Cacto) acederem
    int idadePlanta;
    int crescimentoPlanta;
    int aguaInterna;
    bool viva;
    TipoPlanta tipo;

public:
    Planta(TipoPlanta t);
    virtual ~Planta(){}


    virtual void crescer(Solo& solo) = 0;

    virtual void regar(int agua) = 0;
    virtual void colher() = 0;
    virtual void beleza() = 0;
    virtual char getSimbolo() const = 0;
    virtual int getNutrientes() const { return crescimentoPlanta; }
    virtual CategoriaPlanta getCategoria() const { return NEUTRA; }
    virtual Planta* clone() const = 0;

    int getAgua() const { return aguaInterna; }
    int getCrescimento() const { return crescimentoPlanta; }
    int getIdade() const { return idadePlanta; }

    void setAguaInterna(int a) { aguaInterna = a; }
    void setCrescimento(int n) { crescimentoPlanta = n; }

    bool estaViva() const { return viva; };
    void setViva(bool v) { viva = v; }

    string getBeleza() const;
    TipoPlanta getTipo() const { return tipo; };
};


#endif
