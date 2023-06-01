#ifndef PRESULTADOSWIDGET_H
#define PRESULTADOSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

class PResultadosWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PResultadosWidget(QWidget *parent = nullptr);

    QLabel * label;
    QLineEdit * lineEdit;

signals:

};

#endif // PRESULTADOSWIDGET_H
