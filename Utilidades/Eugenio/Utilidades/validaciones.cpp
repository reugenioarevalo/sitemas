#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../Utilidades/rlutil.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/menus.h"
#include "../Include/Persona.h"
#include "validaciones.h"

using namespace std;
using namespace rlutil;

bool validarNombresApellidos(char *nombres){

    int  cadena = 0, contEspacios=0;
    cadena = strlen(nombres);
    bool valorFinal = true;

     if(cadena == 0){
		system("cls");
        msj("CAMPO VACIO",WHITE,RED,130,TEXT_LEFT);
        return false;
        }

    for(int i=0; i <= cadena; i++){
        if(nombres[i]==' '){
            contEspacios++;
        }
        if(isdigit(nombres[i])==true){
            return false;
        }
    }
    if(contEspacios>=3){
        return false;
    }
    return valorFinal;
}

bool validarDocumento(char *nDoc){

    if(strlen(nDoc) == 8){
        return true;
    }else{
        return false;
    }
}

/*
bool validarFecha( int dia, int mes, int anio){

    Fecha fechaDeHoy;

    fechaDeHoy = hoy();
    bool fec = false;

    if (anio >= fechaDeHoy.anio )
        if(mes >= fechaDeHoy.mes)
         if(dia >= fechaDeHoy.dia){
            fec=false;
              return fec;
    }

    if( mes >= 1 && mes <= 12 )
    {

        switch( mes ){

        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if( dia >= 1 && dia <= 31 ){  fec = true;}
            break;

        case 4:case 6:case 9:case 11:
            if( dia >= 1 && dia <= 30 ){ fec = true;}
            break;


        case 2://Si el año es bisiesto +1 día.

            if( ((anio%4 == 0)   &&   (anio%100 != 0)) ||   (anio%400 == 0) ){
                if( dia >= 1 && dia <= 29 ){
                    fec = true;
                }
            }else{
                if( dia >= 1 && dia <= 28 ){
                    fec = true;
                }
            }
            break;

        }

    }
    return fec;
}*/

/*bool validarFecha(Fecha regAux){



}
*/
