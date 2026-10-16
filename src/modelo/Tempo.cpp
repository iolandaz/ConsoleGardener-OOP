//
// Created by Utilizador on 05/12/2025.
//

#include "modelo/Tempo.h"

Tempo::Tempo() : instanteAtual(0) {}

void Tempo::avanca(int n) {
    if (n > 0) {
        instanteAtual += n;
    }
}

int Tempo::getInstante() const {
    return instanteAtual;
}

void Tempo::reinicia() {
    instanteAtual = 0;
}
