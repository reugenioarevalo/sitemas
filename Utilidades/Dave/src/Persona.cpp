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
    setCuit();
    domicilio.cargarDireccion();
    this->activo = true;
}

void Persona::mostrarPersona(){

	cout << left;
    cout << setw(40) << "NOMBRE Y APELLIDO:" << setw(30) << this->apenom << endl;
    cout << setw(40) << "CUIT:" << setw(14) << this->cuit << endl;
    domicilio.mostrarDireccion();

}
void Persona::setApenom(){

    cout << "NOMBRE Y APELLIDO:\t";
    cin.getline(this->apenom,20,'\n');
    while(!validarNombresApellidos(this->apenom)){
            msj("INCORRECTO",WHITE,RED,130,TEXT_LEFT);
            cout << "NOMBRE Y APELLIDO:\t";
            cin.getline(this->apenom,20,'\n');
    }
}
void Persona::setCuit(){

    cout << "CUIT:\t";
    cin.getline(this->cuit,14,'\n');
}

void Persona::setDomicilio(){this->domicilio.cargarDireccion();}
