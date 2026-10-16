#include "../../../include/modelo/ferramentas/Adubo.h"
#include "../../../include/modelo/Settings.h"
#include "../../../include/modelo/Solo.h"

Adubo::Adubo(int idSerie) : Ferramenta(TipoFerramenta::Adubo, idSerie) {
    this->desgaste = 0;
    this->descarta = false;
}

void Adubo::usarFerramenta(int linha, int coluna) {

    this->desgaste += Settings::Adubo::dose;


    if (this->desgaste >= Settings::Adubo::capacidade) {
        this->descarta = true;
    }
}

void Adubo::descartarFerramenta(int valorDesgaste) {
    desgaste += valorDesgaste;
    if (desgaste >= Settings::Adubo::capacidade) {
        descarta = true;
    }
}