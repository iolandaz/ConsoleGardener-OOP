//
// Created by Utilizador on 25/10/2025.
//

#include "../../include/controlador/Controlador.h"
#include "../../include/interface/comandos/ComandoCriarJardim.h"
#include "../../include/interface/comandos/ComandoApaga.h"
#include "../../include/interface/comandos/ComandoGrava.h"
#include "../../include/interface/comandos/ComandoRecupera.h"
#include "../../include/interface/comandos/ComandoExecuta.h"
#include "../../include/interface/comandos/ComandoAvanca.h"
#include "../../include/interface/comandos/ComandoPlanta.h"
#include "../../include/interface/comandos/ComandoColhe.h"
#include "../../include/interface/comandos/ComandoLarga.h"
#include "../../include/interface/comandos/ComandoPega.h"
#include "../../include/interface/comandos/ComandoCompra.h"
#include "../../include/interface/comandos/ComandoListaFerramentas.h"
#include "../../include/interface/comandos/ComandoListaPlanta.h"
#include "../../include/interface/comandos/ComandoListaPlantas.h"
#include "../../include/interface/comandos/ComandoListaArea.h"
#include "../../include/interface/comandos/ComandoListaSolo.h"
#include "../../include/interface/comandos/ComandoEntra.h"
#include "../../include/interface/comandos/ComandoSai.h"
#include "../../include/interface/comandos/ComandoMovimentoCima.h"
#include "../../include/interface/comandos/ComandoMovimentoBaixo.h"
#include "../../include/interface/comandos/ComandoMovimentoDireita.h"
#include "../../include/interface/comandos/ComandoMovimentoEsquerda.h"
#include "../../include/modelo/Jardim.h"
#include "../../include/modelo/plantas/Roseira.h"
#include "../../include/modelo/plantas/Cacto.h"
#include "../../include/modelo/plantas/Exotica.h"
#include "../../include/modelo/plantas/ErvaDaninha.h"
#include "../../include/modelo/ferramentas/Regador.h"
#include "../../include/modelo/ferramentas/Adubo.h"
#include "../../include/modelo/ferramentas/Tesoura.h"
#include "../../include/modelo/ferramentas/FerramentaZ.h"
#include <sstream>
#include <iostream>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()

using namespace std;

Controlador::~Controlador() {
    if (jardim != nullptr) {
        delete jardim;
    }
    // Limpar todas as cópias de segurança (RAM)
    for (auto const& [nome, copia] : copiasSeguranca) {
        delete copia;
    }
    copiasSeguranca.clear();
}

void Controlador::run() {
    while (true) {
        interface.mostraTexto();
        string linha = interface.leLinha();

        if (linha == "fim") break;

        // Agora chamamos o processador centralizado
        processarLinhaComando(linha);
    }
}

