#include "presultadoswidget.h"

PResultadosWidget::PResultadosWidget(QWidget *parent) : QWidget(parent)
{
    this->label = new QLabel("Torca resultante\nen palanca:", this);
    this->lineEdit = new QLineEdit(this);

    this->lineEdit->setDisabled(true);

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(label);
    layout->addWidget(lineEdit);
    setLayout(layout);
}

