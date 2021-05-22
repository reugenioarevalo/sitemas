
#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Login.h"

bool Login::setLogin(bool _acceso=false)
{
    return acceso=_acceso;
}

//Login::~Login(){
//   acceso= false;
//}
void Login::setUser(){
    cout << "\n\t\t\t\t\tIngrese su  Usuario: ";
	cin>>userName;
}
void Login::setPass(){
	cout << "\t\t\t\t\tPassword: ";
    cin>>pass;
}
void Login::getUser(){
    cout<<usuario;
}
void Login::login(){

	int contador = 0;
	do {
		system("cls");
		cout<<endl<<endl<<endl;
		cout << "\t\t\t\t\tBIENVENIDO A TANGA GESTION" << endl;
		cout << "\t\t\t\t\t--------------------------" << endl;
        setUser();
        setPass();
		if (userName == usuario && pass == contrasena) {
                setLogin(true);
		} else {
			cout << "\n\n\t\t\t\t\tEl usuario y/o password son incorrectos" << endl;
			cin.get();
			contador++;
		}
	} while (acceso == false && contador < 3);
    if (acceso == false)
    {
        cout << "\n\t\t\t\t\tHa realizado mas de 3 intentos fallidos! Sayonara!!" << endl;
    }

}

