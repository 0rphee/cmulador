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
#include <cmath>

#ifdef WIN32
#include <windows.h>
#endif

using namespace std;

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
Palanca obtener_palanca();
Armadura obtener_armadura();
Fuerza calculo_fuerzas_palanca(Palanca palanca);
float torca_resultante_armadura(Armadura armadura);
Fuerza reaccion_ultimonudo(Armadura armadura);
Fuerza reaccion_nudo0(Armadura armadura);
void calculo_fuerzas_armadura(Armadura armadura);

Nudo* obtener_nudos(int num_nudos, float longitud, float altura){
    Nudo* nudos = new Nudo[num_nudos];
    if ( (num_nudos%2) != 0 ){
        for (int i = 0; i < num_nudos; i++){
            nudos[i].ubiX = (longitud/num_nudos)*i;
            if ( (i%2) != 0 ){
                nudos[i].ubiY = altura;
           }
            else{
                nudos[i].ubiY = 0;
            }
        }
    }
    else{
        int acumulador = 0;
        for(int i = 0; i < num_nudos; i++){
            if ( i == 0 ){
                nudos[i].ubiX = 0;
                nudos[i].ubiY = 0;
            }
            if ( i == num_nudos-1 ){
                nudos[i].ubiX = longitud;
                nudos[i].ubiY = 0;
            }
            if ( (i%2) != 0 ){
                nudos[i].ubiX = (longitud/((num_nudos/2)+1))*(i-acumulador);
                acumulador += 1;
                nudos[i].ubiY = altura;
            }
            else{
                nudos[i].ubiX = (longitud/((num_nudos/2)+1))*(i/2);
                nudos[i].ubiY = 0;
            }
        }
    }
    return nudos;
}

Fuerza* obtener_fuerzas_palanca(int num_fuerzas){
    Fuerza * fuerzas = new Fuerza[num_fuerzas];
    for(int i = 0; i < num_fuerzas; i++){
        cout << "Ingrese la magnitud de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].magnitud;
        cout << "Ingrese la dirección de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].direccion;
        cout << "Ingrese la ubicación en X de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].ubiX;
        fuerzas[i].fuerzaX = fuerzas[i].magnitud * cos(fuerzas[i].direccion);
        fuerzas[i].fuerzaY = fuerzas[i].magnitud * sin(fuerzas[i].direccion);
    }
    return fuerzas;
}

Fuerza* obtener_fuerzas_armadura(int numFuerzasArmadura, Nudo* nudos){
    Fuerza * fuerzas = new Fuerza[numFuerzasArmadura];
    for(int i = 0; i < numFuerzasArmadura; i++){
        int numero_nudo = 0;
        cout << "Ingrese la magnitud de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].magnitud;
        cout << "Ingrese la dirección de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].direccion;
        fuerzas[i].fuerzaX = fuerzas[i].magnitud * cos(fuerzas[i].direccion);
        fuerzas[i].fuerzaY = fuerzas[i].magnitud * sin(fuerzas[i].direccion);
        cout << "Ingrese la ubicación del nudo al que se le aplica la fuerzas " << i+1 << ": ";
        cin >> numero_nudo;
        fuerzas[i].ubiX = nudos[numero_nudo-1].ubiX;
        fuerzas[i].ubiY = nudos[numero_nudo-1].ubiY;
    }
    return fuerzas;
}

Palanca obtener_palanca(){
    Palanca palanca;
    cout << "Ingrese la longitud de la palanca: ";
    cin >> palanca.longitud_palanca;
    cout << "Ingrese la ubicación del fulcro: ";
    cin >> palanca.fulcro;
    cout << "Ingrese el numero de fuerzas: ";
    cin >> palanca.num_fuerzas_palanca;
    palanca.fuerzas = obtener_fuerzas_palanca(palanca.num_fuerzas_palanca);
    return palanca;
}

