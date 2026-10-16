#include "../../../include/interface/comandos/ComandoListaFerramentas.h"
#include <sstream>
#include <iostream>

using namespace std;

ComandoLferr::ComandoLferr(const string &linha, Controlador &c) : controlador(c) {
    nome = "lferr";
    valido = false;
    erro = "";

    stringstream ss(linha);
    string cmd, extra;
    ss >> cmd;
    ss >> extra;

    if (!extra.empty()) {
        erro = "O comando 'lferr' nao deve ter argumentos.";
    }
}

bool ComandoLferr::validaComando() {
    return erro.empty();
}

void ComandoLferr::executaComando() {
    if (!validaComando()) {
        cout << "Erro: " << erro << endl;
        return;
    }


    Jardineiro& jardineiro = controlador.getJardineiro();
    const auto& inventario = jardineiro.getInventario();
    Ferramenta* naMao = jardineiro.getFerramentaAtual();

    cout << "\n========== INVENTARIO DO JARDINEIRO ==========" << endl;

    if (inventario.empty()) {
        cout << "  (O inventario esta vazio)" << endl;
    } else {
        for (size_t i = 0; i < inventario.size(); ++i) {
            Ferramenta* f = inventario[i];


            if (f == naMao) {
                cout << " -> [EM MAO] ";
            } else {
                cout << "    [" << i << "]      ";
            }


            cout << f->getDetalhes() << endl;
        }
    }
    cout << "==============================================" << endl;
}