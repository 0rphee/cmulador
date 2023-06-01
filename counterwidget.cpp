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
    this->maxValue = maxVal;
    this->minValue = minVal;
    lineEdit->setValidator(new QIntValidator(minValue, maxValue, this));
    value = minVal;
    updateLineEdit();
}


void CounterWidget::decrement() {
    if (value > minValue){
       value--;
    }
    updateLineEdit();
    emit valueChanged();
}

void CounterWidget::increment() {
    if (value < maxValue){ value++; }
    updateLineEdit();
    emit valueChanged();
 }

void CounterWidget::updateLineEdit() {
    lineEdit->setText(QString::number(value));
}

void CounterWidget::updateValue() {
    value = lineEdit->text().toInt();
    emit valueChanged();
}


