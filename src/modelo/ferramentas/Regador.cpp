//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/modelo/ferramentas/Regador.h"
#include "../../../include/modelo/Settings.h"

Regador::Regador(int idSerie)
    : Ferramenta(TipoFerramenta::Regador, idSerie),
      aguaAtual(Settings::Regador::capacidade) { // Inicia com 200
}

void Regador::usarFerramenta(int linha, int coluna) {
    // Reduz a água pela dose (10)
    aguaAtual -= Settings::Regador::dose;

    desgaste += 5;

    // Se a água acabar, a ferramenta "sai do simulador" (descarta)
    if (aguaAtual <= 0) {
        aguaAtual = 0;
        descarta = true;
    }
}

void Regador::descartarFerramenta(int valorDesgaste) {
    // Para o regador, o "desgaste" é a falta de água neste contexto
    descarta = true;
}