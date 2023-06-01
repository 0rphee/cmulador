#ifndef ARMADURA_H
#define ARMADURA_H

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
#include "counterwidget.h"
#include "inputnumeroswidget.h"
#include "tablafuerzaswidget.h"
#include "resultadoswidget.h"


class VentanaArmadura : public QWidget
{
    Q_OBJECT
public:
    VentanaArmadura(QWidget *parent = nullptr);
    InputNumerosWidget * WinputAltura;
    InputNumerosWidget * WinputLongitud;
    InputNumerosWidget * WinputNudos;
    ResultadosWidget * Wresultados;
    TablaFuerzasWidget * WtablaInputFuerzas;
private:
    void updateLabels();

signals:

};

#endif // ARMADURA_H
