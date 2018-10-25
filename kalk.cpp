#include "kalk.h"
#include "Application.h"
calc::calc(Application *p)
    :parent(p)
{
    displayLeft = new Display("0");
    displayLeft->setReadOnly(true);
    displayLeft->setAlignment(Qt::AlignRight);
    displayLeft->setMaxLength(30);
    QFont font = displayLeft->font();
    font.setPointSize(font.pointSize() + 8);
    displayLeft->setFont(font);

    displayRight = new Display("0");
    displayRight->setReadOnly(true);
    displayRight->setAlignment(Qt::AlignRight);
    displayRight->setMaxLength(30);
    QFont font2 = displayRight->font();
    font2.setPointSize(font2.pointSize() + 8);
    displayRight->setFont(font2);

    displayResult = new Display("/");
    displayResult->setReadOnly(true);
    displayResult->setAlignment(Qt::AlignRight);
    displayResult->setMaxLength(30);
    QFont font3 = displayResult->font();
    font3.setPointSize(font3.pointSize() + 8);
    displayResult->setFont(font3);

    for (int i = 0; i < NumDigitButtons; ++i) {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    Button *clearScreen = createButton(tr("Clear Scr"), SLOT(clear()));
    Button *clearOperand = createButton(tr("Clear Op"), SLOT(clearOp()), tr("Resetta l'operando selezionato"));
    Button *paralleloButton = createButton(tr("//"), SLOT(additiveOperatorClicked()),tr("Esegue l'equivalenza in parallelo dei due operandi"));
    Button *serieButton = createButton(tr("--"), SLOT(additiveOperatorClicked()), tr("Esegue l'equivalenza in serie dei due operandi"));
    Button *copyLeftButton = createButton(tr("↖"), SLOT(copyLeftClicked()), tr("Copia i valori del risultato nell'operando di sinistra"));
    Button *copyRightButton = createButton(tr("↗"), SLOT(copyRightClicked()), tr("Copia i valori del risultato nell'operando di destra"));
    Button *normalizzaButton = createButton(tr("Nrml"), SLOT(unaryOperatorClicked()), tr("Reimposta il valore e il prefisso dell'operando selezionato in maniera ottimale"));
    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row+1, column);
    }
    mainLayout->addWidget(digitButtons[0], 6, 1);
    mainLayout->addWidget(pointButton, 6, 2);
    mainLayout->addWidget(backspaceButton, 2, 0, 1, 2);
    mainLayout->addWidget(clearScreen, 2, 2, 1, 2);
    mainLayout->addWidget(clearOperand, 2, 4, 1, 2);
    mainLayout->addWidget(paralleloButton, 3, 4);
    mainLayout->addWidget(serieButton, 3, 5);
    mainLayout->addWidget(copyLeftButton, 5, 4);
    mainLayout->addWidget(copyRightButton, 5, 5);
    mainLayout->addWidget(normalizzaButton, 4, 4);
    mainLayout->addWidget(displayLeft, 0, 0, 1, 3);
    mainLayout->addWidget(displayRight, 0, 3, 1, 3);
    mainLayout->addWidget(displayResult, 1, 0, 1, 6);

}

Button *calc::createButton(const QString &text, const char *member, const QString &info)
{
    Button *button = new Button(text,0,info);
    connect(button, SIGNAL(clicked()), parent, member);
    connect(button, SIGNAL(hovered()), parent, SLOT(setInfoText()));
    return button;
}

