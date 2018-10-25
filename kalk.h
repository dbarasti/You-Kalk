#ifndef CALC_H
#define CALC_H
#include "button_mod.h"
#include <QWidget>
#include <QGridLayout>
#include "Application.h"

class Application;
class Display;

class calc: public QWidget
{
    Q_OBJECT
public:
    friend class Application;
    calc(Application *p = 0);
    virtual ~calc() = default;

protected:
    Application *parent;
    Button *createButton(const QString &text, const char *member, const QString &info = "\0");
    Display *displayLeft;
    Display *displayRight;
    Display *displayResult;
    QGridLayout *mainLayout = new QGridLayout;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif // CALC_H
