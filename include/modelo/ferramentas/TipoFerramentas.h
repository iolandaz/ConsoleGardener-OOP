// TipoFerramenta.h
#ifndef TIPOFERRAMENTA_H
#define TIPOFERRAMENTA_H

enum class TipoFerramenta {
    Regador,
    Adubo,
    Tesoura,
    FerramentaZ,
    Invalido
};
inline TipoFerramenta fromCharFerramenta(char c) {
    switch(c) {
        case 'g': case 'G': return TipoFerramenta::Regador;
        case 'a': case 'A': return TipoFerramenta::Adubo;
        case 't': case 'T': return TipoFerramenta::Tesoura;
        case 'z': case 'Z': return TipoFerramenta::FerramentaZ;
        default: return TipoFerramenta::Invalido;
    }
}

inline char toCharFerramenta(TipoFerramenta t) {
    switch(t) {
        case TipoFerramenta::Regador: return 'g';
        case TipoFerramenta::Adubo: return 'a';
        case TipoFerramenta::Tesoura: return 't';
        case TipoFerramenta::FerramentaZ: return 'z';
        default: return '?';
    }
}

#endif
