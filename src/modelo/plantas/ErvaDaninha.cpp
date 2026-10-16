#include "../../../include/modelo/plantas/ErvaDaninha.h"
#include "../../../include/modelo/Solo.h"
#include "../../../include/modelo/Settings.h"

ErvaDaninha::ErvaDaninha() : Planta(TipoPlanta::ErvaDaninha) {
    this->viva = true;
    this->idadePlanta = 0;
    this->crescimentoPlanta = 0;


    this->aguaInterna = Settings::ErvaDaninha::inicial_agua; // 5
    this->nutrientesInternos = Settings::ErvaDaninha::inicial_nutrientes; // 5
}

void ErvaDaninha::crescer(Solo &solo) {
    if (!viva) return;
    idadePlanta++;

    //Morre aos 60 instantes
    if (idadePlanta >= Settings::ErvaDaninha::morre_instantes) {
        this->viva = false;
        return;
    }

    //Absorve 1 de água
    if (solo.getAgua() > 0) {
        solo.retirarAgua(Settings::ErvaDaninha::absorcao_agua);
        this->aguaInterna += Settings::ErvaDaninha::absorcao_agua;
    }

    //Absorve 1 de nutriente e guarda no crescimentoPlanta
    if (solo.getNutrientes() > 0) {
        solo.retirarNutrientes(Settings::ErvaDaninha::absorcao_nutrientes);
        this->crescimentoPlanta += Settings::ErvaDaninha::absorcao_nutrientes;
    }
}

char ErvaDaninha::getSimbolo() const {
    return 'e';
}


void ErvaDaninha::regar(int agua) { if(viva) this->aguaInterna += agua; }
void ErvaDaninha::colher() { this->viva = false; }
void ErvaDaninha::beleza() { }