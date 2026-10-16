//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_COMANDO_H
#define TESTE_COMANDO_H
using namespace std;
#include <string>

class Comando {
protected:
    string nome;
    bool valido;
    string erro;

public:
    Comando() {}
    virtual ~Comando(){}

    virtual bool validaComando() = 0;
    virtual void executaComando() = 0;

    bool eValido() const {
        return valido;
    }
    string getErro() const {
        return erro;
    }
    string getNome() const {
        return nome;
    }
};


#endif
