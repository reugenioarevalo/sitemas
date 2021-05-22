#ifndef DIRECCION_H
#define DIRECCION_H

#include "Direccion.h"
#include "Fecha.h"
#include "string.h"

class Direccion{

	private:
		char calle[30];
		int numero;
		int codPost;
		char localidad[30];

	public:
		Direccion(char *, int, int, char *);
		Direccion();
		virtual ~Direccion(){};
		void cargarDireccion();
		void setCalle(char * _calle){strcpy(calle, _calle);}
		void setNumero (int _numero){numero = _numero;}
		void setCodPost(int _codPost){codPost = _codPost;}
        void setLocalidad(char* _localidad){strcpy(localidad, _localidad);}
        void mostrarDireccion();
        const char* getCalle(){return calle;}
        int getNumero(){return numero;}
        int getCodPost(){return codPost;}
        const char* getLocalidad(){return localidad;}
};

#endif // DIRECCION_H