void Controlador::processarLinhaComando(const string& linha) {
    if (linha.empty()) return;
        string comando;
        istringstream iss(linha);
        iss >> comando;

        if (comando == "jardim") {
            int l, c;
            iss >> l >> c;
            ComandoCriarJardim cmd(l, c);
            if (cmd.validaComando() && jardim == nullptr){
                criarJardim(l, c);
            }
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "apaga") {
            ComandoApaga cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "grava") {
            ComandoGrava cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "recupera") {
            ComandoRecupera cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "executa") {
            ComandoExecuta cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "avanca") {
            ComandoAvanca cmd(linha);
            if (cmd.validaComando()) {
                this->avancarTempo(cmd.getInstantes());
            } else {
                interface.mostraErro(cmd.getErro());
            }
        } else if (comando == "planta") {
            ComandoPlanta cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "colhe") {
            ComandoColhe cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "larga") {
            ComandoLarga cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "pega") {
            ComandoPega cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "compra") {
            ComandoCompra cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "lferr") {
            ComandoLferr cmd(linha, *this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "lplanta") {
            ComandoListaPlanta cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "lplantas") {
            ComandoListaPlantas cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "larea") {
            ComandoListaArea cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "lsolo") {
            ComandoListaSolo cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "entra") {
            ComandoEntra cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "sai") {
            ComandoSai cmd(linha,this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "b") {
            ComandoBaixo cmd(linha,this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "c") {
            ComandoCima cmd(linha,this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "d") {
            ComandoDireita cmd(linha, this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else if (comando == "e") {
            ComandoEsquerda cmd(linha,this);
            if (cmd.validaComando()) cmd.executaComando();
            else interface.mostraErro(cmd.getErro());
        } else {
            interface.mostraErro("Comando invalido!");
        }
}

void Controlador::criarJardim(int linhas, int colunas) {
    if (jardim != nullptr) delete jardim;

    jardim = new Jardim(linhas, colunas);
    srand(static_cast<unsigned int>(time(NULL))); // Inicializa semente aleatória

    int proximoID = 1;

    for (int i = 0; i < 3; i++) {
        int l = rand() % linhas;
        int c = rand() % colunas;

        // Sorteia o tipo
        int tipo = rand() % 4;
        Ferramenta* novaF = nullptr;

        if (tipo == 0) novaF = new Regador(proximoID++);
        else if (tipo == 1) novaF = new Adubo(proximoID++);
        else if (tipo == 2) novaF = new Tesoura(proximoID++);
        else novaF = new FerramentaZ(proximoID++);

        jardim->adicionarFerramenta(novaF, l, c);
    }
    jardineiro.setPosicao(0, 0);

    interface.mostraJardim(*jardim, tempo.getInstante(), 0, 0);
}

void Controlador::avancarTempo(int n) {
    if (jardim == nullptr) {
        interface.mostraErro("Nao existe um jardim criado!");
        return;
    }


    plantasPlantadasNesteTurno = 0;
    colheitasNesteTurno = 0;
    movimentosNesteTurno = 0;
    entradasNesteTurno = 0;
    saidasNesteTurno = 0;

    for (int i = 0; i < n; i++) {
        tempo.avanca();


        // Verifica se o jardineiro está no jardim e tem o aspirador no inventário
        int l_jard = jardineiro.getLinha();
        int c_jard = jardineiro.getColuna();

        if (l_jard != -1 && c_jard != -1) {
            const std::vector<Ferramenta*>& inv = jardineiro.getInventario();
            Ferramenta* aspirador = nullptr;

            for (Ferramenta* f : inv) {
                if (f->getTipoFerramenta() == TipoFerramenta::FerramentaZ) {
                    aspirador = f;
                    break;
                }
            }

            if (aspirador != nullptr) {

                jardim->aspirarErvasDaninhas();


                aspirador->usarFerramenta(l_jard, c_jard);
                jardineiro.removerFerramenta(aspirador->getID());

                interface.mostraMensagem("AUTOMÁTICO: O Aspirador detetou ervas, limpou o jardim e avariou!");
            }
        }



        jardim->gerarErvasDaninhas();


        Ferramenta* naMao = jardineiro.getFerramentaAtual();

        if (naMao != nullptr && l_jard != -1 && c_jard != -1) {
            Solo& soloLocal = jardim->getSolo(l_jard, c_jard);
            TipoFerramenta tipoF = naMao->getTipoFerramenta();

            if (tipoF == TipoFerramenta::Regador) {
                soloLocal.adicionarAgua(Settings::Regador::dose);
                naMao->usarFerramenta(l_jard, c_jard);

                if (naMao->estaDescartada()) {
                    interface.mostraMensagem("O regador ficou vazio e foi descartado!");
                    jardineiro.removerFerramenta(naMao->getID());
                }
            }
            else if (tipoF == TipoFerramenta::Tesoura) {
                if (soloLocal.temPlanta()) {
                    Planta* p = soloLocal.getPlanta();
                    if (p->getCategoria() == FEIA || (p->getCrescimento() <= 0 && p->getCategoria() != BONITA)) {
                        soloLocal.removerPlanta();
                        interface.mostraMensagem("A tesoura limpou o que nao era bonito ou estava morto.");
                    }
                }
            }
            else if (tipoF == TipoFerramenta::Adubo) {
                soloLocal.adicionarNutrientes(Settings::Adubo::dose);
                naMao->usarFerramenta(l_jard, c_jard);

                if (naMao->estaDescartada()) {
                    interface.mostraMensagem("O pacote de adubo acabou!");
                    jardineiro.removerFerramenta(naMao->getID());
                }
            }
        }


        for (int l = 0; l < jardim->getLinhas(); l++) {
            for (int c = 0; c < jardim->getColunas(); c++) {
                jardim->getSolo(l, c).processaTurno(*jardim, l, c);
            }
        }
    }


    interface.mostraMensagem("Tempo avancado " + to_string(n) + " instantes.");
    interface.mostraJardim(*jardim, tempo.getInstante(), jardineiro.getLinha(), jardineiro.getColuna());
}

void Controlador::plantar(int l, int c, char tipoChar) {
    if (jardim == nullptr) {
        interface.mostraErro("Erro: Jardim nao existe.");
        return;
    }

    if (plantasPlantadasNesteTurno >= Settings::Jardineiro::max_plantacoes) {
        interface.mostraErro("Limite de plantacoes atingido este turno!");
        return;
    }

    if (!jardim->posicaoValida(l, c)) {
        interface.mostraErro("Posicao fora do jardim!");
        return;
    }

    Solo& solo = jardim->getSolo(l, c);
    if (solo.temPlanta()) {
        interface.mostraErro("Ja existe uma planta nessa posicao!");
        return;
    }

    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nl = l + dl[i];
        int nc = c + dc[i];
        if (jardim->posicaoValida(nl, nc)) {
            Solo& vizinho = jardim->getSolo(nl, nc);
            if (vizinho.temPlanta() && vizinho.getPlanta()->getTipo() == TipoPlanta::Exotica) {
                interface.mostraErro("Nao podes plantar aqui! Esta na zona de exclusao de um Eucalipto.");
                return;
            }
        }
    }
    // --------------------------------------------------

    Planta* nova = nullptr;
    switch (tolower(tipoChar)) {
        case 'r': nova = new Roseira(); break;
        case 'c': nova = new Cacto(); break;
        case 'e': nova = new ErvaDaninha(); break;
        case 'x': nova = new Exotica(); break; // Ativado para a classe Exotica
    }

    if (nova != nullptr) {
        solo.setPlanta(nova);
        plantasPlantadasNesteTurno++;
        interface.mostraMensagem("Planta colocada!");
        interface.mostraJardim(*jardim, tempo.getInstante(), jardineiro.getLinha(), jardineiro.getColuna());
    }
}

void Controlador::listarPlantas() {
    if (jardim == nullptr) {
        interface.mostraErro("Jardim não existe!");
        return;
    }

    cout << "\n--- LISTAGEM DE PLANTAS ---" << endl;
    bool encontrou = false;

    for (int l = 0; l < jardim->getLinhas(); l++) {
        for (int c = 0; c < jardim->getColunas(); c++) {
            Solo& solo = jardim->getSolo(l, c);
            if (solo.temPlanta()) {
                encontrou = true;
                Planta* p = solo.getPlanta();
                char coordL = 'a' + l;
                char coordC = 'a' + c;

                cout << "[" << coordL << coordC << "] "
                     << "Tipo: " << p->getSimbolo()
                     << " | Vida: " << (p->estaViva() ? "Sim" : "Não")
                     << " | Água: " << p->getAgua()
                     << " | Solo: (A:" << solo.getAgua() << "/N:" << solo.getNutrientes() << ")"
                     << endl;
            }
        }
    }

    if (!encontrou) cout << "Não existem plantas no jardim." << endl;
    cout << "---------------------------\n" << endl;
}

void Controlador::detalhesPlanta(int l, int c) {
    if (jardim == nullptr) {
        interface.mostraErro("Jardim nao existe!");
        return;
    }

    if (!jardim->posicaoValida(l, c)) {
        interface.mostraErro("Coordenadas fora do jardim!");
        return;
    }

    Solo& solo = jardim->getSolo(l, c);

    cout << "\n=== DETALHES DA POSICAO [" << (char)('a'+l) << (char)('a'+c) << "] ===" << endl;
    cout << "SOLO:" << endl;
    cout << "  - Agua: " << solo.getAgua() << endl;
    cout << "  - Nutrientes: " << solo.getNutrientes() << endl;

    if (solo.temPlanta()) {
        Planta* p = solo.getPlanta();
        cout << "PLANTA:" << endl;
        cout << "  - Tipo: " << p->getSimbolo() << endl;
        cout << "  - Estado: " << (p->estaViva() ? "Viva" : "Morta") << endl;
        cout << "  - Idade: " << p->getIdade() << " turnos" << endl;
        cout << "  - Agua Interna: " << p->getAgua() << endl;
        cout << "  - Crescimento/Beleza: " << p->getCrescimento() << endl;
    } else {
        cout << "PLANTA: (Nao existe nenhuma planta nesta posicao)" << endl;
    }
    cout << "===============================\n" << endl;
}

void Controlador::listarAreaOcupada() {
    if (jardim == nullptr) {
        interface.mostraErro("Jardim nao existe!");
        return;
    }

    bool encontrouAlguma = false;
    cout << "\n--- AREAS OCUPADAS DO JARDIM ---" << endl;

    for (int l = 0; l < jardim->getLinhas(); l++) {
        for (int c = 0; c < jardim->getColunas(); c++) {
            Solo& solo = jardim->getSolo(l, c);


            if (solo.temPlanta()) {
                encontrouAlguma = true;
                Planta* p = solo.getPlanta();

                cout << "[" << (char)('a' + l) << (char)('a' + c) << "] "
                     << "Planta: " << p->getSimbolo()
                     << " (Agua: " << p->getAgua() << ")"
                     << " | Solo: (A:" << solo.getAgua() << "/N:" << solo.getNutrientes() << ")"
                     << endl;
            }
        }
    }

    if (!encontrouAlguma) {
        cout << "O jardim esta totalmente vazio de plantas." << endl;
    }
    cout << "---------------------------------\n" << endl;
}

void Controlador::colher(int l, int c) {
    if (jardim == nullptr) return;


    if (colheitasNesteTurno >= 5) {
        interface.mostraErro("Limite de 5 colheitas por turno atingido!");
        return;
    }

    if (!jardim->posicaoValida(l, c)) {
        interface.mostraErro("Posicao inexistente!");
        return;
    }

    Solo& solo = jardim->getSolo(l, c);


    if (!solo.temPlanta()) {
        interface.mostraErro("Nao existe nenhuma planta nesta posicao.");
        return;
    }


    solo.getPlanta()->colher();

    delete solo.getPlanta();
    solo.setPlanta(nullptr);

    colheitasNesteTurno++;
    interface.mostraMensagem("Planta colhida com sucesso!");


    interface.mostraJardim(*jardim, tempo.getInstante(), jardineiro.getLinha(), jardineiro.getColuna());
}

void Controlador::listarSolo(int lCentro, int cCentro, int raio) {
    if (jardim == nullptr) return;

    interface.mostraJardim(*jardim, tempo.getInstante(), jardineiro.getLinha(), jardineiro.getColuna());
    cout << "\n=== INFORMACOES DO SOLO (Raio: " << raio << ") ===" << endl;


    int lInicio = lCentro - raio;
    int lFim = lCentro + raio;
    int cInicio = cCentro - raio;
    int cFim = cCentro + raio;

    bool encontrouAlgo = false;

    for (int l = lInicio; l <= lFim; l++) {
        for (int c = cInicio; c <= cFim; c++) {


            if (jardim->posicaoValida(l, c)) {
                encontrouAlgo = true;
                Solo& solo = jardim->getSolo(l, c);

                cout << "[" << (char)('a' + l) << (char)('a' + c) << "] "
                     << "Agua: " << solo.getAgua()
                     << " | Nutrientes: " << solo.getNutrientes();

                if (solo.temPlanta()) {
                    cout << " | Planta: " << solo.getPlanta()->getSimbolo()
                         << " (Vida: " << solo.getPlanta()->getAgua() << ")";
                } else {
                    cout << " | (Vazio)";
                }
                cout << endl;
            }
        }
    }

    if (!encontrouAlgo) {
        interface.mostraErro("Nenhuma posicao valida encontrada nesse raio!");
    }
    cout << "===============================================\n" << endl;
}

void Controlador::moverJardineiro(char direcao) {
    if (jardim == nullptr) return;

    if (movimentosNesteTurno >= 10) {
        interface.mostraErro("Limite de 10 movimentos atingido!");
        return;
    }

    int lAnt = jardineiro.getLinha();
    int cAnt = jardineiro.getColuna();

    jardineiro.mover(direcao, jardim->getLinhas(), jardim->getColunas());

    if (jardineiro.getLinha() != lAnt || jardineiro.getColuna() != cAnt) {
        movimentosNesteTurno++;
        verificarEColherFerramenta();
        interface.mostraJardim(*jardim, tempo.getInstante(), jardineiro.getLinha(), jardineiro.getColuna());
    }
}

void Controlador::entrarNoJardim(int l, int c) {
    if (jardim == nullptr) return;

    if (entradasNesteTurno >= 1) {
        interface.mostraErro("O jardineiro ja entrou no jardim neste turno!");
        return;
    }

    if (jardim->posicaoValida(l, c)) {
        jardineiro.setPosicao(l, c);
        entradasNesteTurno++;
        verificarEColherFerramenta();
        interface.mostraJardim(*jardim, tempo.getInstante(), jardineiro.getLinha(), jardineiro.getColuna());
    }
}

void Controlador::sairDoJardim() {
    if (jardim == nullptr) return;


    if (saidasNesteTurno >= 1) {
        interface.mostraErro("O jardineiro ja saiu neste turno!");
        return;
    }


    if (jardineiro.getLinha() == -1) {
        interface.mostraErro("O jardineiro nao esta no jardim!");
        return;
    }

    jardineiro.setPosicao(-1, -1); // Define posição "fora"
    saidasNesteTurno++;

    interface.mostraMensagem("O jardineiro saiu do jardim.");
    interface.mostraJardim(*jardim, tempo.getInstante(), -1, -1);
}

void Controlador::verificarEColherFerramenta() {
    if (jardim == nullptr) return;

    int l = jardineiro.getLinha();
    int c = jardineiro.getColuna();


    Ferramenta* f = jardim->colherFerramenta(l, c);

    if (f != nullptr) {

        jardineiro.adicionarFerramenta(f);

        char tipo = toCharFerramenta(f->getTipoFerramenta());
        interface.mostraMensagem("Apanhaste automaticamente: " + string(1, toupper(tipo)));
    }
}

void Controlador::comprarFerramenta(char tipo) {
    Ferramenta* nova = nullptr;
    int id = gerarNovoId();

    switch (tipo) {
        case 'g': nova = new Regador(id); break;
        case 'a': nova = new Adubo(id); break;
        case 't': nova = new Tesoura(id); break;
        case 'z': nova = new FerramentaZ(id); break;
    }

    if (nova != nullptr) {
        jardineiro.adicionarFerramenta(nova);
        interface.mostraMensagem("Compra efetuada! Nova ferramenta com ID: " + to_string(id));
    }
}

void Controlador::aplicarAdubo() {
    if (jardineiro.getLinha() == -1) {
        interface.mostraErro("O jardineiro nao esta no jardim!");
        return;
    }

    Ferramenta* f = jardineiro.getFerramentaAtual();

    if (f != nullptr && f->getTipoFerramenta() == TipoFerramenta::Adubo) {
        int l = jardineiro.getLinha();
        int c = jardineiro.getColuna();


        jardim->getSolo(l, c).adicionarNutrientes(Settings::Adubo::dose);


        f->usarFerramenta(l, c);


        if (f->estaDescartada()) {
            jardineiro.removerFerramenta(f->getID());
            interface.mostraMensagem("Adubo aplicado! O pacote esvaziou e voou para o vizinho.");
        } else {
            interface.mostraMensagem("Adubo aplicado com sucesso (+10 nutrientes).");
        }
    } else {
        interface.mostraErro("Nao tens um pacote de adubo selecionado!");
    }
}

void Controlador::usarAspirador() {

    if (jardineiro.getLinha() == -1) {
        interface.mostraErro("Precisas de estar no jardim para usar o aspirador!");
        return;
    }


    Ferramenta* aspirador = nullptr;
    const std::vector<Ferramenta*>& inv = jardineiro.getInventario();

    for (Ferramenta* f : inv) {
        if (f->getTipoFerramenta() == TipoFerramenta::FerramentaZ) {
            aspirador = f;
            break;
        }
    }

    if (aspirador != nullptr) {

        jardim->aspirarErvasDaninhas();


        aspirador->usarFerramenta(jardineiro.getLinha(), jardineiro.getColuna());


        jardineiro.removerFerramenta(aspirador->getID());

        interface.mostraMensagem("VRUMMM! O aspirador sugou todas as ervas daninhas e partiu-se!");
    } else {
        interface.mostraErro("Não tens o Aspirador (Ferramenta Z) no inventário!");
    }
}

void Controlador::gravarJardim(const string& nome) {
    if (jardim == nullptr) {
        interface.mostraErro("Nao existe um jardim ativo para gravar!");
        return;
    }


    auto it = copiasSeguranca.find(nome);
    if (it != copiasSeguranca.end()) {
        delete it->second;
    }


    copiasSeguranca[nome] = new Jardim(*jardim);

    interface.mostraMensagem("Jardim salvaguardado na memoria com o nome: " + nome);
}

void Controlador::recuperarJardim(const string& nome) {
    auto it = copiasSeguranca.find(nome);

    if (it == copiasSeguranca.end()) {
        interface.mostraErro("Gravacao nao encontrada: " + nome);
        return;
    }


    delete jardim;


    jardim = new Jardim(*(it->second));

    interface.mostraMensagem("Jardim recuperado com sucesso do estado: " + nome);


    interface.mostraJardim(*jardim, tempo.getInstante(), jardineiro.getLinha(), jardineiro.getColuna());
}

void Controlador::apagarGrava(const string& nome) {
    auto it = copiasSeguranca.find(nome);

    if (it == copiasSeguranca.end()) {
        interface.mostraErro("Não existe nenhuma gravação com o nome: " + nome);
        return;
    }

    delete it->second;


    copiasSeguranca.erase(it);

    interface.mostraMensagem("Gravação '" + nome + "' eliminada da memória.");
}