#include "mainwindow.h"
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStatusBar>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QStringList>
#include <QStandardItem>
#include <QHBoxLayout>
#include <QSpacerItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->ventanaArmadura = new VentanaArmadura();
    this->ventanaArmadura->hide();

    this->setMinimumSize(660, 500);
    this->setMaximumSize(660, 500);
    // this->resize(800, 550);


    this->botonPalanca = new QPushButton("Realizar cálculos\nde palanca",this);
    this->botonPalanca->setGeometry(120, 50, 150, 75);

    this->botonArmadura = new QPushButton("Realizar cálculos\nde armadura",this);
    this->botonArmadura->setGeometry(390, 50, 150, 75);
    this->connect(this->botonArmadura, &QPushButton::released, this->ventanaArmadura, &VentanaArmadura::show);
}

MainWindow::~MainWindow()
{
}

