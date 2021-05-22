#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <locale.h>
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "Usuario.h"

using namespace std;
using namespace rlutil;


const char * FILE_USUARIOS = "Archivos/Usuarios.dat";

void Usuario::setNombreUser(){
    setlocale(LC_CTYPE, "Spanish");
    cout << "NOMBRE DE USUARIO: ";
	cin>>this->nombreUser;
}

void Usuario::setPassword(){
    cout << "CONTRASEÑA: ";
	cin>>this->password;
}

void Usuario::ingresarUsuario(){

    setNombreUser();
    setPassword();

}

bool Usuario::grabarEnDisco(){

    system("cls");
    FILE *c;
    bool chequeo;

        c = fopen(FILE_USUARIOS,"ab");
        if(c==NULL){
            cout << "Error al abrir el archivo clientes\n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Usuario),1,c);
        if(chequeo==1){

            msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            fclose(c);
            system("cls");
            return true;
        }
        else{
            cout << "El registro no pudo guardarse en clientes\n\n";
            fclose(c);
            system("pause");
            return false;
        }

    }

bool Usuario::leerDeDisco(int posicion){
        bool leyo;
        FILE *c;

            c = fopen(FILE_USUARIOS, "rb");
            if (c == NULL){
            cout << "Error archivo de USUARIOS";
            return false;
            }
            fseek(c, posicion * sizeof(Usuario), 0);
            leyo = fread(this, sizeof(Usuario), 1, c);
            fclose(c);
            return leyo;

}


///--------------------------------- GLOBAL

void crearUsuario(){

	Usuario regAux;

	regAux.ingresarUsuario();
    regAux.setIdUser(crearIdUsuario());
	regAux.setActivo();
	regAux.grabarEnDisco();

}

void listarUsuarios(){

    Usuario usuAux;
    bool estadoAux;
    FILE *c;

        c = fopen(FILE_USUARIOS, "rb");
        if(c==NULL){
                cout << "Error de archivo usuarios\n";
                system("pause");
                return;
        }

            while(fread(&usuAux,sizeof(Usuario),1,c)==1){
                estadoAux = usuAux.getEstado();
                if(estadoAux == true || estadoAux == 1){
                    cout  << "USER:" << usuAux.getNombreUser() << "\t"<< "PASSWORD:" << usuAux.getPassword() << "\tID\t" << usuAux.getIdUser() << "\tESTADO:\t" << usuAux.getEstado() << endl;
                }
//                cout << endl;
            }
        system("pause");
        fclose(c);
        return;
}

int login(){

    Usuario userLog, usuAux;
    int passAux, i=0;
    char *nombreAux;
    bool estadoAux;
    const int POSMENUX = 35;
    const int POSMENUY = 2;

    locate(POSMENUX+5,POSMENUY+1);
    userLog.setNombreUser();
    locate(POSMENUX+5,POSMENUY+2);
    userLog.setPassword();


    if(strcmp(userLog.getNombreUser(), "ADMIN")== 0){
        if(userLog.getPassword() == 1234){
            msj("INGRESO EXITOSO",WHITE,GREEN,130,TEXT_LEFT);
            return 2;
        }
    }
            while(usuAux.leerDeDisco(i++)){

                if(usuAux.getEstado() == true || usuAux.getEstado() == 1){

                    if(strcmp(userLog.getNombreUser(), usuAux.getNombreUser())== 0){
                        if(userLog.getPassword() == usuAux.getPassword()){
                            msj("INGRESO EXITOSO",WHITE,GREEN,130,TEXT_LEFT);
                            return 1;
                        }else{
							msj("CONTRASEÑA INCORRECTA",WHITE,RED,130,TEXT_LEFT);
							return 0;
							cout << endl;
                        }
                }
            }
        }
        msj("USUARIO INEXISTENTE",WHITE,RED,130,TEXT_LEFT);
        cout << endl;
		return 0;
}

void bajaLogicaUsuario(){

    Usuario usuAux;
    bool estadoAux;
    FILE *c;
    int idAux, i=0;

    cout << "INGESE ID:\t";
    cin >> idAux;

        c = fopen(FILE_USUARIOS, "rb+");
        if(c==NULL){
                cout << "Error de archivo usuarios\n";
                system("pause");
                return;
        }

            while(fread(&usuAux,sizeof(Usuario),1,c) == 1){
//            while(usuAux.leerDeDisco(i++)){
                if(usuAux.getIdUser() == idAux){
                    cout  << "USER:" << usuAux.getNombreUser() << "\t"<< "PASSWORD:" << usuAux.getPassword();
                    cout << endl;
                    usuAux.setInactivo(false);
                    fseek(c, sizeof(Usuario)*i, SEEK_SET);
                    fwrite(&usuAux,sizeof(Usuario),1,c);
                    fclose(c);
                    msj("BAJA EXITOSA",WHITE,GREEN,130,TEXT_LEFT);
                    return;
                }
                i++;
            }
        msj("USUARIO NO ENCONTRADO",WHITE,RED,130,TEXT_LEFT);
        system("pause");
        fclose(c);
        return;
}

int crearIdUsuario(){


    int bytes, cant;
    FILE *p = fopen(FILE_USUARIOS, "rb");
     if (p == NULL){
        return 1;
    }
	fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
	cant = bytes / sizeof(Usuario);
    return cant+1;

}

void cambiarPassword(){

    Usuario usuAux;
    bool estadoAux;
    FILE *c;
    int newPass;
    int idAux, i=0;

    cout << "INGESE ID:\t";
    cin >> idAux;

        c = fopen(FILE_USUARIOS, "rb+");
        if(c==NULL){
                cout << "Error de archivo usuarios\n";
                system("pause");
                return;
        }

            while(fread(&usuAux,sizeof(Usuario),1,c) == 1){
                if(usuAux.getIdUser() == idAux){
                    cout << "NUEVA CONTRASEÑA:\t";
                    cin >> newPass;
                    usuAux.setPassword(newPass);
                    fseek(c, sizeof(Usuario)*i, SEEK_SET);
                    fwrite(&usuAux,sizeof(Usuario),1,c);
                    fclose(c);
                    msj("CONTRASEÑA GUARDADA",WHITE,GREEN,130,TEXT_LEFT);
                    return;
                }
                i++;
            }
        msj("USUARIO NO ENCONTRADO",WHITE,RED,130,TEXT_LEFT);
        system("pause");
        fclose(c);
        return;
}
