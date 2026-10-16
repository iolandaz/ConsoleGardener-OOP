#ifndef TEMPO_H
#define TEMPO_H

class Tempo {
    int instanteAtual;

public:
    Tempo();

    void avanca(int n = 1);
    int getInstante() const;
    void reinicia();
};

#endif
