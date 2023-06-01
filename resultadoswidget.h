#ifndef RESULTADOSWIDGET_H
#define RESULTADOSWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>

class ResultadosWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ResultadosWidget(QWidget *parent = nullptr);

    // Create and add the QLabel widgets
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;

    QLineEdit* lineEdit1;
    QLineEdit* lineEdit2;
    QLineEdit* lineEdit3;

signals:

};

#endif // RESULTADOSWIDGET_H
