#include <QtGui/QApplication>

#include "MyWidget.h"

int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);

    MyWidget mywidget;
    mywidget.show();

    return app.exec();
}
