#ifndef USUARIO_H
#define USUARIO_H


class Usuario{
	private:
		char nombreUser[25];
		char password[20];
		bool estado;
		int idUser;
	public:
		void crearUsuario();
        void setNombreUser();
        void setPassword();
        void setNewPassword();
        void setPassword(char * newPass){strcpy(this->password, newPass);}
        void setActivo(){this->estado = true;}
        void setInactivo(bool nuevoEstado){this->estado = nuevoEstado;}
        void ingresarUsuario();
        void setIdUser(int id){this->idUser = id;}
        bool cambiarPasswordUser();
        bool grabarEnDisco();
        bool leerDeDisco(int);
        char* getNombreUser(){return this->nombreUser;}
        char* getPassword(){return password;}
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

void cambiarPasswordAdmin();

void cambiarPasswordUser();

bool usuarioRepetido(char* nombreUsuario); /// falta arreglar

#endif // USUARIO_H
