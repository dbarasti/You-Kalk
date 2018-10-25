#include <QtWidgets>
#include<QStatusBar>
#include<QListWidget>
#include "Application.h"
#include "kalkC.h"
#include "kalkI.h"
#include "kalkR.h"

Application::Application():operando1(nullptr), operando2(nullptr), risultato(nullptr), calcRCL(nullptr)
{
    createActions();
    createMenus();
    createDockWindows();
    createStatusBar();
    ResistorAct->trigger();
    setFixedSize(minimumSize());
}

void Application::valueChanged()
{
    if(dynamic_cast<calcR*>(calcRCL)){
        Resistore *op1_res_cast = dynamic_cast<Resistore*>(operando1);
        Resistore *op2_res_cast = dynamic_cast<Resistore*>(operando2);
        Resistore *ris_res_cast = dynamic_cast<Resistore*>(risultato);
        info->setText("Operando1: \n" + operando1->valorePrincipaleString() + "\nPotenza: " + op1_res_cast->potenzaString() + "\nPmax: " + op1_res_cast->potenzaMaxString() + "\n"
                      + "Tensione: " + operando1->tensioneDCString()+ "\n" + "Corrente: " + op1_res_cast->correnteString() + "\n\nOperando2: \n" + operando2->valorePrincipaleString() + "\nPotenza: " + op2_res_cast->potenzaString() + "\nPmax: " + op2_res_cast->potenzaMaxString() + "\n"
                      + "Tensione: " + operando2->tensioneDCString() + "\n" + "Corrente: " + op2_res_cast->correnteString() + "\n\nRisultato:\n" + risultato->valorePrincipaleString() + "\nPmax: " + ris_res_cast->potenzaMaxString() + "\n");
    }
    if(dynamic_cast<calcC*>(calcRCL)){
        Condensatore *op1_con_cast = dynamic_cast<Condensatore*>(operando1);
        Condensatore *op2_con_cast = dynamic_cast<Condensatore*>(operando2);
        double FT1 = 5 * operando1->getValorePrincipale() * op1_con_cast->getResistenza();
        double FT2 = 5 * operando2->getValorePrincipale() * op2_con_cast->getResistenza();
        //Condensatore *ris_con_cast = dynamic_cast<Condensatore*>(risultato);
        info->setText("Operando1: \n" + operando1->valorePrincipaleString() + "\nResistenza carica: " + op1_con_cast->resistenzaString() + "\n" + "Tcarica: "
                      + op1_con_cast->t_caricaString()+ "\n" + "Tensione applicata: " + operando1->tensioneDCString() +  "\nTensione raggiunta: " + QString::number(op1_con_cast->V(FT1)) + "V\n" + "\nOperando2:\n" + operando2->valorePrincipaleString() +
                      "\nResistenza carica: " + op2_con_cast->resistenzaString() + "\nTcarica: " + op2_con_cast->t_caricaString() + "\n" + "Tensione applicata: " + operando2->tensioneDCString() +
                      "\nTensione raggiunta: " + QString::number(op2_con_cast->V(FT2)) + "V" + "\n\n\n\n\n");
    }
    if(dynamic_cast<calcI*>(calcRCL)){
        Induttore *op1_ind_cast = dynamic_cast<Induttore*>(operando1);
        Induttore *op2_ind_cast = dynamic_cast<Induttore*>(operando2);
        info->setText("Operando1: \n" + operando1->valorePrincipaleString() + "\nResistenza circuito: " + op1_ind_cast->resistenzaString() +
                      "\n" + "Tensione applicata: " + operando1->tensioneACString() +  "\nFrequenza: " + operando1->frequenzaString() + "\nRMS: " + op1_ind_cast->rmsString() + "\nω: " + QString::number(op1_ind_cast->getPulsazione()) +
                      "rad/s\ntg(φ): " + QString::number(op1_ind_cast->getSfasamento(), 'g', 3) + + "\n\nOperando2:\n" + operando2->valorePrincipaleString() + "\nResistenza circuito: " + op2_ind_cast->resistenzaString() + + "\n" + "Tensione applicata: " +
                      operando2->tensioneACString() +  "\nFrequenza: " + operando2->frequenzaString() + "\nRMS: " + op2_ind_cast->rmsString() + "\nω: " + QString::number(op2_ind_cast->getPulsazione()) + "rad/s\ntg(φ): " + QString::number(op2_ind_cast->getSfasamento(), 'g', 3)+"\n" );
    }
}

