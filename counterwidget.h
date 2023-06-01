#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QHBoxLayout>
#include <QPushButton>

class CounterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CounterWidget(QWidget *parent = nullptr);

    void setMinAndMaxValues(int minVal, int maxVal);
    void setMinAndMaxValues(double minVal, double maxVal);

    QLineEdit * lineEdit;


    int value;
    int minValue = 0;
    int maxValue = 100;


    void decrement();
    void increment();
    void updateLineEdit();
    void updateValue();

signals:
    void valueChanged();

};

#endif // COUNTERWIDGET_H
