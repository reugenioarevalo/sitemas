#include <iostream>
#include <iomanip>
#include <cstring>
#include "../Utilidades/menus.h"
#include "Persona.h"
#include "../Utilidades/validaciones.h"
#include "Cliente.h"

using namespace std;

Cliente::Cliente():Persona(){

	strcpy(this->razonSocial, "NN");
	strcpy(this->mail, "NN@NN");
    this->tipoCliente=0;

}


void  Cliente::setIdCliente(){
    this->idCliente=45;
     return ;
}
int  Cliente::getIdCliente(){
 return idCliente;
}
