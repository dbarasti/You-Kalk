#include "misura.h"

Misura::Misura(double val, QString unit):valore(val), unita(unit){}

double Misura::getValore() const
{
    return valore;
}

void Misura::setValore(double value)
{
    valore = value;
}

double Misura::getMoltiplicatore() const
{
    return unita.getMoltiplicatore();
}

void Misura::reset()
{
    valore = 0;
    unita.setPrefisso('\0');
}

void Misura::normalizza()
{
    while(valore>=1000 && unita.next())
        valore /= 1000;

    while(valore != 0 && valore < 1 && unita.prev())
        valore *= 1000;
}

QString Misura::getUnita() const
{
    return unita.getUnita();
}

void Misura::setUnita(const QString & u)
{
    unita.setUnita(u);
}

QString Misura::toString() const
{
    return QString::number(valore, 'g', 3) + unita.getPrefisso() + unita.getUnita();
}

void Misura::setPrefisso(const char& value) {
    unita.setPrefisso(value);
}

char Misura::getPrefisso() const
{
    return unita.getPrefisso();
}
