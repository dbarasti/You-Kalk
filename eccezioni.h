#ifndef ECCEZIONI_H
#define ECCEZIONI_H
#include <QString>

class BadOperation{
private:
    QString detail;
public:
    BadOperation(const QString & e = "");
    QString what();
};

class Alert{
private:
    QString detail;
public:
    Alert(const QString &);
    QString what();
};

#endif // ECCEZIONI_H
