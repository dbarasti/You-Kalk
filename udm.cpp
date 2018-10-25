#include "udm.h"
#include<stdexcept>
#include<iostream>

int UdM::calcolaOffset(const QVector<char> & prefissi)
{
    QVector<char> pref = prefissi;
    while(pref.last()!='\0')
        pref.pop_back();
    pref.pop_back();
    return pref.size();
}

UdM::UdM(const QString &unit, const char &pref):unita(unit){
    setPrefisso(pref);
}

QVector<char> UdM::prefissi = {'n','u','m','\0', 'K', 'M'};

int UdM::offset = UdM::calcolaOffset(UdM::prefissi);

UdM::UdM(const UdM & u):unita(u.unita), index(u.index){}

QString UdM::getUnita() const
{
    return unita;
}

void UdM::setUnita(const QString &value)
{
    unita = value;
}

double UdM::getMoltiplicatore() const
{
    return pow(10,((index - offset)*3));
}

char UdM::getPrefisso() const
{
    return prefissi[index];
}

void UdM::setPrefisso(const char& value)
{
    int indice = prefissi.indexOf(value);
    if(indice == -1){
        throw std::invalid_argument("BadPrefix");
    }else
        index = indice;
}

bool UdM::next()
{
    if(getPrefisso() != prefissi.last()){
        ++index;
        return true;
    }
    return false;
}

bool UdM::prev()
{
    if(getPrefisso() != prefissi.first()){
        --index;
        return true;
    }
    return false;
}
