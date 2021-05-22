#ifndef PERSONA_H
#define PERSONA_H

#include "Direccion.h"
#include "Fecha.h"

class Persona{

    protected:
        bool activo;
        Direccion domicilio;
        char cuit[14];
        char apenom[20];
    public:
        Persona();
        //~Persona();
        void cargarPersona();
        void mostrarPersona();
        void setApenom();
        void setApenom(char * ape_nom){strcpy(apenom, ape_nom);}
        void setCuit();
        void setCuit(char * _cuit){strcpy(cuit, _cuit);}
        void setDomicilio();
        const char * getApenom(){return this->apenom;}
        const char * getCuit(){return this->cuit;}
        bool getEstado(){return this->activo;}
        Direccion getDomicilio(){return this->domicilio;}

};

#endif // PERSONA_H
