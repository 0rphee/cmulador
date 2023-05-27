#include "ventanaArmadura.h"
#include "tablafuerzaswidget.h"
#include "iostream"

class Lever : public QGraphicsItem {
public:
    Lever() : angle(0) {
        setFlag(ItemSendsGeometryChanges);
        setTransformOriginPoint(50, 0);
    }

    QRectF boundingRect() const override {
        return QRectF(-50, -50, 100, 100);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(Qt::red);
        painter->drawRoundedRect(-40, -5, 80, 10, 5, 5);
        painter->drawLine(0, -5, 0, -40);
    }

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override {
        if (change == ItemRotationChange) {
            angle = value.toDouble();
        }
        return QGraphicsItem::itemChange(change, value);
    }

    double getAngle() const {
        return angle;
    }

private:
    double angle;
};



VentanaArmadura::VentanaArmadura(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Armadura");

    this->setMinimumSize(660, 500);
    this->setMaximumSize(660, 500);

    this->WtablaInputFuerzas = new TablaFuerzasWidget(this);
    this->WtablaInputFuerzas->setGeometry(60, 10, 260, 480);

    this->WinputAltura = new InputNumerosWidget("Altura de armadura", 1, 99, this);
    this->WinputAltura->setGeometry(390, 38, 210, 90);

    this->WinputAltura = new InputNumerosWidget("Longitud de armadura", 1, 99, this);
    this->WinputAltura->setGeometry(390, 166, 210, 90);

    this->Wresultados = new QWidget(this);
    this->Wresultados->setBackgroundRole(QPalette::Button);
    QGridLayout* layout = new QGridLayout(Wresultados);

    // Create and add the QLabel widgets
    QLabel* label1 = new QLabel("Torca resultante\nen la armadura: ", Wresultados);
    QLabel* label2 = new QLabel("Fuerza de reacción\nen el apoyo fijo: ", Wresultados);
    QLabel* label3 = new QLabel("Fuerza de reacción\nen el apoyo móvil: ", Wresultados);

    QLineEdit* lineEdit1 = new QLineEdit(Wresultados);
    QLineEdit* lineEdit2 = new QLineEdit(Wresultados);
    QLineEdit* lineEdit3 = new QLineEdit(Wresultados);

    lineEdit1->setDisabled(true);
    lineEdit2->setDisabled(true);
    lineEdit3->setDisabled(true);

    layout->addWidget(label1, 0, 0);
    layout->addWidget(lineEdit1, 0, 1);

    layout->addWidget(label2, 1, 0);
    layout->addWidget(lineEdit2, 1, 1);

    layout->addWidget(label3, 2, 0);
    layout->addWidget(lineEdit3, 2, 1);

    this->Wresultados->setGeometry(390, 264, 210, 200);

    // Set the texts using a function
    // Assuming you have a function that updates the text based on some calculations
    // Replace the function call with your actual logic
    //auto updateTexts = [&label1, &label2, &label3]() {
    //    // Update the text of each QLabel widget
    //    label1->setText("Torca resultante en la armadura: " + QString::number(calculateTorque()) + " Nm");
    //    label2->setText("Fuerza de reacción en el apoyo fijo: " + QString::number(calculateForce()) + " N " + QString::number(calculateAngle()) + " °");
    //    label3->setText("Fuerza de reacción en el apoyo móvil: " + QString::number(calculateForce()) + " N " + QString::number(calculateAngle()) + " °");
    //};

    this->show();
}
