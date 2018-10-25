#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

class Button : public QToolButton
{
    Q_OBJECT
public:
    QString info;
    explicit Button(const QString &text, QWidget *parent = 0, const QString & info = "\0");
    QSize sizeHint() const override;

protected:
    virtual void enterEvent( QEvent* e );

signals:
    void hovered();
};

#endif
