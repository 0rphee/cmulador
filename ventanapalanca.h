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


#include "funciones.h"
#include "counterwidget.h"
#include "inputnumeroswidget.h"
#include "tablafuerzaswidget.h"
#include "resultadoswidget.h"


class VentanaPalanca : public QWidget
{
    Q_OBJECT
public:
    explicit VentanaPalanca(QWidget *parent = nullptr);

    InputNumerosWidget * WinputLongitud;
    InputNumerosWidget * WinputUbicacionFulcro;
    QPushButton * WbotonResultados;
    ResultadosWidget * Wresultados;
    TablaFuerzasWidget * WtablaInputFuerzas;

private:
    void updateLabels();

};

#endif // VENTANAPALANCA_H
