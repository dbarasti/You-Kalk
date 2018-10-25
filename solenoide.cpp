#include "solenoide.h"

Solenoide::Solenoide(double val, double l, unsigned int n):ComponenteElettrico(val, "H") ,lunghezza(l, "m"), Nspire(n){
    valore_principale.setPrefisso('m');
}

Solenoide::Solenoide(const Solenoide * i):ComponenteElettrico(i), lunghezza(i->lunghezza), Nspire(i->Nspire){}

double Solenoide::getLunghezza() const
{
    return lunghezza.getValore() * lunghezza.getMoltiplicatore();
}

void Solenoide::setLunghezza(const Misura &value)
{
    lunghezza = value;
    lunghezza.setPrefisso('\0');
    lunghezza.normalizza();
}

unsigned int Solenoide::getNspire() const
{
    return Nspire;
}

void Solenoide::setNspire(unsigned int value)
{
    Nspire = value;
}

void Solenoide::reset()
{
    ComponenteElettrico::reset();
    lunghezza.reset();
    Nspire = 0;
}
