#include "funciones.h"

using namespace std;

Nudo* obtener_nudos(int num_nudos, float longitud, float altura){
    Nudo* nudos = new Nudo[num_nudos];
    // caso impar
    if ( (num_nudos%2) != 0 ){
        for (int i = 0; i < num_nudos; i++){
            nudos[i].ubiX = (longitud/num_nudos)*i;
            if ( (i%2) != 0 ){
                nudos[i].ubiY = 0;
           }
            else{
                nudos[i].ubiY = altura;
            }
        }
    }
    // caso múltiplo de 4
    else if  (num_nudos % 4 == 0){
        int acumulador = 0;
        for(int i = 0; i < num_nudos-1; i++){
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
    } else {
        cout << "NÚMERO DE NUDOS INVÁLIDO: " << num_nudos << endl;
    }
    return nudos;
}

Fuerza* obtener_fuerzas_palanca(TablaFuerzasWidget* WtablaInputFuerzas){
    Fuerza * fuerzas = new Fuerza[WtablaInputFuerzas->rowCount()];
    for(int i = 0; i < WtablaInputFuerzas->rowCount(); i++){
        fuerzas[i].magnitud = WtablaInputFuerzas->item(i, 0)->text().toDouble();
        cout << "magnitud de fuerza [" << i << "]:" << fuerzas[i].magnitud << "\n";

        fuerzas[i].direccion = WtablaInputFuerzas->item(i, 1)->text().toDouble() * PI/180.0;
        cout << "direccion de fuerza [" << i << "]:" << fuerzas[i].direccion << "\n";

        fuerzas[i].ubiX = WtablaInputFuerzas->item(i, 2)->text().toDouble();

        fuerzas[i].fuerzaX = fuerzas[i].magnitud * cos(fuerzas[i].direccion);
        cout << "fuerza x de fuerza [" << i << "]:" << fuerzas[i].fuerzaX << "\n";

        fuerzas[i].fuerzaY = fuerzas[i].magnitud * sin(fuerzas[i].direccion);
        cout << "fuerza y de fuerza [" << i << "]:" << fuerzas[i].fuerzaY << "\n";
    }
    return fuerzas;
}



Fuerza* obtener_fuerzas_armadura(TablaFuerzasWidget* WtablaInputFuerzas, Nudo* nudos){
    Fuerza * fuerzas = new Fuerza[WtablaInputFuerzas->rowCount()];
    for (int i = 0; i < WtablaInputFuerzas->rowCount(); i++) {

        cout << WtablaInputFuerzas->item(i,0)->text().toStdString() + " " + WtablaInputFuerzas->item(i,1)->text().toStdString() + " " + WtablaInputFuerzas->item(i,2)->text().toStdString() << endl;

        fuerzas[i].magnitud = WtablaInputFuerzas->item(i,0)->text().toInt();

        fuerzas[i].direccion = WtablaInputFuerzas->item(i,1)->text().toInt() * PI/180.0;
        cout << "direccion de fuerza [" << i << "]:" << fuerzas[i].direccion << "\n";

        fuerzas[i].fuerzaX = fuerzas[i].magnitud * cos(fuerzas[i].direccion);
        cout << "fuerza x de fuerza [" << i << "]:" << fuerzas[i].fuerzaX << "\n";

        fuerzas[i].fuerzaY = fuerzas[i].magnitud * sin(fuerzas[i].direccion);
        cout << "fuerza y de fuerza [" << i << "]:" << fuerzas[i].fuerzaY << "\n";

        int numNudo = WtablaInputFuerzas->item(i,2)->text().toInt();
        fuerzas[i].ubiX = nudos[numNudo-1].ubiX;
        fuerzas[i].ubiY = nudos[numNudo-1].ubiY;
    }
    return fuerzas;
}

Palanca obtener_palanca(TablaFuerzasWidget * WtablaInputFuerzas, double longitud, double ubiFulcro){
    Palanca palanca;
    palanca.longitud_palanca = longitud;
    palanca.fulcro = ubiFulcro;
    palanca.num_fuerzas_palanca = WtablaInputFuerzas->rowCount();
    palanca.fuerzas = obtener_fuerzas_palanca(WtablaInputFuerzas);
    return palanca;
}
Armadura obtener_armadura(float longitud, float altura, int num_nudos, TablaFuerzasWidget* tabla){
    Armadura armadura;
    armadura.longitud = longitud;
    armadura.altura = altura;
    armadura.num_nudos = num_nudos;
    armadura.nudos = obtener_nudos(armadura.num_nudos, armadura.longitud, armadura.altura);
    armadura.num_fuerzas_armadura = tabla->rowCount();
    armadura.fuerzas = obtener_fuerzas_armadura(tabla, armadura.nudos);
    return armadura;
}

// unico resultado final de palanca
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
    reaccion_ultimonudo.direccion = 90 * PI/180.0;
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
    cout << "-----------------------------------------------------\n";
    cout << "Torca resultante en la armadura: " << torca_resultante_armadura(armadura) << " Nm" << endl;
    cout << "Fuerza de reacción en el apoyo fijo: " << reaccion_nudo0(armadura).magnitud << " N " << reaccion_nudo0(armadura).direccion << "°" << endl;
    cout << "Fuerza de reacción en el apoyo móvil: " << reaccion_ultimonudo(armadura).magnitud << " N " << reaccion_ultimonudo(armadura).direccion << "°" << endl;
    cout << "-----------------------------------------------------\n";
}

