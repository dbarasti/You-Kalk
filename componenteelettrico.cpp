#include "componenteelettrico.h"

ComponenteElettrico::ComponenteElettrico(double v, QString u):valore_principale(v, u), tensioneDC(0,"V"){}

ComponenteElettrico::ComponenteElettrico(const ComponenteElettrico *r):valore_principale(r->valore_principale),
                                                                        tensioneDC(r->tensioneDC), tensioneAC(r->tensioneAC){}

double ComponenteElettrico::getValorePrincipale() const{
    return valore_principale.getValore() * valore_principale.getMoltiplicatore();
}

void ComponenteElettrico::setValorePrincipale(double value)
{
    valore_principale.setValore(value);
}

double ComponenteElettrico::getTensioneDC() const
{
    return tensioneDC.getValore() * tensioneDC.getMoltiplicatore();
}

void ComponenteElettrico::setTensioneDC(double value)
{
    tensioneDC.setValore(value);
    tensioneDC.setPrefisso('\0');
    tensioneDC.normalizza();
}

QString ComponenteElettrico::tensioneDCString() const
{
    return tensioneDC.toString();
}

double ComponenteElettrico::getTensioneAC() const
{
    return tensioneAC.getValore() * tensioneAC.getMoltiplicatore();
}

void ComponenteElettrico::setTensioneAC(double value)
{
    tensioneAC.setValore(value);
}

QString ComponenteElettrico::tensioneACString() const
{
    return tensioneAC.toString();
}

double ComponenteElettrico::getFrequenza() const
{
    return tensioneAC.getFrequenza();
}

void ComponenteElettrico::setFrequenza(double val)
{
    tensioneAC.setFrequenza(val);
}

QString ComponenteElettrico::frequenzaString() const
{
    return tensioneAC.frequenzaString();
}

double ComponenteElettrico::getRMS() const
{
    return tensioneAC.getRMS();
}

void ComponenteElettrico::setRMS()
{
    tensioneAC.setRMS();
}

QString ComponenteElettrico::rmsString() const
{
    return tensioneAC.rmsString();
}

void ComponenteElettrico::normalizza()
{
    valore_principale.normalizza();
}

void ComponenteElettrico::reset()
{
    valore_principale.reset();
    tensioneDC.reset();
}

void ComponenteElettrico::setUnitaPrincipale(const char &value)
{
    valore_principale.setPrefisso(value);
}

QString ComponenteElettrico::valorePrincipaleString() const
{
    return valore_principale.toString();
}
