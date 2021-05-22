#include <iostream>
#include <iomanip>
#include <conio.h>
#include <sstream>
using namespace std;
#include "centrarTabla.h"

string Convert (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

string centrar(string cadena, int largo){
    int campo = cadena.length();
    int diferncia = largo -campo;
    int parte1 = diferncia/2;
    int parte2 = diferncia - parte1;
    return string(parte1, ' ') + cadena+string(parte2, ' ');
}

string centrarInt(int entero, int largo){
    string cadena= Convert(entero);

    int campo = cadena.length();
    int diferncia = largo -campo;
    int parte1 = diferncia/2;
    int parte2 = diferncia - parte1;
    return string(parte1, ' ') + cadena+string(parte2, ' ');
}

string centrarfloat(float dfloat, int largo){
    string cadena= Convert(dfloat);

    int campo = cadena.length();
    int diferncia = largo -campo;
    int parte1 = diferncia/2;
    int parte2 = diferncia - parte1;
    return string(parte1, ' ') + cadena+string(parte2, ' ');
}
string derechafloat(float dfloat, int largo){
    string cadena= Convert(dfloat);
    int campo = cadena.length();
    int diferncia = largo -campo;
    return string(diferncia, ' ') +cadena;
}
string derechaInt(int dato, int largo){
    string cadena= Convert(dato);
    int campo = cadena.length();
    int diferncia = largo -campo;
    return string(diferncia, '0') +cadena;
}
