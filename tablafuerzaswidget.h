#ifndef TABLAFUERZASWIDGET_H
#define TABLAFUERZASWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <iostream>
#include <QKeyEvent>
#include <QItemDelegate>
#include <QLineEdit>


class TablaFuerzasWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TablaFuerzasWidget(QWidget *parent = nullptr);
    bool esArmadura;

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    void addRow();
    void deleteSelectedRows();

signals:
    void tableDataChanged();
};

class MyDelegate : public QItemDelegate {
    Q_OBJECT

public:
    explicit MyDelegate(QObject* parent = nullptr);
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

class MyDelegateP : public QItemDelegate {
    Q_OBJECT

public:
    explicit MyDelegateP(QObject* parent = nullptr);
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};



#endif // TABLAFUERZASWIDGET_H
