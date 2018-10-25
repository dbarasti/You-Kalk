#ifndef UDM_H
#define UDM_H
#include<QString>
#include<QVector>
#include<math.h>

class UdM
{
private:
    QString unita;
    int index;
    static int calcolaOffset(const QVector<char> &);
public:
    UdM(const QString & unit, const char & pref = '\0');
    UdM(const UdM &);

    static QVector<char> prefissi;
    static int offset; //in base al numero di elementi in 'prefissi'

    QString getUnita() const;
    void setUnita(const QString &value);
    double getMoltiplicatore() const;
    char getPrefisso() const;
    void setPrefisso(const char &value);

    bool next();
    bool prev();
};

#endif // UDM_H
