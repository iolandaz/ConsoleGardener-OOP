//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_JARDINEIRO_H
#define TESTE_JARDINEIRO_H

#include "../modelo/ferramentas/Ferramenta.h"
#include <vector>


class Jardineiro {
    int linha, coluna;
    int energia;
    std::vector<Ferramenta*> inventario;
    Ferramenta* ferramentaAtual;

public:
    Jardineiro();
    ~Jardineiro();

    void mover(char direcao, int maxLinhas, int maxColunas);
    void setPosicao(int l, int c);
    void usarFerramenta();
    void adicionarFerramenta(Ferramenta* ferramenta);
    void trocarFerramenta(int id);
    void largarFerramentaDaMao();
    void removerFerramenta(int id);

    int getLinha() const;
    int getColuna() const;
    int getEnergia() const;
    Ferramenta* getFerramentaAtual() const;
    const std::vector<Ferramenta*>& getInventario() const;
};


#endif
