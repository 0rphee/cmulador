#include "ventanaArmadura.h"

VentanaArmadura::VentanaArmadura(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Armadura");

    this->setMinimumSize(660, 418);
    this->setMaximumSize(660, 418);

    this->WtablaInputFuerzas = new TablaFuerzasWidget(this);
    this->WtablaInputFuerzas->esArmadura = true;
    this->WtablaInputFuerzas->setGeometry(60, 10, 260, 390);
    this->WtablaInputFuerzas->setItemDelegate(new MyDelegate);
    this->WtablaInputFuerzas->setHorizontalHeaderLabels({"Magnitud (N)","Dirección (grados)","# Nudo"});
    this->WtablaInputFuerzas->resizeColumnsToContents();


    this->WinputAltura = new InputNumerosWidget("Altura de armadura", 1, 99, this);
    this->WinputAltura->setGeometry(320, 0, 210, 90);

    this->WinputLongitud = new InputNumerosWidget("Longitud de armadura", 1, 99, this);
    this->WinputLongitud->setGeometry(320, 80, 210, 90);

    this->WinputNudos = new InputNumerosWidget("# de Nudos de armadura", 3, 99, this);
    this->WinputNudos->setGeometry(320, 160, 210, 90);

    this->Wresultados = new ResultadosWidget(this);
    this->Wresultados->setGeometry(340, 220, 310, 200);

    this->WbotonResultados = new QPushButton("Calcular\nresultados",this);
    this->WbotonResultados->setGeometry(520, 100, 120, 90);


    connect(this->WtablaInputFuerzas, &TablaFuerzasWidget::tableDataChanged, this, &VentanaArmadura::updateLabels);
    connect(this->WinputAltura->counterWidget, &CounterWidget::valueChanged, this, &VentanaArmadura::updateLabels);
    connect(this->WinputLongitud->counterWidget, &CounterWidget::valueChanged, this, &VentanaArmadura::updateLabels);
    connect(this->WbotonResultados, &QPushButton::released, this, &VentanaArmadura::updateLabels);

    this->show();
}

void VentanaArmadura::updateLabels()
{
    bool nudosImpar = (WinputNudos->counterWidget->value % 2) == 1;
    bool nudosFactor4 = (WinputNudos->counterWidget->value % 4) == 0;

    bool nudosInvalidos = !nudosImpar && !nudosFactor4;

    if (WtablaInputFuerzas->rowCount() <= 0 || nudosInvalidos ) {
        QString labelText = "";
        if (WtablaInputFuerzas->rowCount() <= 0){
            labelText = "No hay fuerzas para\ncalcular resultados";
        }else {
            labelText = "Se necesita un número de\n nudos impar o factor de 4";
        }

       // Create the warning dialog
        QDialog * warningDialog = new QDialog();
        warningDialog->setWindowTitle("Alerta");
        warningDialog->setFixedSize(200, 200);

        // Create the label
        QLabel * label = new QLabel(labelText, warningDialog);
        label->setAlignment(Qt::AlignCenter);
        label->setGeometry(0, 50, 200, 50);

        // Create the close button
        QPushButton * closeButton = new QPushButton("Close", warningDialog);
        closeButton->setGeometry(60, 120, 80, 30);

         // Connect the clicked signal of the close button to the close() slot of the dialog
        connect(closeButton, &QPushButton::released, warningDialog, &QDialog::close);
        warningDialog->show();

    }else{
        Armadura armadura = obtener_armadura(WinputLongitud->counterWidget->value, WinputAltura->counterWidget->value, WinputNudos->counterWidget->value, WtablaInputFuerzas);

        double torcaResultante = torca_resultante_armadura(armadura);
        Fuerza fuerzaApoyoFijo = reaccion_nudo0(armadura);
        Fuerza fuerzaApoyoMovil = reaccion_ultimonudo(armadura);

        calculo_fuerzas_armadura(armadura); // writes to stdout

        double apoyofijoDirGrados = fuerzaApoyoFijo.direccion * 180 / PI;
        double apoyomovilDirGrados = fuerzaApoyoMovil.direccion * 180 / PI;

        this->Wresultados->lineEdit1->setText(QString::number(torcaResultante) + " Nm");
        this->Wresultados->lineEdit2->setText(QString::number(fuerzaApoyoFijo.magnitud) + " N " + QString::number(apoyofijoDirGrados) + " °");
        this->Wresultados->lineEdit3->setText(QString::number(fuerzaApoyoMovil.magnitud) + " N " + QString::number(apoyomovilDirGrados) + " °");
    }
}
