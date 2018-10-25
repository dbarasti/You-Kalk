#include <QtWidgets>

#include "button_mod.h"

Button::Button(const QString &text, QWidget *parent, const QString &info)
    : QToolButton(parent), info(info)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setMouseTracking(true);
    setText(text);
}

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}

void Button::enterEvent( QEvent* e )
{
    hovered();
    QWidget::enterEvent( e );
}
