#include "counterwidget.h"

CounterWidget::CounterWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    QPushButton* decrementButton = new QPushButton("-", this);
    QPushButton* incrementButton = new QPushButton("+", this);
    lineEdit = new QLineEdit("0", this);

    layout->addWidget(decrementButton);
    layout->addWidget(lineEdit);
    layout->addWidget(incrementButton);

    connect(decrementButton, &QPushButton::clicked, this, &CounterWidget::decrement);
    connect(incrementButton, &QPushButton::clicked, this, &CounterWidget::increment);
    connect(lineEdit, &QLineEdit::editingFinished, this, &CounterWidget::updateValue);
    this->setGeometry(0,0,175,50);
}

void CounterWidget::setMinAndMaxValues(int minVal, int maxVal){
    this->esInt = true;
    this->maxValue = maxVal;
    this->minValue = minVal;
    lineEdit->setValidator(new QIntValidator(minValue, maxValue, this));
    value = minVal;
    updateLineEdit();
}

void CounterWidget::setMinAndMaxValues(double minVal, double maxVal){
    this->esInt = false;
    this->dmaxValue = maxVal;
    this->dminValue = minVal;
    lineEdit->setValidator(new QDoubleValidator(minValue, maxValue, 2, this));
    dvalue = minVal;
    updateLineEdit();
}


void CounterWidget::decrement() {

    if ((value > minValue) && esInt){
       value--;
    }else if (dvalue > dminValue){
        dvalue--;
    }
    updateLineEdit();
    emit valueChanged();
}

void CounterWidget::increment() {
    if ((value < maxValue) && esInt){
        value++;
    } else if (dvalue < dmaxValue){
        dvalue++;
    }
    updateLineEdit();
    emit valueChanged();
 }

void CounterWidget::updateLineEdit() {
    if (esInt){
        lineEdit->setText(QString::number(value));
    } else{
        lineEdit->setText(QString::number(dvalue));
    }
}

void CounterWidget::updateValue() {
    if (esInt){
        value = lineEdit->text().toInt();
    } else{
        dvalue = lineEdit->text().toDouble();
    }
    emit valueChanged();
}


