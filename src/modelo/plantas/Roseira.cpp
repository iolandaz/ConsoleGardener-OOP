#include "../../../include/modelo/plantas/Roseira.h"
#include "../../../include/modelo/Solo.h"
#include "../../../include/modelo/Settings.h"

Roseira::Roseira() : Planta(TipoPlanta::Roseira) {
    this->viva = true;
    this->idadePlanta = 0;
    this->nutrientesInternos = Settings::Roseira::inicial_nutrientes; 
    this->aguaInterna = Settings::Roseira::inicial_agua;             
}

Planta* Roseira::clone() const {
    return new Roseira(*this);
}

char Roseira::getSimbolo() const {
    return 'r';
}

void Roseira::regar(int agua) {
    this->aguaInterna += agua;
}

void Roseira::colher() {
    this->viva = false;
}

void Roseira::beleza() {}

void Roseira::crescer(Solo &solo) {
    if (!viva) return;
    idadePlanta++;

    //Perda de 4 unidades (Metabolismo)
    this->aguaInterna -= Settings::Roseira::perda_agua;
    this->nutrientesInternos -= Settings::Roseira::perda_nutrientes;

    //Absorção (5 água, 8 nutrientes)
    if (solo.getAgua() > 0) {
        int absA = (solo.getAgua() < Settings::Roseira::absorcao_agua) ? solo.getAgua() : Settings::Roseira::absorcao_agua;
        solo.retirarAgua(absA);
        this->aguaInterna += absA;
    }
    if (solo.getNutrientes() > 0) {
        int absN = (solo.getNutrientes() < Settings::Roseira::absorcao_nutrientes) ? solo.getNutrientes() : Settings::Roseira::absorcao_nutrientes;
        solo.retirarNutrientes(absN);
        this->nutrientesInternos += absN;
    }

    // Verificação de MORTE
    //Água <= 0 OU Nutrientes <= 0 OU Nutrientes >= 200
    if (this->aguaInterna <= 0 ||
        this->nutrientesInternos <= Settings::Roseira::morre_nutrientes_menor ||
        this->nutrientesInternos >= Settings::Roseira::morre_nutrientes_maior) {
        this->viva = false;
        }
}