Armadura obtener_armadura(){
    Armadura armadura;
    do{
        cout << "Ingrese la longitud de la armadura (L > 0): ";
        cin >> armadura.longitud;
    }while (armadura.longitud <= 0);
    do{
        cout << "Ingrese la altura de la armadura (h > 0): ";
        cin >> armadura.altura;
    }while (armadura.altura <= 0);
    bool validación = false;    
    do{
        cout << "Ingrese el número de nudos (N > 3 / N impar / N multiplo de 4): ";
        cin >> armadura.num_nudos;
        if (armadura.num_nudos < 3){
            cout << "El número de nudos debe ser mayor o igual a 3" << endl;
            validación = false;
        }
        if ( (armadura.num_nudos%2) != 0 ){
            validación = true;
        }
        else{
            if( (armadura.num_nudos%4) == 0){
                validación = true;
            }
            else{
                cout << "El número de nudos debe ser impar o múltiplo de 4" << endl;
                validación = false;
            }
        }
    } while(validación == false);

    armadura.nudos = obtener_nudos(armadura.num_nudos, armadura.longitud, armadura.altura);

    do {
        cout << "Ingrese el número de fuerzas ( N > 1 ): ";
        cin >> armadura.num_fuerzas_armadura;
    } while (armadura.num_fuerzas_armadura < 1);

    armadura.fuerzas = obtener_fuerzas_armadura(armadura.num_fuerzas_armadura, armadura.nudos);

    return armadura;
}

Fuerza calculo_fuerzas_palanca(Palanca palanca){
    Fuerza torca_resultante;
    for(int i = 0; i < palanca.num_fuerzas_palanca; i++){
        if(palanca.fuerzas[i].ubiX < palanca.fulcro){
            torca_resultante.fuerzaX += palanca.fuerzas[i].fuerzaX * (palanca.fulcro - palanca.fuerzas[i].ubiX);
        }
        else{
            torca_resultante.fuerzaX -= palanca.fuerzas[i].fuerzaX * (palanca.fuerzas[i].ubiX - palanca.fulcro);
        }
    }
    return torca_resultante;
}

float torca_resultante_armadura(Armadura armadura){
    float torca_resultante = 0.0;
    for(int i = 0; i < armadura.num_fuerzas_armadura; i++){
        torca_resultante += armadura.fuerzas[i].fuerzaY * armadura.fuerzas[i].ubiX;
    }
    return torca_resultante;
}

Fuerza reaccion_ultimonudo(Armadura armadura){
    Fuerza reaccion_ultimonudo;
    reaccion_ultimonudo.magnitud = -(torca_resultante_armadura(armadura)/armadura.longitud);
    reaccion_ultimonudo.direccion = 90;
    return reaccion_ultimonudo;
}

Fuerza reaccion_nudo0(Armadura armadura){
    Fuerza reaccion_nudo0;
    reaccion_nudo0.fuerzaX = 0;
    reaccion_nudo0.fuerzaY = 0;
    for(int i = 0; i < armadura.num_fuerzas_armadura; i++){
        reaccion_nudo0.fuerzaX -= armadura.fuerzas[i].fuerzaX;
        reaccion_nudo0.fuerzaY -= armadura.fuerzas[i].fuerzaY;
    }
    reaccion_nudo0.fuerzaY -= reaccion_ultimonudo(armadura).magnitud;
    reaccion_nudo0.magnitud = sqrt(pow(reaccion_nudo0.fuerzaX,2)+pow(reaccion_nudo0.fuerzaY,2));
    reaccion_nudo0.direccion = atan(reaccion_nudo0.fuerzaY/reaccion_nudo0.fuerzaX);
    return reaccion_nudo0;
}

void calculo_fuerzas_armadura(Armadura armadura){
    cout << "Torca resultante en la armadura: " << torca_resultante_armadura(armadura) << " Nm" << endl;
    cout << "Fuerza de reacción en el apoyo fijo: " << reaccion_nudo0(armadura).magnitud << " N " << reaccion_nudo0(armadura).direccion << "°" << endl;
    cout << "Fuerza de reacción en el apoyo móvil: " << reaccion_ultimonudo(armadura).magnitud << " N " << reaccion_ultimonudo(armadura).direccion << "°" << endl;
}

int main(int argc, char *argv[]){
    cout << "Hello World!" << endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}