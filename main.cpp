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

using namespace std;

typedef struct{
    float magnitud;
    float direccion;
    float ubiX;
    float ubiY;
    string sentido;
}Fuerza;

typedef struct{
    float longitud_palanca;
    float fulcroX;
    float fulcroY;
    Fuerza fuerza;
}Palanca ;

typedef struct{
    float ubiX;
    float ubiY;
}Nudo;

typedef struct{
    float longitud;
    float altura;
    Fuerza *fuerza;
    Nudo *nudos;
}Armadura;


void obtener_nudos(int num_nudos, Armadura *armadura){
    bool validacion = false;
    armadura->nudos = new Nudo[num_nudos];
    do{
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
        validacion = true;
        }
        else{
            if( (num_nudos%4) == 0){
                
                validacion = true;
            }
            else{
                cout << "El número de nudos debe ser impar o múltiplo de 4" << endl;
                validacion = false;
            }
        }
    }while (validacion == false);
}

int main(){
    cout << "Hello World!" << endl;
}