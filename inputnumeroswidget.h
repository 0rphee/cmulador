#ifndef INPUTNUMEROSWIDGET_H
#define INPUTNUMEROSWIDGET_H

#include "counterwidget.cpp"
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>


class InputNumerosWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputNumerosWidget(QWidget *parent = nullptr);
    explicit InputNumerosWidget(QString prompt, int maxValue, int minValue, QWidget *parent = nullptr);
    CounterWidget * counterWidget;
    QLabel * label;

//signals:

};

#endif // INPUTNUMEROSWIDGET_H
