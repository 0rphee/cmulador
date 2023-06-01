#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QApplication>

#include "ventanapalanca.h"
#include "ventanaArmadura.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
   QPushButton * botonPalanca;
   QPushButton * botonArmadura;

   VentanaArmadura * ventanaArmadura;
   VentanaPalanca * ventanaPalanca;

   void	updateButtonStyles();
};
#endif // MAINWINDOW_H
