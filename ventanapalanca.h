#pragma once
#ifndef VENTANAPALANCA_H
#define VENTANAPALANCA_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStatusBar>
#include <QTableWidget>
#include <QStringList>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QDialog>

#include <iostream>

#include "funciones.h"
#include "counterwidget.h"
#include "inputnumeroswidget.h"
#include "tablafuerzaswidget.h"
#include "resultadoswidget.h"
#include "presultadoswidget.h"


class VentanaPalanca : public QWidget
{
    Q_OBJECT
public:
    explicit VentanaPalanca(QWidget *parent = nullptr);

    InputNumerosWidget * WinputLongitud;
    InputNumerosWidget * WinputUbicacionFulcro;
    QPushButton * WbotonResultados;
    PResultadosWidget* Wresultados;
    TablaFuerzasWidget * WtablaInputFuerzas;

private:
    void updateLabels();

};

#endif // VENTANAPALANCA_H
