#include <QApplication>
#include <QMainWindow>
#include <Application.h>
#include <spec_udm.cpp>
#include <spec_misura.cpp>

int main(int argc, char *argv[])
{
    if(true){
        QApplication a(argc, argv);
        Application mainWin;
        mainWin.show();
        return a.exec();
    } else {
        misura_spec();
        udm_spec();
    }
}
