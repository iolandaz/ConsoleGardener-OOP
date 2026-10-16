//
// Created by Utilizador on 25/10/2025.
//

#include "../../include/modelo/Jardineiro.h"
#include "../../include/modelo/ferramentas/Ferramenta.h"
#include <iostream>

using namespace std;


Jardineiro::Jardineiro()
    : linha(-1), coluna(-1), energia(10), ferramentaAtual(nullptr) {

}


Jardineiro::~Jardineiro() {
    for (Ferramenta* f : inventario) {
        delete f;
    }
    inventario.clear();
}

void Jardineiro::mover(char direcao, int maxLinhas, int maxColunas) {

    if (linha == -1 || coluna == -1) return;

    int novaL = linha;
    int novaC = coluna;

    if (direcao == 'c') novaL--;
    else if (direcao == 'b') novaL++;
    else if (direcao == 'e') novaC--;
    else if (direcao == 'd') novaC++;

    // Verifica se a nova posição é válida dentro dos limites do jardim
    if (novaL >= 0 && novaL < maxLinhas && novaC >= 0 && novaC < maxColunas) {
        linha = novaL;
        coluna = novaC;
    }
}

void Jardineiro::setPosicao(int l, int c) {
    linha = l;
    coluna = c;
}

void Jardineiro::adicionarFerramenta(Ferramenta* ferramenta) {
    if (ferramenta == nullptr) return;

    inventario.push_back(ferramenta);

    // Se o jardineiro não tiver nenhuma ferramenta na mão,
    // a que acabou de apanhar torna-se a ativa.
    if (ferramentaAtual == nullptr) {
        ferramentaAtual = ferramenta;
    }
}

void Jardineiro::trocarFerramenta(int id) {
    for (Ferramenta* f : inventario) {
        if (f->getID() == id) {
            ferramentaAtual = f;
            return;
        }
    }
}

void Jardineiro::usarFerramenta() {
    if (ferramentaAtual == nullptr) {
        return;
    }


    ferramentaAtual->usarFerramenta(linha, coluna);
}

void Jardineiro::largarFerramentaDaMao() {
    this->ferramentaAtual = nullptr;
}

void Jardineiro::removerFerramenta(int idRemover) {
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if ((*it)->getID() == idRemover) {
            if (ferramentaAtual == *it) ferramentaAtual = nullptr;
            delete *it; // Libertar memória
            inventario.erase(it);
            return;
        }
    }
}

// Getters
int Jardineiro::getLinha() const { return linha; }
int Jardineiro::getColuna() const { return coluna; }
int Jardineiro::getEnergia() const { return energia; }
Ferramenta* Jardineiro::getFerramentaAtual() const { return ferramentaAtual; }

const std::vector<Ferramenta*>& Jardineiro::getInventario() const {
    return inventario;
}
