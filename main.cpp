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
    string sentido;
};

struct Palanca {
    float longitud_palanca;
    float fulcro[2];
    Fuerza fuerza[];
};

struct Nudo {
    float ubicacion[2];
    Fuerza fuerza[];
};

struct Armadura{
    float longitud;
    float altura;
    float ancho;
    Fuerza fuerza[];
};


class Armazon : public Estructura {
public:
    float longitud_lado1;
    float longitud_lado2;
    float altura_lado1;
    float altura_lado2;
    void calcular_balance_armazon();
};

class Estructura {
public:
    std::string nombre;
    float longitud;
    float ancho;
    float altura;

};