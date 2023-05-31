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
    this->setMinimumSize(660, 418);
    this->setMaximumSize(660, 418);
    this->setWindowTitle("cmulador");

    this->ventanaArmadura = new VentanaArmadura();
    this->ventanaArmadura->hide();

    QGridLayout* mainLayout = new QGridLayout();

    QLabel* imageLabel1 = new QLabel(this);
    QPixmap pixmap1("/Users/roger/Documents/Dev/up/pa/cmulador/palanca.png");

    imageLabel1->setPixmap(pixmap1);
    imageLabel1->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(imageLabel1, 0, 0);

    QLabel* imageLabel2 = new QLabel(this);
    QPixmap pixmap2("/Users/roger/Documents/Dev/up/pa/cmulador/armadura.png");
    imageLabel2->setPixmap(pixmap2);
    imageLabel2->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(imageLabel2, 0, 1);


    this->connect(qApp, &QApplication::paletteChanged, this, &MainWindow::updateButtonStyles);

    this->botonPalanca = new QPushButton("Realizar cálculos\nde palanca", this);
    this->botonPalanca->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(this->botonPalanca, 1, 0);

    this->botonArmadura = new QPushButton("Realizar cálculos\nde armadura", this);
    this->botonArmadura->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->connect(this->botonArmadura, &QPushButton::released, this->ventanaArmadura, &VentanaArmadura::show);
    mainLayout->addWidget(this->botonArmadura, 1, 1);



    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateButtonStyles()
{
    QPalette palette = QApplication::palette();
    bool isDarkTheme = (palette.color(QPalette::Window).value() < 128);

    QString buttonStyle = "QPushButton { border-radius: 6px; }";
    buttonStyle += " QPushButton:hover { background-color: rgba(4, 122, 255, 0.5); }";

    if (isDarkTheme) {
        buttonStyle += " QPushButton { background-color: rgba(97, 97, 97, 1); border: 1px solid hex(2c2c2c); };";
    } else {
        buttonStyle += " QPushButton { background-color: rgba(255, 255, 255, 1); border: 1px solid rgb(215, 215, 215); };";
    }

    this->botonPalanca->setStyleSheet(buttonStyle);
    this->botonArmadura->setStyleSheet(buttonStyle);
}
