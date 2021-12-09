#ifndef SPREADSHEETWINDOW_H
#define SPREADSHEETWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SpreadsheetWindow; }
QT_END_NAMESPACE

class SpreadsheetWindow : public QMainWindow
{
    Q_OBJECT

public:
    SpreadsheetWindow(QWidget *parent = nullptr);
    ~SpreadsheetWindow();

private slots:
    void on_actionClear_Table_triggered();
    void on_action_Quit_triggered();

private:
    Ui::SpreadsheetWindow *ui;

};
#endif // SPREADSHEETWINDOW_H
