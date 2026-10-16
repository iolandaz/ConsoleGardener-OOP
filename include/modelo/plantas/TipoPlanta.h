
#ifndef TIPOPLANTA_H
#define TIPOPLANTA_H

enum class TipoPlanta {
    Cacto,
    Roseira,
    ErvaDaninha,
    Exotica,
    Invalido
};

inline TipoPlanta fromCharPlanta(char c) {
    switch(c) {
        case 'c': case 'C': return TipoPlanta::Cacto;
        case 'r': case 'R': return TipoPlanta::Roseira;
        case 'e': case 'E': return TipoPlanta::ErvaDaninha;
        case 'x': case 'X': return TipoPlanta::Exotica;
        default: return TipoPlanta::Invalido;
    }
}

inline char toCharPlanta(TipoPlanta t) {
    switch(t) {
        case TipoPlanta::Cacto: return 'c';
        case TipoPlanta::Roseira: return 'r';
        case TipoPlanta::ErvaDaninha: return 'e';
        case TipoPlanta::Exotica: return 'x';
        default: return '?';
    }
}

#endif
