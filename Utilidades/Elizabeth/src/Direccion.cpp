#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Direccion.h"
#include "Fecha.h"

using namespace std;

//Direccion::Direccion(char * _calle, int _numero, int _codPost, char * _localidad){
Direccion::Direccion(char * _calle, int _numero){

    strcpy(calle, _calle);
    numero = _numero;
//    codPost = _codPost;
//    strcpy(localidad, _localidad);
}

Direccion::Direccion(){

    strcpy(calle, "NS/NC");
    numero = 0;
//    codPost = 0;
//    strcpy(localidad, "NS/NC");

}

void Direccion::cargarDireccion(){

	cin.ignore();
	cout << "CALLE:\t";
	cin.getline(calle,30,'\n');	cout << "ALTURA:\t";
	cin >> this->numero;
//	cout << "CODIGO POSTAL:\t";
//	cin >> this->codPost;//	cin.ignore();
//	cout << "LOCALIDAD:\t";
//	cin.getline(localidad,30,'\n');
}

void Direccion::mostrarDireccion(){

//	cout << left;
cout<<" "<<setw(20)<<this->calle ;
//	cout << setw(40) << "CALLE Y ALTURA:" << setw(25) << this->calle << setw(5) << this->numero << endl;
//	cout << setw(40) << "CODIGO POSTAL:" << setw(30) << this->codPost << endl;
//	cout << setw(40) << "LOCALIDAD:" << setw(30) << this->localidad << endl;

}
