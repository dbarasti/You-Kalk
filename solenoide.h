#ifndef SOLENOIDE_H
#define SOLENOIDE_H
#include "componenteelettrico.h"
#include "misuraTA.h"

class Solenoide : public ComponenteElettrico
{
protected:
    Misura lunghezza;
    unsigned int Nspire;
public:
    Solenoide(double val = 0, double l = 0, unsigned int n = 0);
    Solenoide(const Solenoide *);
    double getLunghezza() const;
    void setLunghezza(const Misura &value);
    unsigned int getNspire() const;
    void setNspire(unsigned int value);
    void reset();
};

#endif // SOLENOIDE_H
