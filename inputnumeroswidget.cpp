#include "inputnumeroswidget.h"

InputNumerosWidget::InputNumerosWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout(this);
    QLabel * label = new QLabel("value",this);

    this->counterWidget = new CounterWidget(this);
    this->counterWidget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    layout->addWidget(label);
    layout->addWidget(counterWidget);
}

InputNumerosWidget::InputNumerosWidget(QString prompt, int minValue, int maxValue, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout(this);

    QLabel * label = new QLabel(prompt,this);

    this->counterWidget = new CounterWidget(this);
    this->counterWidget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    this->counterWidget->setMinAndMaxValues(minValue, maxValue);

    layout->addWidget(label);
    layout->addWidget(counterWidget);
}
