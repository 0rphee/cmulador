#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <cmath>
#include "tablafuerzaswidget.h"

#define PI 3.141592653589793238462643383279502884L

typedef struct{
    float magnitud;
    float direccion;
    float ubiX;
    float ubiY;
    float fuerzaX;
    float fuerzaY;
}Fuerza;

typedef struct{
    float longitud_palanca;
    float fulcro;
    int num_fuerzas_palanca;
    Fuerza *fuerzas;
}Palanca ;

typedef struct{
    float ubiX;
    float ubiY;
}Nudo;

typedef struct{
    float longitud;
    float altura;
    int num_nudos;
    int num_fuerzas_armadura;
    Fuerza *fuerzas;
    Nudo *nudos;
}Armadura;


Nudo* obtener_nudos(int num_nudos, float longitud, float altura);
Fuerza* obtener_fuerzas_palanca(int num_fuerzas);
Fuerza* obtener_fuerzas_armadura(int numFuerzasArmadura, Nudo* nudos);
Fuerza* obtener_fuerzas_armadura(TablaFuerzasWidget* WtablaInputFuerzas, Nudo* nudos);
Palanca obtener_palanca();
Armadura obtener_armadura(float longitud, float altura, int num_nudos, TablaFuerzasWidget* tabla);
Armadura obtener_armadura(float longitud, float altura, int num_nudos);
Fuerza calculo_fuerzas_palanca(Palanca palanca);
float torca_resultante_armadura(Armadura armadura);
Fuerza reaccion_ultimonudo(Armadura armadura);
Fuerza reaccion_nudo0(Armadura armadura);
void calculo_fuerzas_armadura(Armadura armadura);

#endif // FUNCIONES_H
