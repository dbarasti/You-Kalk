#ifndef MISURATA_H
#define MISURATA_H
#include "misura.h"

class MisuraTA : public Misura
{
private:
    Misura frequenza;
    Misura RMS;
public:
    MisuraTA(double V = 0, double f = 0);

    void setValore(double value);
    double getFrequenza()const;
    void setFrequenza(double val);
    QString frequenzaString()const;
    double getRMS()const;
    void setRMS();
    QString rmsString()const;
    double getW()const; //pulsazione
};

#endif // MISURATA_H
