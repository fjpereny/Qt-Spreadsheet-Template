#include "spreadsheetwindow.h"
#include "ui_spreadsheetwindow.h"
#include "spreadsheettable.h"

#include <QKeyEvent>
#include <QModelIndex>

SpreadsheetWindow::SpreadsheetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpreadsheetWindow)
{
    ui->setupUi(this);
}

SpreadsheetWindow::~SpreadsheetWindow()
{
    delete ui;
}


// Menu Actions

void SpreadsheetWindow::on_actionClear_Table_triggered()
{
    ui->sheet->clearContents();
}

void SpreadsheetWindow::on_action_Quit_triggered()
{
    close();
}
