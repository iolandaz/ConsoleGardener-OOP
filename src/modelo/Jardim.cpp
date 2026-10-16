//
// Created by Utilizador on 25/10/2025.
//

#include "../../include/modelo/Jardim.h"
#include "../../include/modelo/plantas/ErvaDaninha.h"
#include "../../include/modelo/Settings.h"
#include "../../include/modelo/plantas/Roseira.h"
#include "../../include/modelo/plantas/Cacto.h"
#include <cstdlib> // Para o rand()

Jardim::Jardim(int l, int c) : linhas(l), colunas(c) {

    areaJogo = new Solo*[linhas];
    for (int i = 0; i < linhas; i++) {
        areaJogo[i] = new Solo[colunas];
    }
}

Jardim::Jardim(const Jardim& outro) {
    this->linhas = outro.linhas;
    this->colunas = outro.colunas;
    this->ferramentasNoChao = outro.ferramentasNoChao;


    areaJogo = new Solo*[linhas];
    for (int i = 0; i < linhas; i++) {
        areaJogo[i] = new Solo[colunas];
        for (int j = 0; j < colunas; j++) {

            areaJogo[i][j].adicionarAgua(outro.areaJogo[i][j].getAgua());
            areaJogo[i][j].adicionarNutrientes(outro.areaJogo[i][j].getNutrientes());


            if (outro.areaJogo[i][j].temPlanta()) {
                areaJogo[i][j].setPlanta(outro.areaJogo[i][j].getPlanta()->clone());
            }
        }
    }
}


char Jardim::getIcon(int i, int j) const {

    for (const auto& f : ferramentasNoChao) {
        if (f.linha == i && f.coluna == j) {
            return toupper(toCharFerramenta(f.ferramenta->getTipoFerramenta()));
        }
    }

    if (areaJogo[i][j].temPlanta())
        return areaJogo[i][j].getPlanta()->getSimbolo();

    return '-';
}

Jardim::~Jardim() {
    for (int i = 0; i < linhas; i++) {
        delete[] areaJogo[i];
    }
    delete[] areaJogo;
}

void Jardim::adicionarFerramenta(Ferramenta* f, int l, int c) {
    if (f == nullptr) return;
    ferramentasNoChao.push_back({f, l, c});
}

Ferramenta* Jardim::colherFerramenta(int l, int c) {
    for (auto it = ferramentasNoChao.begin(); it != ferramentasNoChao.end(); ++it) {
        if (it->linha == l && it->coluna == c) {
            Ferramenta* f = it->ferramenta;
            ferramentasNoChao.erase(it);
            return f;
        }
    }
    return nullptr;
}

void Jardim::aspirarErvasDaninhas() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (areaJogo[i][j].temPlanta()) {
                // Se for Erva Daninha, removemos
                if (areaJogo[i][j].getPlanta()->getTipo() == TipoPlanta::ErvaDaninha) {
                    areaJogo[i][j].removerPlanta();
                }
            }
        }
    }
}

void Jardim::gerarErvasDaninhas() {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            Solo& solo = areaJogo[i][j];

            if (solo.temPlanta() && solo.getPlanta()->getTipo() == TipoPlanta::ErvaDaninha) {
                ErvaDaninha* ed = static_cast<ErvaDaninha*>(solo.getPlanta());


                ed->incrementarContador();

                // Verifica se tem > 30 nutrientes e se passaram 5 instantes
                if (ed->getCrescimento() > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
                    ed->getContador() >= Settings::ErvaDaninha::multiplica_instantes) {

                    // Tenta vizinhos: Norte, Sul, Este, Oeste
                    int dl[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dl[k];
                        int nj = j + dc[k];

                        if (posicaoValida(ni, nj)) {

                            areaJogo[ni][nj].removerPlanta();


                            areaJogo[ni][nj].setPlanta(new ErvaDaninha());


                            ed->resetContador();
                            break;
                        }
                    }
                    }
            }
        }
    }
}

void Jardim::tentarMultiplicarPlanta(int l, int c) {
    Planta* original = areaJogo[l][c].getPlanta();
    if (original == nullptr) return;

    // Vetores de direção para vizinhos (Cima, Baixo, Esquerda, Direita)
    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nl = l + dl[i];
        int nc = c + dc[i];

        if (posicaoValida(nl, nc) && !areaJogo[nl][nc].temPlanta()) {

            Planta* novo = original->clone();


            areaJogo[nl][nc].setPlanta(novo);

            return;
        }
    }
}

bool Jardim::todosVizinhosOcupados(int l, int c) {
    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int ocupados = 0;
    int validos = 0;

    for (int i = 0; i < 4; i++) {
        if (posicaoValida(l + dl[i], c + dc[i])) {
            validos++;
            if (areaJogo[l + dl[i]][c + dc[i]].temPlanta()) ocupados++;
        }
    }

    return (ocupados == validos && validos > 0);
}

bool Jardim::tentarMultiplicarRoseira(int l, int c) {
    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nl = l + dl[i], nc = c + dc[i];
        if (posicaoValida(nl, nc) && !areaJogo[nl][nc].temPlanta()) {
            Roseira* mae = static_cast<Roseira*>(areaJogo[l][c].getPlanta());

            Roseira* filha = new Roseira();
            filha->setNutrientes(Settings::Roseira::nova_nutrientes); // 25
            filha->setAgua(mae->getAgua() / 2); // Metade da água da mãe

            areaJogo[nl][nc].setPlanta(filha);
            return true;
        }
    }
    return false;
}

void Jardim::tentarMultiplicarCacto(int l, int c) {
    Planta* original = areaJogo[l][c].getPlanta();

    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nl = l + dl[i];
        int nc = c + dc[i];

        if (posicaoValida(nl, nc) && !areaJogo[nl][nc].temPlanta()) {
            Planta* novo = original->clone(); // Cria cópia

            // Divisão simples de recursos
            int metadeAgua = original->getAgua() / 2;
            int metadeNutri = original->getCrescimento() / 2;

            // Precisas de ter estes métodos no Cacto ou na Planta:
            original->setAguaInterna(metadeAgua);
            original->setCrescimento(metadeNutri);

            novo->setAguaInterna(metadeAgua);
            novo->setCrescimento(metadeNutri);

            areaJogo[nl][nc].setPlanta(novo);
            break;
        }
    }
}
