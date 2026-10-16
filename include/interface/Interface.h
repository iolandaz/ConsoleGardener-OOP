//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_INTERFACE_H
#define TESTE_INTERFACE_H

#include "../modelo/Jardim.h"
#include <string>

class Interface {
public:
    void mostraMensagem(const std::string &msg) const;
    void mostraErro(const std::string &erro) const;
    void mostraTexto() const;
    string leLinha() const;
    void mostraJardim(const Jardim &jardim, int instante, int jLinha, int jColuna) const;
};



#endif
