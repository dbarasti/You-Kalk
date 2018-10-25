#include "induttore.h"
#include <math.h>

Induttore::Induttore(double val, double l, int n):Solenoide(val, l, n), resistenza(0, "ohm"), corrente(0, "A"){}

Induttore::Induttore(const Induttore *i):Solenoide(i), resistenza(i->resistenza), corrente(i->corrente){}

double Induttore::getResistenza() const
{
    return resistenza.getValore() * resistenza.getMoltiplicatore();
}

void Induttore::setResistenza(double v)
{
    resistenza.setValore(v);
    resistenza.setPrefisso('\0');
    resistenza.normalizza();
}

QString Induttore::resistenzaString() const{
    return resistenza.toString();
}

double Induttore::getCorrente()
{
    return corrente.getValore() * corrente.getMoltiplicatore();
}

void Induttore::setCorrente()
{
    if(getTensioneAC() > 0){
        double curr = getRMS() / sqrt(pow(getResistenza(),2) + pow(getPulsazione()*getValorePrincipale(),2));
        corrente.setValore(curr);
        corrente.setPrefisso('\0');
        corrente.normalizza();
    }
    else{
        throw BadOperation("Valore tensione non specificato");
    }
}

QString Induttore::correnteString() const{
    return corrente.toString();
}

double Induttore::getPulsazione() const
{
    return tensioneAC.getW();
}

double Induttore::getSfasamento() const
{
    if(getResistenza())
        return (getPulsazione() * getValorePrincipale()) / getResistenza();
    else return 0;
}

Induttore *Induttore::parallelo(ComponenteElettrico *i)const{
    double valore1 = getValorePrincipale();
    double valore2 = i->getValorePrincipale();
    if(valore1 > 0 && valore2 > 0){
        double valore_par = (valore1 * valore2) / (valore1 + valore2);
        Induttore* aux = new Induttore(valore_par);
        aux->valore_principale.normalizza();
        return aux;
    }
    else{
        throw BadOperation("Uno degli operandi non è stato definito");
    }
}

Induttore *Induttore::serie(ComponenteElettrico *i) const{
    double valore1 = getValorePrincipale();
    double valore2 = i->getValorePrincipale();
    if(valore1 > 0 && valore2 > 0){
        double valore_serie = valore1 + valore2;
        Induttore* aux = new Induttore(valore_serie);
        aux->valore_principale.normalizza();
        return aux;
    }
    else
        throw BadOperation("Uno degli operandi non è stato definito");
}

Induttore *Induttore::copy() const
{
    return new Induttore(this);
}

void Induttore::reset()
{
    Solenoide::reset();
    resistenza.reset();
    corrente.reset();
}
