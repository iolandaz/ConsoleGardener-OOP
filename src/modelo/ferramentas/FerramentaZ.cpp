#include "../../../include/modelo/ferramentas/FerramentaZ.h"
#include "../../../include/modelo/Jardim.h"

FerramentaZ::FerramentaZ(int idSerie) : Ferramenta(TipoFerramenta::FerramentaZ, idSerie) {

    this->desgaste = 0;
    this->descarta = false;
}

void FerramentaZ::usarFerramenta(int linha, int coluna) {
    // Uso único: ao usar, o desgaste vai para o máximo
    this->desgaste = 100;
    this->descarta = true; 
}

void FerramentaZ::descartarFerramenta(int valorDesgaste) {
    this->desgaste = 100;
    this->descarta = true;
}