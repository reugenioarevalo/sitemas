#ifndef Entidad_H
#define Entidad_H
#define FILE_CLIENTES "Archivos/Clientes.dat"
#define FILE_PROVEEDORES "Archivos/Proveedores.dat"

#include "../Include/Persona.h"



class Entidad: public Persona{

	private:
        char razonSocial[50];
        char mail[50];
        int idEntidad;
        int tipoEntidad; /// -> diferencia a clientes de proveedores
//        char cuit[13];
	public:

		Entidad();
		Entidad(char*, char*, int);
		~Entidad();
		void cargarCliente();
		void cargarProveedor();
		void mostrarEntidad();
//        void setIdEntidad();
        void setRazonSocial(char *);
        void setMail(char *);
        void setTipoEntidad(int);
        bool grabarEnDisco(int);
        bool leerDeDisco(int, int);
        const char* getRazonSocial(){return this->razonSocial;}
        const char* getMail(){return this->mail;}
        int getTipoEntidad(){return this->tipoEntidad;}
        int getIdEntidad(){return this->idEntidad;}
        const char * getCuit(){return this->cuit;}
//        void listarEntidadesTabla(int); /// Lista todos los Entidads del archivo
        Entidad buscarRazonSocial(int);
        Entidad buscarEntidadXId(int, int, Entidad *);

void listarEntidadesTabla(int);

};

void listarEntidadPorID(int); /// Lista un Entidad por un id que pregunta dentro de la funcion

bool existenciaEntidad(int, int); /// Corrobora si una entidad existe en el archivo de entidades

int crearIdEntidades(int); /// Crea un id autonumerico para el Entidad

void listarEntidades(int); /// Lista todos los Entidads del archivo


#endif // Entidad_H
