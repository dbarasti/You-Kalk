#ifndef CONDENSATORE_H
#define CONDENSATORE_H
#include <componenteelettrico.h>

class Condensatore: public ComponenteElettrico
{
private:
    Misura t_carica;
    Misura resistenza; //resistenza che viene usata per il calcolo del t_carica
public:
    Condensatore(double v=0);
    Condensatore(const Condensatore *);
    Condensatore* copy() const;
    Condensatore* parallelo(ComponenteElettrico * )const;
    Condensatore* serie(ComponenteElettrico * )const;
    //calcola tensione ai capi del condensatore in un istante t:
    double V(double t) const; //calcola la tensione ai capi del condensatore nel tempo t
    double getResistenza() const;
    void setResistenza(double v);
    void setT_carica();
    double getT_carica() const;
    QString resistenzaString()const;
    QString t_caricaString() const;
    void reset();
};

#endif // CONDENSATORE_H
