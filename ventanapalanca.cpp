#include "ventanapalanca.h"

VentanaPalanca::VentanaPalanca(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Palanca");

    this->setMinimumSize(660, 418);
    this->setMaximumSize(660, 418);

    this->WtablaInputFuerzas = new TablaFuerzasWidget(this);
    this->WtablaInputFuerzas->esArmadura = false;
    this->WtablaInputFuerzas->setGeometry(20, 10, 300, 390);
    this->WtablaInputFuerzas->setItemDelegate(new MyDelegateP);
    this->WtablaInputFuerzas->setHorizontalHeaderLabels({"Magnitud (N)","Dirección (grados)","Ubicación 0-longitud (m)"});
    this->WtablaInputFuerzas->resizeColumnsToContents();

    this->WinputLongitud = new InputNumerosWidget("Longitud de palanca", 0.0, 99.0, this);
    this->WinputLongitud->setGeometry(320, 20, 210, 90);

    this->WinputUbicacionFulcro = new InputNumerosWidget("Ubicación de Fulcro\n(0-longitud)", 0.0, 99.0, this);
    this->WinputUbicacionFulcro->setGeometry(320, 100, 210, 110);

    this->WbotonResultados = new QPushButton("Calcular\nresultados",this);
    this->WbotonResultados->setGeometry(520, 80, 120, 90);

    this->Wresultados = new ResultadosWidget(this);
    this->Wresultados->setGeometry(340, 200, 310, 200);

    connect(this->WtablaInputFuerzas, &TablaFuerzasWidget::tableDataChanged, this, &VentanaPalanca::updateLabels);
    connect(this->WinputLongitud->counterWidget, &CounterWidget::valueChanged, this, &VentanaPalanca::updateLabels);
    connect(this->WinputUbicacionFulcro->counterWidget, &CounterWidget::valueChanged, this, &VentanaPalanca::updateLabels);
    connect(this->WbotonResultados, &QPushButton::released, this, &VentanaPalanca::updateLabels);

    this->show();
}

void VentanaPalanca::updateLabels()
{
    if (WtablaInputFuerzas->rowCount() <= 0) {
        QString labelText = "";
        if (WtablaInputFuerzas->rowCount() <= 0){
            labelText = "No hay fuerzas para\ncalcular resultados";
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
//        Armadura armadura = obtener_armadura(WinputLongitud->counterWidget->value, WinputAltura->counterWidget->value, WinputNudos->counterWidget->value, WtablaInputFuerzas);

//        double torcaResultante = torca_resultante_armadura(armadura);
//        Fuerza fuerzaApoyoFijo = reaccion_nudo0(armadura);
//        Fuerza fuerzaApoyoMovil = reaccion_ultimonudo(armadura);

//        calculo_fuerzas_armadura(armadura); // writes to stdout

//        double apoyofijoDirGrados = fuerzaApoyoFijo.direccion * 180 / PI;
//        double apoyomovilDirGrados = fuerzaApoyoMovil.direccion * 180 / PI;

//        this->Wresultados->lineEdit1->setText(QString::number(torcaResultante) + " Nm");
//        this->Wresultados->lineEdit2->setText(QString::number(fuerzaApoyoFijo.magnitud) + " N " + QString::number(apoyofijoDirGrados) + " °");
//        this->Wresultados->lineEdit3->setText(QString::number(fuerzaApoyoMovil.magnitud) + " N " + QString::number(apoyomovilDirGrados) + " °");
    }
}
