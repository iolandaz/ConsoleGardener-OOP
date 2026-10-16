//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/modelo/ferramentas/Ferramenta.h"


Ferramenta::Ferramenta(TipoFerramenta t, int idSerie)
    : tipo(t), desgaste(0), descarta(false), id(idSerie) {
}

bool Ferramenta::estaDescartada() const {
    return descarta;
}

int Ferramenta::getDesgaste() const {
    return desgaste;
}

std::string Ferramenta::getDetalhes() const {
    std::string nome;
    switch(tipo) {
        case TipoFerramenta::Regador: nome = "Regador"; break;
        case TipoFerramenta::Adubo: nome = "Adubo"; break;
        case TipoFerramenta::Tesoura: nome = "Tesoura"; break;
        case TipoFerramenta::FerramentaZ: nome = "Ferramenta Especial Z"; break;
        default: nome = "Desconhecida";
    }
    return nome + " [ID: " + std::to_string(id) + "] - Desgaste: " + std::to_string(desgaste) + "%";
}
