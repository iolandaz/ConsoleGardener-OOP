//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_CONTROLADOR_H
#define TESTE_CONTROLADOR_H

#include "modelo/Jardim.h"
#include "modelo/Tempo.h"
#include "../modelo/Jardineiro.h"
#include "../interface/Interface.h"
#include <map>
#include <string>

class Controlador {
    Jardim* jardim = nullptr;
    Jardineiro jardineiro;
    Interface interface;
    Tempo tempo;

    std::map<std::string, Jardim*> copiasSeguranca;


    int plantasPlantadasNesteTurno = 0;
    int colheitasNesteTurno = 0;
    int movimentosNesteTurno = 0;
    int entradasNesteTurno = 0;
    int saidasNesteTurno = 0;
    int proximoIdFerramenta = 100;

public:
    Controlador() = default;
    ~Controlador();

    void run();
    void criarJardim(int linhas, int colunas);
    void avancarTempo(int n);

    void plantar(int l, int c, char tipoChar);
    void listarPlantas();
    void detalhesPlanta(int l, int c);
    void listarAreaOcupada();
    void colher(int l, int c);
    void listarSolo(int l, int c, int raio);
    void moverJardineiro(char direcao);
    void entrarNoJardim(int l, int c);
    void sairDoJardim();
    void verificarEColherFerramenta();
    void comprarFerramenta(char tipo);
    int gerarNovoId() { return proximoIdFerramenta++; }
    void aplicarAdubo();
    void usarAspirador();

    void gravarJardim(const std::string& nome);
    void recuperarJardim(const std::string& nome);
    void apagarGrava(const std::string& nome);
    void processarLinhaComando(const std::string& linha);

    // Getters necessários para a interface e comandos
    Jardim* getJardim() { return jardim; }
    Jardineiro& getJardineiro() { return jardineiro; }
    Interface& getInterface() { return interface; }
};


#endif
