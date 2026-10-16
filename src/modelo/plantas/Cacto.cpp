#include "../../../include/modelo/plantas/Cacto.h"
#include "../../../include/modelo/Solo.h"
#include "../../../include/modelo/Settings.h"


Cacto::Cacto() : Planta(TipoPlanta::Cacto), instantesComMuitaAgua(0) {
    this->viva = true;
    this->idadePlanta = 0;
    this->crescimentoPlanta = 0;
    this->aguaInterna = 10;
}


Planta* Cacto::clone() const {
    return new Cacto(*this);
}


char Cacto::getSimbolo() const {
    return 'c';
}

void Cacto::regar(int agua) {

    this->aguaInterna += agua;
}


void Cacto::colher() {
    this->viva = false;
}

void Cacto::beleza() {

}


void Cacto::crescer(Solo &solo) {
    if (!viva) return;
    idadePlanta++;


    int aguaNoSolo = solo.getAgua();
    int absAgua = (aguaNoSolo * Settings::Cacto::absorcao_agua_percentagem) / 100;
    solo.retirarAgua(absAgua);
    this->aguaInterna += absAgua;

    int nNoSolo = solo.getNutrientes();
    int absNutri = (nNoSolo < Settings::Cacto::absorcao_nutrientes) ? nNoSolo : Settings::Cacto::absorcao_nutrientes;
    solo.retirarNutrientes(absNutri);
    this->crescimentoPlanta += absNutri;


    if (solo.getAgua() > Settings::Cacto::morre_agua_solo_maior) {
        instantesComMuitaAgua++;
    } else {
        instantesComMuitaAgua = 0;
    }


    if (solo.getNutrientes() <= 0) {
        instantesSemNutrientes++;
    } else {
        instantesSemNutrientes = 0;
    }


    if (instantesComMuitaAgua >= 3 || instantesSemNutrientes > 3) {
        viva = false;
    }
}