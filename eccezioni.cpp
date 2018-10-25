#include "eccezioni.h"

BadOperation::BadOperation(const QString &e):detail(e){}

QString BadOperation::what()
{
    return detail;
}

Alert::Alert(const QString &m):detail(m){}

QString Alert::what()
{
    return detail;
}
