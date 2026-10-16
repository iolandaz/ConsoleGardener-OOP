//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_JARDIM_H
#define TESTE_JARDIM_H

#include "Solo.h"
#include "Jardineiro.h"
#include "plantas/Planta.h"
#include "ferramentas/Ferramenta.h"
#include <vector>

struct FerramentaNoChao {
    Ferramenta* ferramenta;
    int linha;
    int coluna;
};

class Jardim {
private:
    int linhas, colunas;
    Solo** areaJogo;
    std::vector<FerramentaNoChao> ferramentasNoChao;

public:
    Jardim(int l, int c);
    Jardim(const Jardim& outro);
    ~Jardim();

    Solo& getSolo(int l, int c) { return areaJogo[l][c]; }
    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
    char getIcon(int i, int j) const;

    bool posicaoValida(int l, int c) const {
        return l >= 0 && l < linhas && c >= 0 && c < colunas;
    }

    void adicionarFerramenta(Ferramenta* f, int l, int c);
    const std::vector<FerramentaNoChao>& getFerramentasNoChao() const { return ferramentasNoChao; }

    Ferramenta* colherFerramenta(int l, int c);

    void aspirarErvasDaninhas();
    void gerarErvasDaninhas();
    void tentarMultiplicarPlanta(int linha, int coluna);
    bool todosVizinhosOcupados(int l, int c);
    bool tentarMultiplicarRoseira(int l, int c);
    void tentarMultiplicarCacto(int l, int c);
};


#endif