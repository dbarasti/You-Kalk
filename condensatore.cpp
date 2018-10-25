#include "condensatore.h"
#include "exception"

Condensatore::Condensatore(double v):ComponenteElettrico(v, "F"), t_carica(0,"S"), resistenza(5000, "ohm"){
    resistenza.normalizza();
    valore_principale.setPrefisso('m');
}

Condensatore::Condensatore(const Condensatore *c):ComponenteElettrico(c), t_carica(c->t_carica), resistenza(c->resistenza){}

Condensatore *Condensatore::copy() const
{
    return new Condensatore(this);
}

double Condensatore::getT_carica() const
{
    return t_carica.getValore() * t_carica.getMoltiplicatore();
}

void Condensatore::setT_carica()
{
    if(getTensioneDC() > 0){
        double t_c = 5 * getResistenza() * getValorePrincipale();
        t_carica.setValore(t_c);
        t_carica.setPrefisso('\0');
        t_carica.normalizza();
    }
    else
        throw BadOperation("Valore tensione mancante");
}

QString Condensatore::resistenzaString() const
{
    return resistenza.toString();
}

QString Condensatore::t_caricaString() const
{
    return t_carica.toString();
}

Condensatore *Condensatore::parallelo(ComponenteElettrico * c)const{
    double valore1 = getValorePrincipale();
    double valore2 = c->getValorePrincipale();
    if(valore1 > 0.0 && valore2 > 0.0){
        double valore_aux = valore1 + valore2;
        Condensatore* aux = new Condensatore(valore_aux); //magari metto direttamente val1+val2?
        aux->valore_principale.normalizza(); //sistemare normalizzazione
        return aux;
    }
    throw BadOperation("Uno degli operandi non è stato definito");
}

Condensatore *Condensatore::serie(ComponenteElettrico *c) const{
    double valore1 = getValorePrincipale();
    double valore2 = c->getValorePrincipale();
    if(valore1 > 0 && valore2 > 0.0){
        double valore_aux = (valore1 * valore2) / (valore1 + valore2);
        Condensatore* aux = new Condensatore(valore_aux);
        aux->valore_principale.normalizza(); //da sistemare normalizzazione
        return aux;
    }
    else
        throw BadOperation("Uno degli operandi non è stato definito");

}


double Condensatore::V(double t) const
{
    double tensione = getTensioneDC();
    double RC = getResistenza() * getValorePrincipale();
    if(getT_carica() > 0){
        return tensione*(1 - pow(M_E, -t/RC));
    }
    else
        return 0;
}

double Condensatore::getResistenza() const
{
    return resistenza.getValore() * resistenza.getMoltiplicatore();
}

void Condensatore::setResistenza(double v)
{
    resistenza.setValore(v);
    resistenza.setPrefisso('\0');
    resistenza.normalizza();
}

void Condensatore::reset()
{
    ComponenteElettrico::reset();
    t_carica.reset();
}
