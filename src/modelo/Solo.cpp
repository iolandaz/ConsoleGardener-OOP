#include "../../include/modelo/Solo.h"
#include "../../include/modelo/Jardim.h"
#include "../../include/modelo/plantas/ErvaDaninha.h"
#include <cstdlib>

Solo::Solo() {

    this->agua = Settings::Jardim::agua_min +
                 (rand() % (Settings::Jardim::agua_max - Settings::Jardim::agua_min + 1));

    this->nutrientes = Settings::Jardim::nutrientes_min +
                       (rand() % (Settings::Jardim::nutrientes_max - Settings::Jardim::nutrientes_min + 1));
}

Solo::~Solo() {
    delete planta;
}

void Solo::adicionarAgua(int qtd) {
    agua += qtd;

}

void Solo::adicionarNutrientes(int qtd) {
    nutrientes += qtd;
}

void Solo::retirarAgua(int qtd) {
    agua -= qtd;
    if (agua < 0) agua = 0;
}

void Solo::retirarNutrientes(int qtd) {
    nutrientes -= qtd;
    if (nutrientes < 0) nutrientes = 0;
}

void Solo::removerPlanta() {
    if (planta != nullptr) {
        delete planta;
        planta = nullptr;
    }
}

void Solo::processaTurno(Jardim& j, int l, int c) {
    if (planta == nullptr) return;

    //A planta cresce (consome água/nutrientes do solo e atualiza estado)
    planta->crescer(*this);


    if (!planta->estaViva()) {


        if (planta->getTipo() == TipoPlanta::Cacto) {

            this->adicionarNutrientes(planta->getCrescimento());
        }

        // Exótica morre
        if (planta->getTipo() == TipoPlanta::Exotica) {
            int dl[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int nl = l + dl[i];
                int nc = c + dc[i];
                if (j.posicaoValida(nl, nc)) {
                    // Limpa o vizinho e gera uma Erva Daninha
                    j.getSolo(nl, nc).removerPlanta();
                    j.getSolo(nl, nc).setPlanta(new ErvaDaninha());
                }
            }
        }

        // Remove a planta morta deste solo
        removerPlanta();
        return;
    }



    // Regra do Cacto: Nutrientes > 100 e Água > 50
    if (planta->getTipo() == TipoPlanta::Cacto) {
        if (planta->getCrescimento() > 100 && planta->getAgua() > 50) {
            j.tentarMultiplicarCacto(l, c);
        }
    }

    // Regra da Roseira (se já a tiveres implementada no Jardim)
    if (planta->getTipo() == TipoPlanta::Roseira) {
        if (planta->getCrescimento() > 100) {
            j.tentarMultiplicarRoseira(l, c);
        }
    }
}