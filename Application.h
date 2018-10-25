#ifndef APP_H
#define APP_H
#include<QMainWindow>
#include<QListWidget>
#include"display_mod.h"
#include<QLabel>
#include<QAction>
#include "kalk.h"
#include<resistore.h>
#include<condensatore.h>
#include<induttore.h>


class calc;

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application();

protected slots:
    virtual void digitClicked();
    virtual void unaryOperatorClicked();
    virtual void additiveOperatorClicked();
    virtual void pointClicked();
    virtual void backspaceClicked();
    virtual void clear();
    virtual void clearOp();
    virtual void setValore();
    virtual void setPotenza();
    virtual void setResistenza();
    virtual void setTensioneDC();
    virtual void setTensioneAC();
    virtual void setFrequenza();
    virtual void getCurrent();
    virtual void getTCarica();
    virtual void setPref();
    virtual void copyRightClicked();
    virtual void copyLeftClicked();
    virtual void setInfoText();
protected:
    void createDockWindows();
    void createStatusBar();
    void createActions();
    void createMenus();

    Display * displayWithFocus();
    ComponenteElettrico * operandWithFocus();
    void setOperandWithPrefix(const char&);

    QMenu *kalkMenu;
    QAction *ResistorAct;
    QAction *CapacitorAct;
    QAction *InductorAct;

    ComponenteElettrico *operando1;
    ComponenteElettrico *operando2;
    ComponenteElettrico *risultato;

    void calculate(const QString &pendingOperator);
    void valueChanged();

    calc *calcRCL;
    QDockWidget * dock;
    QLabel *info;

private slots:
    void resistorCalc();
    void capacitorCalc();
    void inductorCalc();

};

#endif
