#include "misuraTA.h"
#include <math.h>

MisuraTA::MisuraTA(double V, double f):Misura(V, "V"), frequenza(f, "Hz"), RMS(valore/sqrt(2), "V"){}

void MisuraTA::setValore(double value)
{
    valore = value;
    setPrefisso('\0');
    normalizza();
    setRMS();
}

double MisuraTA::getFrequenza() const
{
    return frequenza.getValore() * frequenza.getMoltiplicatore();
}

void MisuraTA::setFrequenza(double val)
{
    frequenza.setValore(val);
    frequenza.setPrefisso('\0');
    frequenza.normalizza();
}

QString MisuraTA::frequenzaString() const
{
    return frequenza.toString();
}

double MisuraTA::getRMS() const
{
    return RMS.getValore() * RMS.getMoltiplicatore();
}

void MisuraTA::setRMS()
{
    RMS.setValore(valore/sqrt(2));
}

QString MisuraTA::rmsString() const
{
    return RMS.toString();
}

double MisuraTA::getW()const
{
    return 2 * M_PI * getFrequenza();
}
