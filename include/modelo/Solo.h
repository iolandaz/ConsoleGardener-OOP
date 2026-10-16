#ifndef TESTE_SOLO_H
#define TESTE_SOLO_H

#include "Settings.h"
#include "plantas/Planta.h"

class Jardim;

class Solo {
    int agua;
    int nutrientes;
    Planta* planta = nullptr;

public:
    Solo();
    ~Solo();

    int getAgua() const { return agua; }
    int getNutrientes() const { return nutrientes; }


    bool temPlanta() const { return planta != nullptr; }
    Planta* getPlanta() { return planta; }
    void setPlanta(Planta* nova) { planta = nova; }
    void removerPlanta();


    void adicionarAgua(int qtd);
    void adicionarNutrientes(int qtd);
    
    void retirarAgua(int qtd);      
    void retirarNutrientes(int qtd); 

    void processaTurno(Jardim& j, int l, int c);
};

#endif