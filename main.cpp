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
    Fuerza *fuerzas;
    Nudo *nudos;
}Armadura;

void obtener_nudos(int num_nudos, Armadura *armadura);
void obtener_fuerza_palanca(int num_fuerzas);
void obtener_fuerza_armadura(int num_fuerzas, Armadura * armadura);
void obtener_datos_palanca(Palanca *palanca);
void obtener_datos_armadura(Armadura *armadura);
Fuerza calculo_fuerzas_palanca(Palanca palanca);
Fuerza calculo_fuerzas_armadura(Armadura armadura);

// Corregir
void obtener_nudos(Armadura *armadura){
    bool validacion = false;
    armadura->nudos = new Nudo[armadura->num_nudos];
    if ( (armadura->num_nudos%2) != 0 ){
        for (int i = 0; i < armadura->num_nudos; i++){
            armadura->nudos[i].ubiX = (armadura->longitud/armadura->num_nudos)*i;
            if ( (i%2) != 0 ){
                armadura->nudos[i].ubiY = armadura->altura;
            }
            else{
                armadura->nudos[i].ubiY = 0;
            }
        }
    }
    else{
        int acumulador = 0;
        for(int i = 0; i < armadura->num_nudos; i++){
            if ( i == 0 ){
                armadura->nudos[i].ubiX = 0;
                armadura->nudos[i].ubiY = 0;
            }
            if ( i == armadura->num_nudos-1 ){
                armadura->nudos[i].ubiX = armadura->longitud;
                armadura->nudos[i].ubiY = 0;
            }
            if ( (i%2) != 0 ){
                armadura->nudos[i].ubiX = (armadura->longitud/((armadura->num_nudos/2)+1))*(i/2);
                armadura->nudos[i].ubiY = 0;
            }
            else{
                armadura->nudos[i].ubiX = (armadura->longitud/((armadura->num_nudos/2)+1))*(i-acumulador);
                acumulador += 1;
                armadura->nudos[i].ubiY = armadura->altura;
            }
        }
    }
}

void obtener_fuerza_palanca(int num_fuerzas){
    Fuerza * fuerzas = new Fuerza[num_fuerzas];
    for(int i = 0; i < num_fuerzas; i++){
        cout << "Ingrese la magnitud de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].magnitud;
        cout << "Ingrese la dirección de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].direccion;
        cout << "Ingrese la ubicación en X de la fuerzas " << i+1 << ": ";
        cin >> fuerzas[i].ubiX;
        fuerzas[i].fuerzaX = fuerzas[i].magnitud*cos(fuerzas[i].direccion);
        fuerzas[i].fuerzaY = fuerzas[i].magnitud*sin(fuerzas[i].direccion);
    }
}

void obtener_fuerza_armadura(int num_fuerzas, Armadura * armadura){
    armadura->fuerzas = new Fuerza[num_fuerzas];
    for(int i = 0; i < num_fuerzas; i++){
        int numero_nudo = 0;
        cout << "Ingrese la magnitud de la fuerzas " << i+1 << ": ";
        cin >> armadura->fuerzas[i].magnitud;
        cout << "Ingrese la dirección de la fuerzas " << i+1 << ": ";
        cin >> armadura->fuerzas[i].direccion;
        armadura->fuerzas[i].fuerzaX = armadura->fuerzas[i].magnitud*cos(armadura->fuerzas[i].direccion);
        armadura->fuerzas[i].fuerzaY = armadura->fuerzas[i].magnitud*sin(armadura->fuerzas[i].direccion);
        cout << "Ingrese la ubicación del nudo al que se le aplica la fuerzas " << i+1 << ": ";
        cin >> numero_nudo;
        armadura->fuerzas[i].ubiX = armadura->nudos[numero_nudo-1].ubiX;
        armadura->fuerzas[i].ubiY = armadura->nudos[numero_nudo-1].ubiY;
    }
}

void obtener_datos_palanca(Palanca *palanca){
    cout << "Ingrese la longitud de la palanca: ";
    cin >> palanca->longitud_palanca;
    cout << "Ingrese la ubicación del fulcro: ";
    cin >> palanca->fulcro;
}

void obtener_datos_armadura(Armadura *armadura){
    cout << "Ingrese la longitud de la armadura: ";
    cin >> armadura->longitud;
    cout << "Ingrese la altura de la armadura: ";
    cin >> armadura->altura;
    bool validación = false;    
    do{
        cout << "Ingrese el número de nudos (N > 3 / N impar / N multiplo de 4): ";
        cin >> armadura->num_nudos;
        if (armadura->num_nudos < 3){
            cout << "El número de nudos debe ser mayor o igual a 3" << endl;
            validación = false;
        }
        if ( (armadura->num_nudos%2) != 0 ){
            validación = true;
        }
        else{
            if( (armadura->num_nudos%4) == 0){
                validación = true;
            }
            else{
                cout << "El número de nudos debe ser impar o múltiplo de 4" << endl;
                validación = false;
            }
        }
    }while(validación == false);
}

Fuerza calculo_fuerzas_palanca(Palanca palanca){

}

Fuerza calculo_fuerzas_armadura(Armadura armadura){

}

int main(){
    cout << "Hello World!" << endl;
}