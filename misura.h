#ifndef MISURA_H
#define MISURA_H
#include <udm.h>

class Misura
{
protected:
    double valore;
    UdM unita;
public:
    Misura(double val = 0, QString unit = "\0");
    void normalizza();
    QString getUnita() const;
    void setUnita(const QString &);
    QString toString() const;
    void setPrefisso(const char &);
    char getPrefisso() const;
    double getValore() const;
    void setValore(double value);
    double getMoltiplicatore() const;
    void reset();
};

#endif // MISURA_H
