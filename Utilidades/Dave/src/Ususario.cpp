
#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include "Ususario.h"

Ususario::Ususario(){}
Ususario::~Ususario(){}
void Ususario::setUser(){char _u[20];cin.getline(_u, 20);strcpy(usuario, _u);}
void Ususario::setPass(){char _p[15];cin.getline(_p, 15);strcpy(password, _p);}
void Ususario::getUser(){cout<<usuario;}
void Ususario::getPass(){cout<<password;}
void Ususario::cargarUsuario(){}
void Ususario::grabarUsuario(){}
void leerUsuarios(){}

