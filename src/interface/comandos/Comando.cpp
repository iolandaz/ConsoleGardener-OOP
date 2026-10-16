//
// Created by Utilizador on 25/10/2025.
//

#include "../../../include/interface/comandos/Comando.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool Comando::validaComando() {

    const string comandosValidos[] = {
            "jardim", "planta", "colhe", "avanca", "entra", "sai",
            "compra", "pega", "larga", "grava", "recupera", "apaga",
            "executa", "fim"
    };
    const int totalComandos = sizeof(comandosValidos) / sizeof(comandosValidos[0]);

    if (nome.empty()) {
        erro = "Comando vazio!";
        valido = false;
        return false;
    }


    string nomeLower = nome;
    for (char &c : nomeLower)
        c = static_cast<char>(tolower(c));


    for (int i = 0; i < totalComandos; i++) {
        if (comandosValidos[i] == nomeLower) {
            valido = true;
            erro = "";
            return true;
        }
    }

    erro = "Comando desconhecido: " + nome;
    valido = false;
    return false;
}

void Comando::executaComando() {
    if (!valido) {
        cout << "Erro: comando inválido (" << erro << ")" << endl;
        return;
    }

    cout << "Executar comando base: " << nome << endl;
}
