#include "tablafuerzaswidget.h"

MyDelegate::MyDelegate(QObject* parent) : QItemDelegate(parent) {
}

QWidget* MyDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const {
    int column = index.column();
    QLineEdit* editor = new QLineEdit(parent);
    if (column == 0) {
        QValidator* validator = new QIntValidator(0, 999, editor);
        editor->setValidator(validator);
    } else if (column == 1) {
        QValidator* validator = new QDoubleValidator(0.0, 360.0, 2, editor);
        editor->setValidator(validator);
    } else if (column == 2){
        QValidator* validator = new QIntValidator(0, 999, editor);
        editor->setValidator(validator);
    }

    return editor;
}

TablaFuerzasWidget::TablaFuerzasWidget(QWidget *parent) : QTableWidget(parent)
{
    this->setItemDelegate(new MyDelegate);

    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    this->setRowCount(0);
    this->setColumnCount(3);
    this->setHorizontalHeaderLabels({"Magnitud (N)","Dirección (grados)","# Nudo"});
    this->setEditTriggers(QAbstractItemView::DoubleClicked);
    this->setCornerButtonEnabled(true);

    this->addRow();
}

void TablaFuerzasWidget::keyPressEvent(QKeyEvent* event) {
        if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
            addRow();
        } else if (event->key() == Qt::Key_Backspace) {
            deleteSelectedRows();
        } else {
            QTableWidget::keyPressEvent(event);
        }
    }

void TablaFuerzasWidget::addRow() {
        int row = rowCount();
        insertRow(row);

        setItem(row, 0, new QTableWidgetItem(QString::number(0)));
        setItem(row, 1, new QTableWidgetItem(QString::number(0)));
        setItem(row, 2, new QTableWidgetItem(QString::number(0)));
        this->resizeColumnsToContents();
    }



void TablaFuerzasWidget::deleteSelectedRows() {
        QList<QTableWidgetItem*> selectedItems = this->selectedItems();
        if (selectedItems.isEmpty()) {
            return;
        }

        // Collect unique rows for deletion
        QSet<int> rows;
        foreach (QTableWidgetItem* item, selectedItems) {
            rows.insert(item->row());
        }

        // Remove rows in descending order
        QList<int> sortedRows = rows.toList();
        qSort(sortedRows.begin(), sortedRows.end(), qGreater<int>());

        foreach (int row, sortedRows) {
            removeRow(row);
        }
}
