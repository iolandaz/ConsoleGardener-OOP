//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/modelo/plantas/Planta.h"
#include <string>

using namespace std;


Planta::Planta(TipoPlanta t)
    : tipo(t),
      idadePlanta(0),
      crescimentoPlanta(0),
      viva(true),
      aguaInterna(0)
{
}

string Planta::getBeleza() const {
    if (!viva) {
        return "Morta";
    }
    return "Nivel " + to_string(crescimentoPlanta);
}