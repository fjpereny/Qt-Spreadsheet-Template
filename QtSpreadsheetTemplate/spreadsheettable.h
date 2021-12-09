#ifndef SPREADSHEETTABLE_H
#define SPREADSHEETTABLE_H

#include <QTableWidget>

class SpreadsheetTable : public QTableWidget
{
public:
    SpreadsheetTable(QWidget *parent = nullptr, int rows = 100, int cols = 100);
    ~SpreadsheetTable();

    QStringList *headers = new QStringList();
    QString get_header_letters(int column);

private slots:
    void keyPressEvent(QKeyEvent *event);
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void add_visible_rows();
    void add_visible_cols();

private:

};

#endif // SPREADSHEETTABLE_H
