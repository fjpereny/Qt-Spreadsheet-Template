#include "spreadsheetwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpreadsheetWindow w;
    w.show();
    return a.exec();
}
