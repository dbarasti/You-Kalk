#ifndef RESISTORE_H
#define RESISTORE_H
#include<componenteelettrico.h>

class Resistore: public ComponenteElettrico
{
private:
    Misura potenzaMax; //potenza massima dissipabile dal resistore
    Misura corrente;
    Misura potenza;
public:
    Resistore(double v=0);
    Resistore(const Resistore *);
    double potenza_max_equivalente_par(const ComponenteElettrico *r2, const double & val)const;
    double potenza_max_equivalente_ser(const ComponenteElettrico * r2, const double & val)const;
    Resistore * copy() const;
    Resistore * parallelo(ComponenteElettrico * r)const;
    Resistore * serie(ComponenteElettrico * r)const;
    void setCorrente();
    double getCorrente() const;
    double getPotenzaMax() const;
    void setPotenzaMax(double value);
    double getPotenza() const;
    void setPotenza();
    QString potenzaMaxString() const;
    QString correnteString() const;
    QString potenzaString() const;
    void reset();
};

#endif // RESISTENZA_H
