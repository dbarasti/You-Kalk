#ifndef DISPLAY_H
#define DISPLAY_H
#include <QLineEdit>

class Display : public QLineEdit
{
public:
    Display(const QString&s);
    bool writable = 1;
};

#endif // DISPLAY_H
