#ifndef USUARIO_H
#define USUARIO_H


class Usuario{
	private:
		char nombreUser[25];
		int password;
		bool estado;
		int idUser;
	public:
//		Usuario();
//		virtual ~Usuario();
        void setNombreUser();
        void setPassword();
        void setPassword(int newPass){this->password = newPass;}
        void setActivo(){this->estado = true;}
        void setInactivo(bool nuevoEstado){this->estado = nuevoEstado;}
        void ingresarUsuario();
        void setIdUser(int id){this->idUser = id;}
        bool grabarEnDisco();
        bool leerDeDisco(int);
        char* getNombreUser(){return this->nombreUser;}
        const char* getNombreUser(char* nombAux){strcpy(nombAux, this->nombreUser);}
        int getPassword(){return password;}
        bool getEstado(){return estado;}
        int getIdUser(){return this->idUser;}
};

///--------------------------------- GLOBAL

void crearUsuario();

int login();

void listarUsuarios();

int crearIdUsuario();

void bajaLogicaUsuario();

int crearIdUsuario();

void cambiarPassword();

#endif // USUARIO_H
