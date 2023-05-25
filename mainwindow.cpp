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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(550, 800);
    this->botonPalanca = new QPushButton(this);
    this->botonPalanca->setGeometry(50, 50, 200, 100);
    this->botonPalanca->setText("boton");
}

MainWindow::~MainWindow()
{
}

