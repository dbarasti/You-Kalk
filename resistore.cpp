#include "resistore.h"
#include <assert.h>
#include <exception>

Resistore::Resistore(double v):ComponenteElettrico(v, "ohm"), potenzaMax(0, "W"), corrente(0,"A"), potenza(0, "W"){}

Resistore::Resistore(const Resistore *r):ComponenteElettrico(r), potenzaMax(r->potenzaMax), corrente(r->corrente), potenza(r->potenza){}

double Resistore::getPotenzaMax() const
{
    return potenzaMax.getValore() * potenzaMax.getMoltiplicatore();
}

void Resistore::setPotenzaMax(double value)
{
    potenzaMax.setValore(value);
    potenzaMax.setPrefisso('\0');
    potenzaMax.normalizza();
}

QString Resistore::potenzaMaxString() const
{
    return potenzaMax.toString();
}

QString Resistore::correnteString() const
{
    return corrente.toString();
}

QString Resistore::potenzaString() const
{
    return potenza.toString();
}

double Resistore::getCorrente() const
{
    return corrente.getValore() * corrente.getMoltiplicatore();
}

void Resistore::setCorrente()
{
    if(getTensioneDC() > 0){
        double curr = getTensioneDC() / getValorePrincipale();
        corrente.setValore(curr);
        corrente.setPrefisso('\0');
        corrente.normalizza();
    }
    else{
        throw BadOperation("Valore tensione non specificato");
    }
}

double Resistore::getPotenza() const
{
    return potenza.getValore() * potenza.getMoltiplicatore();
}

void Resistore::setPotenza()
{
    double potenzadissipata = getTensioneDC()* getCorrente();
    potenza.setValore(potenzadissipata);
    potenza.setPrefisso('\0');
    potenza.normalizza();
    if(getPotenzaMax() > 0 && getPotenzaMax() < potenzadissipata)
        throw Alert("Attenzione: la potenza massima è stata superata");

}

double Resistore::potenza_max_equivalente_ser(const ComponenteElettrico * r2, const double & val)const{
    double wmax = 0, imax = 0;
    double r1_valore_assoluto = getValorePrincipale();
    const Resistore* r2_cast = dynamic_cast<const Resistore*>(r2);
    double r2_valore_assoluto = r2->getValorePrincipale();
    if( getPotenzaMax() / r1_valore_assoluto < ( r2_cast->getPotenzaMax() / r2_valore_assoluto ))
        imax = sqrt( getPotenzaMax() / r1_valore_assoluto );
    else
        imax = sqrt(r2_cast->getPotenzaMax() / r2_valore_assoluto);
    wmax = pow(imax, 2) * val;
    return wmax;
}

Resistore *Resistore::copy() const
{
    return new Resistore(this);
}


double Resistore::potenza_max_equivalente_par(const ComponenteElettrico* r2, const double & val)const{
    double wmax = 0, vmax = 0;
    double r1_valore_assoluto = getValorePrincipale();
    const Resistore* r2_cast = dynamic_cast<const Resistore*>(r2);
    double r2_valore_assoluto =  r2->getValorePrincipale();
    if(r1_valore_assoluto * getPotenzaMax() < r2_valore_assoluto * r2_cast->getPotenzaMax()){
        vmax = sqrt(r1_valore_assoluto * getPotenzaMax());
    }
    else
        vmax = sqrt(r2_valore_assoluto * r2_cast->getPotenzaMax());
    wmax = pow(vmax, 2) / val;
    return wmax;
}

Resistore *Resistore::parallelo(ComponenteElettrico * r)const{
    double valore1 = getValorePrincipale();
    double valore2 = r->getValorePrincipale();
    if(valore1 > 0 && valore2 > 0){
        double valore_par = (valore1 * valore2) / (valore1 + valore2);
        Resistore* aux = new Resistore(valore_par);
        aux->setPotenzaMax( potenza_max_equivalente_par(r, valore_par) );
        aux->potenzaMax.normalizza();
        aux->valore_principale.normalizza();
        return aux;
    }
    else{
        throw BadOperation("Uno degli operandi non è stato definito");
    }
}

Resistore *Resistore::serie(ComponenteElettrico *r) const{
    double valore1 = getValorePrincipale();
    double valore2 = r->getValorePrincipale();
    if(valore1 > 0 && valore2 > 0){
        double valore_serie = valore1 + valore2;
        Resistore* aux = new Resistore(valore_serie);
        aux->setPotenzaMax(potenza_max_equivalente_ser(r, valore_serie));
        aux->potenzaMax.normalizza();
        aux->valore_principale.normalizza();
        return aux;
    }
    else
        throw BadOperation("Uno degli operandi non è stato definito");
}

void Resistore::reset()
{
    ComponenteElettrico::reset();
    potenzaMax.reset();
    corrente.reset();
    potenza.reset();
}
