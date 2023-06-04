#include "resultadoswidget.h"

ResultadosWidget::ResultadosWidget(QWidget *parent) : QWidget(parent)
{
    this->setBackgroundRole(QPalette::Button);
    QGridLayout* layout = new QGridLayout(this);

    // Create and add the QLabel widgets
    this->label1 = new QLabel("Torca resultante\nen la armadura: ", this);
    this->label2 = new QLabel("Fuerza de reacción\nen el apoyo fijo: ", this);
    this->label3 = new QLabel("Fuerza de reacción\nen el apoyo móvil: ", this);

    this->lineEdit1 = new QLineEdit(this);
    this->lineEdit2 = new QLineEdit(this);
    this->lineEdit3 = new QLineEdit(this);

    lineEdit1->setDisabled(true);
    lineEdit2->setDisabled(true);
    lineEdit3->setDisabled(true);

    layout->addWidget(label1, 0, 0);
    layout->addWidget(lineEdit1, 0, 1);

    layout->addWidget(label2, 1, 0);
    layout->addWidget(lineEdit2, 1, 1);

    layout->addWidget(label3, 2, 0);
    layout->addWidget(lineEdit3, 2, 1);

}
