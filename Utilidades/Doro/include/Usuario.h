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
        void setActivo(){this->estado = true;}
        void setInactivo(){this->estado = false;}
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

bool login();

void listarUsuarios();

int crearIdUsuario();



#endif // USUARIO_H
