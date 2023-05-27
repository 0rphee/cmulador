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

    this->WinputAltura = new InputNumerosWidget("Altura de armadura", 1, 99, this);
    this->WinputAltura->setGeometry(80, 10, 210, 90);

    this->WinputAltura = new InputNumerosWidget("Longitud de armadura", 1, 99, this);
    this->WinputAltura->setGeometry(370, 10, 210, 90);

    this->WtablaInputFuerzas = new TablaFuerzasWidget(this);
    this->WtablaInputFuerzas->setGeometry(80, 110, 500, 380);

    this->show();
}
