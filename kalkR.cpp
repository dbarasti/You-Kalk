#include "kalkR.h"

calcR::calcR(Application *p):calc(p)
{
    Button *ohmButton = createButton(tr(" ohm"), SLOT(setPref()) );
    Button *KohmButton = createButton(tr("Kohm"), SLOT(setPref()) );
    Button *MohmButton = createButton(tr("Mohm"), SLOT(setPref()) );
    Button *setTensDCButton = createButton(tr("setTens"), SLOT(setTensioneDC()), tr("Imposta la tensione DC ai capi dell'operando selezionato"));
    Button *setValoreButton = createButton(tr("setVal"), SLOT(setValore()), tr("Imposta il valore di resistenza"));
    Button *setPotenzaButton = createButton(tr("setMaxP"), SLOT(setPotenza()), tr("Imposta la potenza massima dissipabile dal resistore selezionato"));
    Button *getCurrentButton = createButton(tr("getCurr"), SLOT(getCurrent()), tr("Calcola il valore della corrente ai capi del resistore selezionato, data una tensione"));

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    mainLayout->addWidget(ohmButton, 6, 3);
    mainLayout->addWidget(KohmButton, 6, 4);
    mainLayout->addWidget(MohmButton, 6, 5);
    mainLayout->addWidget(setValoreButton, 3, 0);
    mainLayout->addWidget(setTensDCButton, 5, 0);
    mainLayout->addWidget(setPotenzaButton, 4, 0);
    mainLayout->addWidget(getCurrentButton, 4, 5);
    setLayout(mainLayout);
    parent->setWindowTitle(tr("YouKalk <Resistore>"));
}
