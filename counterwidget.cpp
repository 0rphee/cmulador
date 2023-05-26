#pragma once

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>

class CounterWidget : public QWidget {
public:
    explicit CounterWidget(QWidget* parent = nullptr) : QWidget(parent) {
        QHBoxLayout* layout = new QHBoxLayout(this);

        QPushButton* decrementButton = new QPushButton("-", this);
        QPushButton* incrementButton = new QPushButton("+", this);
        lineEdit = new QLineEdit("0", this);
        // lineEdit->setValidator(new QIntValidator(0, maxValue, this)); // Restrict input to integers from 0 to 999

        layout->addWidget(decrementButton);
        layout->addWidget(lineEdit);
        layout->addWidget(incrementButton);

        connect(decrementButton, &QPushButton::clicked, this, &CounterWidget::decrement);
        connect(incrementButton, &QPushButton::clicked, this, &CounterWidget::increment);
        connect(lineEdit, &QLineEdit::editingFinished, this, &CounterWidget::updateValue);
        this->setGeometry(0,0,175,50);
    }

    QLineEdit* lineEdit;

    void setMinAndMaxValues(int minVal, int maxVal){
        this->maxValue = maxVal;
        this->minValue = minVal;
        lineEdit->setValidator(new QIntValidator(minValue, maxValue, this));
        value = minVal;
        updateLineEdit();
    }
private:

    int maxValue;
    int minValue = 0;
    int value = minValue;

    void decrement() {
        if (value > minValue){
            value--;
        }
        updateLineEdit();
    }

    void increment() {
        if (value < maxValue){ value++; }
        updateLineEdit();
    }

    void updateLineEdit() {
        lineEdit->setText(QString::number(value));
    }

    void updateValue() {
        value = lineEdit->text().toInt();
    }
};