void Application::createDockWindows()
{
    dock = new QDockWidget(tr("Info"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    info = new QLabel(dock);
    dock->setWidget(info);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void Application::createStatusBar()
{
    statusBar()->showMessage(tr("Pronto"), 3000);
}

void Application::createActions()
{
    ResistorAct = new QAction(tr("&ResistorKALK"), this);
    ResistorAct->setStatusTip(tr("Apri una nuova sessione di ResistorKALK"));
    connect(ResistorAct, SIGNAL(triggered()), this, SLOT(resistorCalc()));

    CapacitorAct = new QAction(tr("&CapacitorKALK"), this);
    CapacitorAct->setStatusTip(tr("Apri una nuova sessione di CapacitorKALK"));
    connect(CapacitorAct, SIGNAL(triggered()), this, SLOT(capacitorCalc()));

    InductorAct = new QAction(tr("&InductorKALK"), this);
    InductorAct->setStatusTip(tr("Apri una nuova sessione di InductorKALK"));
    connect(InductorAct, SIGNAL(triggered()), this, SLOT(inductorCalc()));
}
void Application::createMenus()
{
    kalkMenu = menuBar()->addMenu(tr("&KALK"));
    kalkMenu->addAction(ResistorAct);
    kalkMenu->addAction(CapacitorAct);
    kalkMenu->addAction(InductorAct);
}

void Application::resistorCalc()
{  
    if(operando1 != nullptr){
        delete operando1;
        delete operando2;
        operando1 = nullptr;
        operando2 = nullptr;
        if(risultato != nullptr) { delete risultato; risultato = nullptr; }
    }
    if(calcRCL != nullptr){
        delete calcRCL;
        calcRCL = nullptr;
    }
    operando1 = new Resistore;
    operando2 = new Resistore;
    risultato = new Resistore;
    calcRCL = new calcR(this);
    setCentralWidget(calcRCL);
    valueChanged();
}

void Application::capacitorCalc()
{
    if(operando1 != nullptr){
        delete operando1;
        delete operando2;
        operando1 = nullptr;
        operando2 = nullptr;
        if(risultato != nullptr) { delete risultato; risultato = nullptr; }
    }
    if(calcRCL != nullptr){
        delete calcRCL;
        calcRCL = nullptr;
    }
    operando1 = new Condensatore();
    operando2 = new Condensatore();
    risultato = new Condensatore();
    calcRCL = new calcC(this);
    setCentralWidget(calcRCL);
    valueChanged();
}

void Application::inductorCalc()
{
    if(operando1 != nullptr){
        delete operando1;
        delete operando2;
        operando1 = nullptr;
        operando2 = nullptr;
        if(risultato != nullptr) { delete risultato; risultato = nullptr; }
    }
    if(calcRCL != nullptr){
        delete calcRCL;
        calcRCL = nullptr;
    }
    operando1 = new Induttore();
    operando2 = new Induttore();
    risultato = new Induttore();
    calcRCL = new calcI(this);
    setCentralWidget(calcRCL);
    valueChanged();
}

void Application::setInfoText()
{
    Button* hovered = qobject_cast<Button*>(sender());
    statusBar()->showMessage(hovered->info, 2000);
}

//controllore

void Application::digitClicked()
{
    Display* disp = displayWithFocus();
    if(disp){
        Button *clickedButton = qobject_cast<Button *>(sender());
        int digitValue = clickedButton->text().toInt();
        if (disp->text() == "0" && digitValue == 0.0)
            return;
        if(disp->text()=="0" || disp->writable == false ){
            disp->clear();
            disp->writable = true;
        }
        disp->setText(disp->text() + QString::number(digitValue));
    }
}


Display *Application::displayWithFocus()
{
    if(calcRCL->displayLeft->hasFocus())
        return calcRCL->displayLeft;
    if(calcRCL->displayRight->hasFocus())
        return calcRCL->displayRight;
    return NULL;
}

ComponenteElettrico *Application::operandWithFocus()
{
    if(displayWithFocus() == calcRCL->displayLeft)
        return operando1;
    if(displayWithFocus() == calcRCL->displayRight)
        return operando2;
    return NULL;
}

void Application::setOperandWithPrefix(const char & pref)
{
    Display* disp = displayWithFocus();
    if(disp){
        ComponenteElettrico * operando = operandWithFocus();
        operando->setUnitaPrincipale(pref);
        disp->setText(operando->valorePrincipaleString());
        disp->writable = false;
        valueChanged();
    }
}

void Application::unaryOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    ComponenteElettrico * operando = operandWithFocus();
    if(operando){
        if (clickedOperator == tr("Nrml")){
            operando->normalizza();
            displayWithFocus()->setText(operando->valorePrincipaleString());
            valueChanged();
        }
    }
}

void Application::additiveOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    try{
        calculate(clickedOperator);
        calcRCL->displayResult->setText( risultato->valorePrincipaleString() );
        Resistore* res_cast = dynamic_cast<Resistore*>(risultato);
        if(res_cast)
            calcRCL->displayResult->setText(calcRCL->displayResult->text() + " MaxPow: " + res_cast->potenzaMaxString() );
        valueChanged();
    }
    catch(BadOperation e){
        statusBar()->showMessage(e.what(), 2500);
    }
}

void Application::pointClicked()
{
    Display* disp = displayWithFocus();
    if(disp)
        if (!disp->text().contains('.'))
            disp->setText(disp->text() + tr("."));
}

void Application::backspaceClicked()
{
    Display* disp = displayWithFocus();
    if(disp && disp->writable){
        QString text = disp->text();
        text.chop(1);
        if (text.isEmpty()) {
            text = "0";
        }
        disp->setText(text);
    }
}

void Application::copyRightClicked(){
    if(risultato->getValorePrincipale() > 0){
        ComponenteElettrico* aux = operando2;
        operando2 = risultato->copy();
        delete aux;
        calcRCL->displayRight->setText( operando2->valorePrincipaleString());
        calcRCL->displayLeft->writable = false;
        valueChanged();
    }
}

void Application::copyLeftClicked(){
    if(risultato->getValorePrincipale() > 0){
        ComponenteElettrico *aux = operando1;
        operando1 = risultato->copy();
        delete aux;
        calcRCL->displayLeft->setText( operando1->valorePrincipaleString() );
        calcRCL->displayLeft->writable = false;
        valueChanged();
    }
}

void Application::clear()
{
    Display * disp = displayWithFocus();
    if(disp)
        disp->setText("0");
}

void Application::clearOp()
{
    calcRCL->displayResult->setText("0");
    Display * disp = displayWithFocus();
    if(disp){
        operandWithFocus()->reset();
        disp->setText("0");
        valueChanged();
    }
}

void Application::setValore()
{
    Display * disp = displayWithFocus();
    if(disp && disp->writable){
        ComponenteElettrico * operando = operandWithFocus();
        operandWithFocus()->setValorePrincipale(disp->text().toDouble());
        disp->setText(operando->valorePrincipaleString());
        disp->writable = false;
        valueChanged();
    }
}

void Application::setPotenza()
{
    Display * disp = displayWithFocus();
    if(disp && disp->writable){
        Resistore* op_cast = dynamic_cast<Resistore*>(operandWithFocus());
        op_cast->setPotenzaMax(disp->text().toDouble());
        disp->setText(op_cast->potenzaMaxString());
        disp->writable = false;
        valueChanged();
    }
}

void Application::setResistenza()
{
    Display *disp = displayWithFocus();
    if(disp && disp->writable){
        if(dynamic_cast<Condensatore*>(operandWithFocus())){
            Condensatore * operando = static_cast<Condensatore*>(operandWithFocus());
            operando->setResistenza(disp->text().toDouble());
            disp->setText(operando->resistenzaString());
        }
        if(dynamic_cast<Induttore*>(operandWithFocus())){
            Induttore * operando = static_cast<Induttore*>(operandWithFocus());
            operando->setResistenza(disp->text().toDouble());
            disp->setText(operando->resistenzaString());
        }
        disp->writable = false;
        valueChanged();
    }
}

void Application::setTensioneDC()
{
    Display * disp = displayWithFocus();
    if(disp && disp->writable){
        ComponenteElettrico * operando = operandWithFocus();
        operando->setTensioneDC(disp->text().toDouble());
        disp->setText(operando->tensioneDCString());
        disp->writable = false;
        valueChanged();
    }
}

void Application::setTensioneAC()
{
    Display * disp = displayWithFocus();
    if(disp && disp->writable){
        ComponenteElettrico * operando = operandWithFocus();
        operando->setTensioneAC(disp->text().toDouble());
        disp->setText(operando->tensioneACString() + " " + operando->frequenzaString());
        disp->writable = false;
        valueChanged();
    }
}

void Application::setFrequenza()
{
    Display *disp = displayWithFocus();
    if(disp && disp->writable){
        ComponenteElettrico * operando = operandWithFocus();
        operando->setFrequenza(disp->text().toDouble());
        disp->setText(operando->tensioneACString() + " " + operando->frequenzaString());
        disp->writable = false;
        valueChanged();
    }
}

void Application::getCurrent()
{
    Display* disp = displayWithFocus();
    ComponenteElettrico *operando = operandWithFocus();
    try{
        if(disp){
            if(dynamic_cast<Resistore*>(operandWithFocus())){
                Resistore* op_cast = dynamic_cast<Resistore*>(operando);
                op_cast->setCorrente();
                calcRCL->displayResult->setText(op_cast->valorePrincipaleString() + " " + op_cast->tensioneDCString() + " " + op_cast->correnteString());
                try{op_cast->setPotenza();}
                catch(Alert a){statusBar()->showMessage(a.what());}
            }
            if(dynamic_cast<Induttore*>(operandWithFocus())){
                Induttore* op_cast = dynamic_cast<Induttore*>(operando);
                op_cast->setCorrente();
                calcRCL->displayResult->setText(op_cast->valorePrincipaleString() + " " + op_cast->tensioneACString() + " " + op_cast->correnteString());
            }
            valueChanged();
        }
    }
    catch(BadOperation e){
        statusBar()->showMessage(e.what(), 2500);
    }
}

void Application::getTCarica()
{
    Display * disp = displayWithFocus();
    ComponenteElettrico * operando = operandWithFocus();
    try{
        if(disp){
            Condensatore* op_cast = dynamic_cast<Condensatore*>(operando);
            op_cast->setT_carica();
            calcRCL->displayResult->setText(op_cast->valorePrincipaleString() + " " + op_cast->tensioneDCString() + " " + op_cast->t_caricaString());
            disp->writable = false;
            valueChanged();
        }
    }
    catch(BadOperation e){
        statusBar()->showMessage(e.what(), 2500);
    }
}

void Application::setPref()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    char prefix = clickedButton->text().toStdString().at(0);
    if(prefix == ' ')
        setOperandWithPrefix('\0');
    else
        setOperandWithPrefix(prefix);
}

void Application::calculate(const QString &pendingOperator)
{
    if (pendingOperator == tr("//")) {
            ComponenteElettrico* aux = risultato;
            risultato = operando1->parallelo(operando2);
            delete aux;
    }else if (pendingOperator == tr("--")) {
        ComponenteElettrico* aux = risultato;
        risultato = operando1->serie(operando2);
        delete aux;
    }
}
