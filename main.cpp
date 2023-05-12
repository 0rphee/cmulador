/*
Análisis de estructuras

Es un programa que calcula el balance de fuerzas físicas en distintas estructuras, palancas y armaduras. Sirve para la física y la ingeniería estructural, es una herramienta que puede simplificar el proceso de análisis de estructuras.
El programa es muy fácil de usar. Los usuarios pueden ingresar los parámetros de la estructura que desean analizar y, a continuación, obtendrán resultados precisos y detallados sobre las fuerzas involucradas. Además, el programa incluye características adicionales, como la capacidad de visualizar gráficamente las fuerzas y momentos en la estructura, lo que facilita aún más el análisis.
Esto será una herramienta valiosa para ingenieros, arquitectos, estudiantes y cualquier persona interesada en la física y la mecánica. La capacidad de automatizar estos cálculos ahorra tiempo y reduce los errores de cálculo, lo que hace que el análisis de estructuras sea más eficiente y preciso.
Un equipo de dos integrantes es beneficioso para el desarrollo de este proyecto complejo ya que puede acelerar el proceso de desarrollo, aportar diferentes habilidades y conocimientos, mejorar la calidad del proyecto y reducir la carga de trabajo y estrés asociado con el proyecto.
*/

#include <iostream>
#ifdef WIN32
#include <windows.h>
#endif

using namespace std;

struct Fuerza {
    float magnitud;
    float direccion;
    float ubicacion[2];
};

struct Nudo {
    float ubicacion[2];
    string nombre;
};

struct Palanca {
    float longitud_palanca;
    float fulcro;
    Fuerza fuerzaReaccion;
};

struct Armadura {
    float longitud;
    Nudo nudos;
    Fuerza fuerzas;
};

void addFuerza(Fuerza fuerza){
    cout << "Ingrese la magnitud de la fuerza: "; cin >> fuerza.magnitud >> " N";
    cout << "Ingrese la direccion de la fuerza: "; cin >> fuerza.direccion >> " °";
    cout << "Ingrese la ubicacion de la fuerza: ("; cin >> fuerza.ubicacion[0] >> " m, " >> fuerza.ubicacion[1] >> " m)";
};

void addNfuerzas (int N){
    Fuerza *fuerzas = new Fuerza[N];
    for (int i = 0; i < N; i++){
        addFuerza(fuerzas[i]);
    }
};

void addNudos (int N, struct Armadura armadura){
    Nudo *nudos = new Nudo[N];
    for (int i = 0; i < N; i++){
        nudos[i].nombre = "Nudo " + i;
        nudos[i].ubicacion[0] =
    }
};