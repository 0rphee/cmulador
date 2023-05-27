#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStatusBar>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QStringList>
#include <QStandardItem>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPropertyAnimation>
#include "counterwidget.cpp"
#include "inputnumeroswidget.h"
#include "tablafuerzaswidget.h"

#ifndef ARMADURA_H
#define ARMADURA_H

class VentanaArmadura : public QWidget
{
    Q_OBJECT
public:
    VentanaArmadura(QWidget *parent = nullptr);
    InputNumerosWidget * WinputAltura;
    InputNumerosWidget * WinputLongitud;
    QWidget * Wresultados;
    TablaFuerzasWidget * WtablaInputFuerzas;
private:

signals:

};

#endif // ARMADURA_H
