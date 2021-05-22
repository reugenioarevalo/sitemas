#include <iostream>
#include <cstring>
#include <iomanip>
#include "Persona.h"
#include "Fecha.h"
#include "../Utilidades/rlutil.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/validaciones.h"

using namespace rlutil;
using namespace std;


Persona::Persona(){

    strcpy(this->apenom, "NN");
    //this->domicilio.Direccion();
    this->activo = false;

}
void Persona::cargarPersona(){

    setApenom();
    domicilio.cargarDireccion();
    this->activo = true;
}

void Persona::mostrarPersona(){

	cout << left;
    cout << setw(40) << "NOMBRE Y APELLIDO:" << setw(30) << this->apenom << endl;
    domicilio.mostrarDireccion();

}
void Persona::setApenom(){

    cout << "NOMBRE Y APELLIDO:\t";
    cin.getline(this->apenom,50,'\n');
    while(!validarNombresApellidos(this->apenom)){
            msj("INCORRECTO",WHITE,RED,130,TEXT_LEFT);
            cout << "NOMBRE Y APELLIDO:\t";
            cin.getline(this->apenom,50,'\n');
    }
}

//void Persona::setNDoc(){
//
//    cout << "DNI:\t";
//    cin.getline(this->nDoc,9,'\n');
//    while(!validarDocumento(nDoc)){
//            msj("INCORRECTO",WHITE,RED,130,TEXT_LEFT);
//            cout << "DNI:\t";
//            cin.getline(this->nDoc,9,'\n');
//    }
//
//}

void Persona::setDomicilio(){this->domicilio.cargarDireccion();}
