#include "kalkC.h"

calcC::calcC(Application *p):calc(p)
{
    Button *nfButton = createButton(tr("nF"), SLOT(setPref()));
    Button *uFButton = createButton(tr("uF"), SLOT(setPref()));
    Button *mFButton = createButton(tr("mF"), SLOT(setPref()));
    Button *setValoreButton = createButton(tr("setVal"), SLOT(setValore()), tr("Imposta il valore di capacità"));
    Button *setTensDCButton = createButton(tr("setTens"), SLOT(setTensioneDC()), tr("Imposta la tensione DC ai capi dell'operando selezionato"));
    Button *setResistenzaButton = createButton(tr("setRes"), SLOT(setResistenza()), tr("Imposta il valore della resistenza di carica in Ohm"));
    Button *getCaricaButton = createButton(tr("getTCar"), SLOT(getTCarica()), tr("Calcola il valore del tempo di carica del condensatore, data una tensione"));

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    mainLayout->addWidget(nfButton, 6, 3);
    mainLayout->addWidget(uFButton, 6, 4);
    mainLayout->addWidget(mFButton, 6, 5);
    mainLayout->addWidget(setResistenzaButton, 4, 0);
    mainLayout->addWidget(setTensDCButton, 5, 0);
    mainLayout->addWidget(setValoreButton, 3, 0);
    mainLayout->addWidget(getCaricaButton, 4, 5);
    setLayout(mainLayout);

    parent->setWindowTitle(tr("YouKalk <Condensatore>"));
}
