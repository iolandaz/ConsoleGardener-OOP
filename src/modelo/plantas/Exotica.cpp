#include "../../../include/modelo/plantas/Exotica.h"
#include "../../../include/modelo/Solo.h"

Exotica::Exotica() : Planta(TipoPlanta::Exotica) {
    this->viva = true;
    this->idadePlanta = 0;
    this->aguaInterna = 50;
    this->nutrientesInternos = 50;
}

void Exotica::crescer(Solo &solo) {
    if (!viva) return;
    idadePlanta++;

    // Perda constante por instante
    this->aguaInterna -= 8;
    this->nutrientesInternos -= 8;


    int soloAgua = solo.getAgua();
    int absAgua = (soloAgua < 10) ? soloAgua : 10;
    solo.retirarAgua(absAgua);
    this->aguaInterna += absAgua;

    int soloNutri = solo.getNutrientes();
    int absNutri = (soloNutri < 10) ? soloNutri : 10;
    solo.retirarNutrientes(absNutri);
    this->nutrientesInternos += absNutri;

    //Condições de Morte
    if (this->aguaInterna <= 0 || this->nutrientesInternos <= 0 || this->aguaInterna >= 200) {
        this->viva = false;
    }
}

void Exotica::regar(int agua) { this->aguaInterna += agua; }
void Exotica::colher() { this->viva = false; }
void Exotica::beleza() {}