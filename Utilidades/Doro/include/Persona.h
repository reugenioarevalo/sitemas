#ifndef PERSONA_H
#define PERSONA_H

#include "Direccion.h"
#include "Fecha.h"

class Persona{

    protected:
        char apenom[50];
        bool activo;
        Direccion domicilio;
    public:
        Persona();
        //~Persona();
        void cargarPersona();
        void mostrarPersona();
        void setApenom();
        void setApenom(char * ape_nom){strcpy(apenom, ape_nom);}
//        void setNDoc();
//        void setNDoc(char *_nDoc){strcpy(nDoc, _nDoc);}
        void setDomicilio();
        const char * getApenom(){return this->apenom;}
//        const char * getNDoc(){return this->nDoc;}
        bool getEstado(){return this->activo;}
        Direccion getDomicilio(){return this->domicilio;}

};

#endif // PERSONA_H
