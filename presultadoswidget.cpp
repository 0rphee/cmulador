#include "presultadoswidget.h"

PResultadosWidget::PResultadosWidget(QWidget *parent) : QWidget(parent)
{
    this->label1 = new QLabel("Torca resultante en x\n en palanca:", this);
    this->lineEdit1 = new QLineEdit(this);

    this->label2 = new QLabel("Torca resultante en y\n en palanca:", this);
    this->lineEdit2 = new QLineEdit(this);

    this->lineEdit1->setDisabled(true);
    this->lineEdit2->setDisabled(true);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label1);
    layout->addWidget(lineEdit1);
    layout->addWidget(label2);
    layout->addWidget(lineEdit2);

    setLayout(layout);
}
