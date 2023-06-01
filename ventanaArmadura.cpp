#include "ventanaArmadura.h"
#include "tablafuerzaswidget.h"
#include "palancaYarmadura.h"

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

    this->setMinimumSize(660, 418);
    this->setMaximumSize(660, 418);

    this->WtablaInputFuerzas = new TablaFuerzasWidget(this);
    this->WtablaInputFuerzas->setGeometry(60, 10, 260, 390);

    this->WinputAltura = new InputNumerosWidget("Altura de armadura", 1, 99, this);
    this->WinputAltura->setGeometry(390, 0, 210, 90);

    this->WinputLongitud = new InputNumerosWidget("Longitud de armadura", 1, 99, this);
    this->WinputLongitud->setGeometry(390, 80, 210, 90);

    this->WinputNudos = new InputNumerosWidget("# de Nudos de armadura", 3, 99, this);
    this->WinputNudos->setGeometry(390, 160, 210, 90);

    this->Wresultados = new ResultadosWidget(this);
    this->Wresultados->setGeometry(340, 220, 310, 200);

    connect(this->WtablaInputFuerzas, &TablaFuerzasWidget::tableDataChanged, this, &VentanaArmadura::updateLabels);
    connect(this->WinputAltura->counterWidget, &CounterWidget::valueChanged, this, &VentanaArmadura::updateLabels);
    connect(this->WinputLongitud->counterWidget, &CounterWidget::valueChanged, this, &VentanaArmadura::updateLabels);

     this->show();
}

void VentanaArmadura::updateLabels()
{
    bool nudosImpar = (WinputNudos->counterWidget->value % 2) == 1;
    bool nudosFactor4 = (WinputNudos->counterWidget->value % 4) == 0;

    bool nudosInvalidos = !nudosImpar && !nudosFactor4;

    if (WtablaInputFuerzas->rowCount() < 0 || nudosInvalidos ) {
        cout << "WARNING\n" << endl;
        QString nudos4 = "Válidos: " + QString::number(nudosFactor4);
        if (!nudosFactor4){
            nudos4 = "Inválidos: " + QString::number(nudosFactor4);
        }
        QString nudosImparS = "Válidos: " + QString::number(nudosImpar);
        if (!nudosImpar){
            nudosImparS = "Inválidos: " + QString::number(nudosImpar);
        }
        QLabel * warning = new QLabel("WARNING, factor 4: " + nudos4 + "\n, impar: " + nudosImparS);
        warning->show();
        warning->setWindowTitle("WARNING");

        warning->setMinimumSize(200, 200);
        warning->setMaximumSize(200, 200);

    }else{
        Armadura armadura = obtener_armadura(WinputLongitud->counterWidget->value, WinputAltura->counterWidget->value, WinputNudos->counterWidget->value, WtablaInputFuerzas);

        double torcaResultante = torca_resultante_armadura(armadura);
        Fuerza fuerzaApoyoFijo = reaccion_nudo0(armadura);
        Fuerza fuerzaApoyoMovil = reaccion_ultimonudo(armadura);

        // Update the text of the labels
        calculo_fuerzas_armadura(armadura);

        this->Wresultados->lineEdit1->setText(QString::number(torcaResultante) + " Nm");
        this->Wresultados->lineEdit2->setText(QString::number(fuerzaApoyoFijo.magnitud) + " N " + QString::number(fuerzaApoyoFijo.direccion) + " °");
        this->Wresultados->lineEdit3->setText(QString::number(fuerzaApoyoMovil.magnitud) + " N " + QString::number(fuerzaApoyoMovil.direccion) + " °");
    }
}
