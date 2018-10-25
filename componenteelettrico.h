#ifndef COMPONENTEELETTRICO_H
#define COMPONENTEELETTRICO_H
#include <udm.h>
#include <iostream>
#include <QString>
#include <misura.h>
#include <cmath>
#include "eccezioni.h"
#include "misuraTA.h"

class ComponenteElettrico
{
protected:
    Misura valore_principale;
    Misura tensioneDC;
    MisuraTA tensioneAC;
public:
    ComponenteElettrico(double v=0, QString u="\0");
    ComponenteElettrico(const ComponenteElettrico * r);
    virtual ~ComponenteElettrico() = default;
    virtual ComponenteElettrico* copy() const=0;
    virtual ComponenteElettrico* parallelo(ComponenteElettrico *) const =0;
    virtual ComponenteElettrico* serie(ComponenteElettrico *) const =0;
    virtual void reset();

    void setValorePrincipale(double value);
    double getValorePrincipale() const;
    double getTensioneDC() const;
    void setTensioneDC(double value);
    QString tensioneDCString() const;
    double getTensioneAC() const;
    void setTensioneAC(double value);
    QString tensioneACString() const;
    double getFrequenza()const;
    void setFrequenza(double val);
    QString frequenzaString()const;
    double getRMS() const;
    void setRMS();
    QString rmsString() const;
    void setUnitaPrincipale(const char &value);
    QString valorePrincipaleString() const;
    void normalizza();
};

#endif // COMPONENTEELETTRICO_H
