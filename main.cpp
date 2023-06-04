/*
Análisis de estructuras

Es un programa que calcula el balance de fuerzas físicas en distintas estructuras, palancas y armaduras. Sirve para la física y la ingeniería estructural, es una herramienta que puede simplificar el proceso de análisis de estructuras.
El programa es muy fácil de usar. Los usuarios pueden ingresar los parámetros de la estructura que desean analizar y, a continuación, obtendrán resultados precisos y detallados sobre las fuerzas involucradas. Además, el programa incluye características adicionales, como la capacidad de visualizar gráficamente las fuerzas y momentos en la estructura, lo que facilita aún más el análisis.
Esto será una herramienta valiosa para ingenieros, arquitectos, estudiantes y cualquier persona interesada en la física y la mecánica. La capacidad de automatizar estos cálculos ahorra tiempo y reduce los errores de cálculo, lo que hace que el análisis de estructuras sea más eficiente y preciso.
Un equipo de dos integrantes es beneficioso para el desarrollo de este proyecto complejo ya que puede acelerar el proceso de desarrollo, aportar diferentes habilidades y conocimientos, mejorar la calidad del proyecto y reducir la carga de trabajo y estrés asociado con el proyecto.
*/

#include "mainwindow.h"
#include <QApplication>

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    cout << "Hello World!" << endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
