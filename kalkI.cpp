#include "kalkI.h"

calcI::calcI(Application *p):calc(p)
{
    Button *nHButton = createButton(tr("nH"), SLOT(setPref()) );
    Button *uHButton = createButton(tr("uH"), SLOT(setPref()) );
    Button *mHButton = createButton(tr("mH"), SLOT(setPref()) );
    Button *setValoreButton = createButton(tr("setVal"), SLOT(setValore()), tr("Imposta il valore di induttanza"));
    Button *setTensACButton = createButton(tr("setTens"), SLOT(setTensioneAC()), tr("Imposta la tensione di picco AC ai capi del circuito selezionato"));
    Button *setResistenzaButton = createButton(tr("setRes"), SLOT(setResistenza()), tr("Imposta il valore della resistenza del circuito in Ohm"));
    Button *setFrequenzaButton =createButton(tr("setFrq"), SLOT(setFrequenza()), tr("Imposta la frequenza del generatore di tensione AC"));
    Button *getCurrentButton = createButton(tr("getCurr"), SLOT(getCurrent()), tr("Calcola il valore della corrente che scorre nel circuito R-L, data una tensione"));

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    mainLayout->addWidget(nHButton, 6, 3);
    mainLayout->addWidget(uHButton, 6, 4);
    mainLayout->addWidget(mHButton, 6, 5);
    mainLayout->addWidget(setValoreButton, 3, 0);
    mainLayout->addWidget(setTensACButton, 5, 0);
    mainLayout->addWidget(setResistenzaButton, 4, 0);
    mainLayout->addWidget(setFrequenzaButton, 6,0);
    mainLayout->addWidget(getCurrentButton, 4, 5);
    setLayout(mainLayout);
    parent->setWindowTitle(tr("YouKalk <Induttore>"));
}
