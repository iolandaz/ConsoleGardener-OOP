//
// Created by Utilizador on 25/10/2025.
//

#ifndef TESTE_FERRAMENTA_H
#define TESTE_FERRAMENTA_H
#include <string>

#include "TipoFerramentas.h"

class Ferramenta {
protected:
    TipoFerramenta tipo;
    int desgaste;
    bool descarta;
    int id;

public:
    Ferramenta(TipoFerramenta t, int idSerie);
    virtual ~Ferramenta(){}


    virtual void usarFerramenta(int linha, int coluna) = 0;
    virtual void descartarFerramenta(int desgaste) = 0;
    virtual std::string getDetalhes() const;

    bool estaDescartada() const;
    TipoFerramenta getTipoFerramenta() const{return tipo;};
    int getDesgaste() const;
    int getID() const { return id; }
};


#endif