#include "ventanapalanca.h"

using namespace std;

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

    this->Wresultados = new PResultadosWidget(this);
    this->Wresultados->setGeometry(340, 200, 310, 200);

    connect(this->WtablaInputFuerzas, &TablaFuerzasWidget::tableDataChanged, this, &VentanaPalanca::updateLabels);
    connect(this->WinputLongitud->counterWidget, &CounterWidget::valueChanged, this, &VentanaPalanca::updateLabels);
    connect(this->WinputUbicacionFulcro->counterWidget, &CounterWidget::valueChanged, this, &VentanaPalanca::updateLabels);
    connect(this->WbotonResultados, &QPushButton::released, this, &VentanaPalanca::updateLabels);

    this->show();
}

void VentanaPalanca::updateLabels()
{
    cout << WinputLongitud->counterWidget->dvalue << endl;

    if (WtablaInputFuerzas->rowCount() <= 0 || WinputLongitud->counterWidget->dvalue == 0) {
        QString labelText = "";
        if (WtablaInputFuerzas->rowCount() <= 0){
            labelText = "No hay fuerzas para\ncalcular resultados";
        } else{
            labelText = "La longitud de la \npalanca no puede ser 0";
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
        Palanca palanca = obtener_palanca(WtablaInputFuerzas, WinputLongitud->counterWidget->dvalue, WinputUbicacionFulcro->counterWidget->dvalue);

        cout << "Fuerzas palanca: " << palanca.num_fuerzas_palanca << endl;
        cout << "Posicion fulcro: " << palanca.fulcro << endl;
        cout << "Longitud palanca: " << palanca.longitud_palanca << endl;

        Fuerza torcaResultante = calculo_fuerzas_palanca(palanca);

        this->Wresultados->lineEdit1->setText(QString::number(torcaResultante.fuerzaX) + " Nm");
        this->Wresultados->lineEdit2->setText(QString::number(torcaResultante.fuerzaY) + " Nm");
//        double apoyofijoDirGrados = fuerzaApoyoFijo.direccion * 180 / PI;
//        double apoyomovilDirGrados = fuerzaApoyoMovil.direccion * 180 / PI;

//        this->Wresultados->lineEdit1->setText(QString::number(torcaResultante) + " Nm");
//        this->Wresultados->lineEdit2->setText(QString::number(fuerzaApoyoFijo.magnitud) + " N " + QString::number(apoyofijoDirGrados) + " °");
//        this->Wresultados->lineEdit3->setText(QString::number(fuerzaApoyoMovil.magnitud) + " N " + QString::number(apoyomovilDirGrados) + " °");
    }
}
