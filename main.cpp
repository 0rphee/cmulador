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

void obtener_nudos(int num_nudos, Armadura *armadura);
void obtener_fuerza_palanca(int num_fuerzas);
void obtener_fuerza_armadura(int num_fuerzas, Armadura * armadura);
void obtener_datos_palanca(Palanca *palanca);
void obtener_datos_armadura(Armadura *armadura);

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
    Fuerza *fuerza;
}Palanca ;

typedef struct{
    float ubiX;
    float ubiY;
}Nudo;

typedef struct{
    float longitud;
    float altura;
    int num_nudos;
    Fuerza *fuerza;
    Nudo *nudos;
}Armadura;


void obtener_nudos(int num_nudos, Armadura *armadura){
    bool validacion = false;
    armadura->nudos = new Nudo[num_nudos];
    if ( (num_nudos%2) != 0 ){
        for (int i = 0; i < num_nudos; i++){
            armadura->nudos[i].ubiX = (armadura->longitud/num_nudos)*i;
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
        for(int i = 0; i < num_nudos; i++){
            if ( i == 0 ){
                armadura->nudos[i].ubiX = 0;
                armadura->nudos[i].ubiY = 0;
            }
            if ( i == num_nudos-1 ){
                armadura->nudos[i].ubiX = armadura->longitud;
                armadura->nudos[i].ubiY = 0;
            }
            if ( (i%2) != 0 ){
                armadura->nudos[i].ubiX = (armadura->longitud/((num_nudos/2)+1))*(i/2);
                armadura->nudos[i].ubiY = 0;
            }
            else{
                armadura->nudos[i].ubiX = (armadura->longitud/((num_nudos/2)+1))*(i-acumulador);
                acumulador += 1;
                armadura->nudos[i].ubiY = armadura->altura;
            }
        }
    }
}

void obtener_fuerza_palanca(int num_fuerzas){
    Fuerza * fuerza = new Fuerza[num_fuerzas];
    for(int i = 0; i < num_fuerzas; i++){
        cout << "Ingrese la magnitud de la fuerza " << i+1 << ": ";
        cin >> fuerza[i].magnitud;
        cout << "Ingrese la dirección de la fuerza " << i+1 << ": ";
        cin >> fuerza[i].direccion;
        cout << "Ingrese la ubicación en X de la fuerza " << i+1 << ": ";
        cin >> fuerza[i].ubiX;
        fuerza[i].fuerzaX = fuerza[i].magnitud*cos(fuerza[i].direccion);
        fuerza[i].fuerzaY = fuerza[i].magnitud*sin(fuerza[i].direccion);
    }
}

void obtener_fuerza_armadura(int num_fuerzas, Armadura * armadura){
    armadura->fuerza = new Fuerza[num_fuerzas];
    for(int i = 0; i < num_fuerzas; i++){
        int numero_nudo = 0;
        cout << "Ingrese la magnitud de la fuerza " << i+1 << ": ";
        cin >> armadura->fuerza[i].magnitud;
        cout << "Ingrese la dirección de la fuerza " << i+1 << ": ";
        cin >> armadura->fuerza[i].direccion;
        armadura->fuerza[i].fuerzaX = armadura->fuerza[i].magnitud*cos(armadura->fuerza[i].direccion);
        armadura->fuerza[i].fuerzaY = armadura->fuerza[i].magnitud*sin(armadura->fuerza[i].direccion);
        cout << "Ingrese la ubicación del nudo al que se le aplica la fuerza " << i+1 << ": ";
        cin >> numero_nudo;
        armadura->fuerza[i].ubiX = armadura->nudos[numero_nudo-1].ubiX;
        armadura->fuerza[i].ubiY = armadura->nudos[numero_nudo-1].ubiY;
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

int main(){
    cout << "Hello World!" << endl;
}