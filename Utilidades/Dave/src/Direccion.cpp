#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Direccion.h"
#include "Fecha.h"

using namespace std;


Direccion::Direccion(char * _calle, int _numero){

    strcpy(calle, _calle);
    numero = _numero;

}

Direccion::Direccion(){

    strcpy(calle, "NS/NC");
    numero = 0;
}

void Direccion::cargarDireccion(){

	cin.ignore();
	cout << "CALLE:\t";
	cin.getline(calle,30,'\n');	cout << "ALTURA:\t";
	cin >> this->numero;
}

void Direccion::mostrarDireccion(){
cout<<" "<<setw(20)<<this->calle;
}
