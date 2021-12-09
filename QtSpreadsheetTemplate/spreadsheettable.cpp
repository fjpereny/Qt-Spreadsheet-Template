#include "spreadsheettable.h"

#include <QKeyEvent>
#include <iostream>

SpreadsheetTable::SpreadsheetTable(QWidget *parent, int rows, int cols)
    : QTableWidget(parent)
    , headers(new QStringList)
{
    setRowCount(rows);
    setColumnCount(cols);

    for (int i=1; i<=cols; ++i)
        headers->push_back(get_header_letters(i));
    setHorizontalHeaderLabels(*headers);
}

SpreadsheetTable::~SpreadsheetTable()
{
    delete headers;
}

void SpreadsheetTable::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
        setCurrentCell(currentIndex().row() + 1, currentIndex().column());
        edit(currentIndex());
    }

    else
        QTableWidget::keyPressEvent(event);

}


void SpreadsheetTable::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    double percent_from_end_row = (double)currentRow() / (double)rowCount();
    double percent_from_end_col = (double)currentColumn() / (double)columnCount();
    if (percent_from_end_row > 0.90)
        add_visible_rows();
    if (percent_from_end_col > 0.90)
        add_visible_cols();
}


void SpreadsheetTable::add_visible_rows()
{
    setRowCount(rowCount() + 100);
}

void SpreadsheetTable::add_visible_cols()
{
    setColumnCount(columnCount() + 100);
    QStringList new_headers;
    for (int i=0; i<100; ++i)
    {
        int index = columnCount() - i;
        new_headers.push_front(get_header_letters(index));
    }
    *headers += new_headers;
    setHorizontalHeaderLabels(*headers);
}

QString SpreadsheetTable::get_header_letters(int column)
{
    QString result = QString();
    while (--column >= 0)
    {
        result = (char)('A' + column % 26) + result;
        column /= 26;
    }
    return result;
}
