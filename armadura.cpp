#include "armadura.h"
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
    this->WinputAltura->setGeometry(390, 58, 210, 90);

    this->WinputAltura = new InputNumerosWidget("Longitud de armadura", 1, 99, this);
    this->WinputAltura->setGeometry(390, 205, 210, 90);

    this->Wresultados = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(Wresultados);

    // Create and add the QLabel widgets
    QLabel* label1 = new QLabel("Torca resultante en la armadura: ", Wresultados);
    QLabel* label2 = new QLabel("Fuerza de reacción en el apoyo fijo: ", Wresultados);
    QLabel* label3 = new QLabel("Fuerza de reacción en el apoyo móvil: ", Wresultados);

    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addWidget(label3);
    this->Wresultados->setGeometry(390, 352, 210, 200);

    this->show();
}
