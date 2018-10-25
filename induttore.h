#ifndef INDUTTORE_H
#define INDUTTORE_H
#include "solenoide.h"

class Induttore : public Solenoide
{
private:
    Misura resistenza;
    Misura corrente;

public:
    Induttore(double val = 0, double l = 0, int n = 0);
    Induttore(const Induttore *);
    double getResistenza() const;
    void setResistenza(double v);
    QString resistenzaString()const;
    double getCorrente();
    void setCorrente();
    QString correnteString()const;
    double getPulsazione()const;
    double getSfasamento()const;
    Induttore * parallelo(ComponenteElettrico * r)const;
    Induttore * serie(ComponenteElettrico * i)const;
    Induttore * copy() const;
    void reset();
};

#endif // INDUTTORE_H
