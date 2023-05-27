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
    this->setMinimumSize(660, 500);
    this->setMaximumSize(660, 500);
    this->setWindowTitle("cmulador");

    this->ventanaArmadura = new VentanaArmadura();
    this->ventanaArmadura->hide();

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    this->botonPalanca = new QPushButton("Realizar cálculos\nde palanca", this);
    this->botonPalanca->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->botonPalanca->setStyleSheet("QPushButton { background-image: url(/Users/roger/Documents/Dev/up/pa/cmulador/palanca.png); \
                                                      border-radius: 6px; \
                                                      border: 1px solid rgb(215, 215, 215) } \
                                       QPushButton:hover { background-color: rgba(4, 122, 255, 0.5); } \
                                       QPushButton { background-color: rgba(255, 255, 255, 1); };");

    this->botonArmadura = new QPushButton("Realizar cálculos\nde armadura", this);
    this->botonArmadura->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->botonArmadura->setStyleSheet("QPushButton { background-image: url(/Users/roger/Documents/Dev/up/pa/cmulador/armadura.png); \
                                                      border-radius: 6px; \
                                                      border: 1px solid rgb(215, 215, 215) } \
                                       QPushButton:hover { background-color: rgba(4, 122, 255, 0.5); } \
                                       QPushButton { background-color: rgba(255, 255, 255, 1); };");
    this->connect(this->botonArmadura, &QPushButton::released, this->ventanaArmadura, &VentanaArmadura::show);

    buttonLayout->addWidget(this->botonPalanca);
    buttonLayout->addWidget(this->botonArmadura);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(buttonLayout);
    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}
