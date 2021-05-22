#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
using namespace std;
#include "../Utilidades/menus.h"
#include "Persona.h"
#include "../Utilidades/validaciones.h"
#include "Entidad.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
using namespace rlutil;

Entidad::Entidad():Persona(){

	strcpy(this->razonSocial, "NHHN");
	strcpy(this->mail, "NN@NN");
    this->tipoEntidad=0;

}

//Entidad::~Entidad(){cout << "El Entidad murio";}


void Entidad::cargarCliente(){

    //title("NUEVO CLIENTE", BLACK, CYAN); //-> ARREGLAR
    locate(3,3);
    cargarPersona();
    cin.ignore();
    cout << "RAZON SOCIAL:\t";
    cin.getline(this->razonSocial,50,'\n');
    cout << "EMAIL:\t";
    cin.getline(this->mail,50,'\n');
    setTipoEntidad(1);
    this->idEntidad = crearIdEntidades(this->getTipoEntidad());
    grabarEnDisco(1);

}

void Entidad::cargarProveedor(){

    //title("NUEVO PROVEEDOR", BLACK, CYAN); //-> ARREGLAR
    locate(3,3);
    cargarPersona();
    cin.ignore();
    cout << "RAZON SOCIAL:\t";
    cin.getline(this->razonSocial,50,'\n');
    cout << "EMAIL:\t";
    cin.getline(this->mail,50,'\n');
    setTipoEntidad(2);
    this->idEntidad = crearIdEntidades(this->getTipoEntidad());
    grabarEnDisco(2);
}

void Entidad::mostrarEntidad(){

	mostrarPersona();
	cout << setw(40) << "RAZON SOCIAL:" << setw(30) << this->razonSocial << endl;
	cout << setw(40) << "EMAIL:" << setw(30) << this->mail << endl;
	cout << setw(40) << "CATEGORIA:" << setw(30);
	switch(this->tipoEntidad){
	case 1: cout << "CLIENTE" << endl; break;
	case 2: cout << "PROVEEDOR" << endl; break;
	}
	cout << setw(40) << "ID:" << setw(30) << this->idEntidad << endl;

}

void Entidad::setRazonSocial(char * _razonSocial){strcpy(this->razonSocial,_razonSocial);}

void Entidad::setMail(char * _mail){strcpy(this->mail,_mail);}

void Entidad::setTipoEntidad(int _tipo){this->tipoEntidad = _tipo;}

bool Entidad::grabarEnDisco(int _tipoEntidad){

    system("cls");
    FILE *c, *p;
    bool chequeo;

    switch(_tipoEntidad){

    case 1:
        c = fopen(FILE_CLIENTES,"ab");
        if(c==NULL){
            cout << "Error al abrir el archivo clientes\n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Entidad),1,c);
        if(chequeo==1){

            //msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            cout << "Registro exitoso";
            fclose(c);
            system("pause");
            // cls();
            return true;
        }
        else{
            cout << "El registro no pudo guardarse en clientes\n\n";
            fclose(c);
            system("pause");
            return false;
        }
    break;
    case 2:
        p = fopen(FILE_PROVEEDORES,"ab");
        if(p==NULL){
            cout << "Error al abrir el archivo proveedores\n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Entidad),1,p);
        if(chequeo==1){

            //msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            cout << "Registro exitoso";
            fclose(p);
            system("pause");
            // cls();
            return true;
        }
        else{
            cout << "El registro no pudo guardarse \n\n";
            fclose(p);
            system("pause");
            //cls();
            return false;
        }
    break;

    }
}

bool Entidad::leerDeDisco(int posicion,int _tipoEntidad){ /// Modificar
        bool leyo;
        FILE *c, *p;

        switch(_tipoEntidad){
        case 1:
            c = fopen(FILE_CLIENTES, "rb");
            if (c == NULL){
            cout << "Error archivo de clientes";
            return false;
            }
            fseek(c, posicion * sizeof(Entidad), 0);
            leyo = fread(this, sizeof(Entidad), 1, c);
            fclose(c);
            return leyo;
        break;
        case 2:
            p = fopen(FILE_PROVEEDORES, "rb");
            if (p == NULL){
            cout << "Chotaaaa Error archivo de proveedores";
            return false;
            }
            fseek(p, posicion * sizeof(Entidad), 0);
            leyo = fread(this, sizeof(Entidad), 1, p);
            fclose(p);
            return leyo;
        break;
    }
}
void Entidad::listarEntidadesTabla(int _tipoEntidad){

    Entidad aux;
    bool estadoAux;
    FILE *p, *c;
    int idAux;

    const int POSMENUX = 1;
    const int POSMENUY = 1;
    const int COLOR_PANTALLA = BLACK;
    const int LETRA = DARKGREY;
    const int FONDO = RED;

    setlocale(LC_ALL, "spanish");
    const int ANCHO_MENU = 124;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    //
      cursorX=POSMENUX+0;
      cursorY=POSMENUY +1;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
     int i = 0;
      cout<<endl;
    switch(_tipoEntidad){
        case 1:
            c = fopen(FILE_CLIENTES, "rb");
            if(c==NULL){
                    cout << "Error de archivo\n";
                    system("pause");
                    return;
            }

        title("LISTADO DE  CLIENTES", WHITE, RED);//system("color 0F");
        locate(cursorX,cursorY);
        setBackgroundColor(DARKGREY);
            ///Inicio de cabecera
            cout<<setfill(' ');
            cout<<"|"<<setw(4)<<centrar("ID", 4);
            cout<<"|"<<setw(20)<<centrar("RAZON SOCIAL", 20);
            cout<<"|"<<setw(16)<<centrar("CUIT", 16);
            cout<<"|"<<setw(20)<<centrar("APELLIDO Y NOMBRE", 20);
            cout<<"|"<<setw(20)<<centrar("DIRECCION ",20);
            cout<<"|"<<setw(20)<<centrar("EMAIL",20)<<"|"<<endl;
        setBackgroundColor(BLACK);

        while (aux.leerDeDisco(i++, 1)){
            estadoAux = aux.getEstado();
            if(estadoAux == true){
                cout<<left;
                cout<<" "<<setw(4)<<centrarInt(aux.idEntidad, 4);
                cout<<" "<<setw(20)<<aux.razonSocial;
                cout<<" "<<setw(16)<<aux.cuit;
                cout<<" "<<setw(20)<<aux.apenom;
                aux.domicilio.mostrarDireccion();                cout<<" "<<setw(20)<<aux.mail<<" "<<endl;
            }
        }
            cout<<right;
            cout<<" "<<setw(106)<<setfill('_')<<" "<<endl;
            system("pause");
            fclose(c);
        //        return;
        break;
        case 2:
            p = fopen(FILE_PROVEEDORES, "rb");
            if(p==NULL){
                    cout << "Error de archivo\n";
                    system("pause");
                    return;
            }
        title("LISTADO DE  PROVEEDORES", WHITE, RED);// system("color 0F");
        locate(cursorX,cursorY);
        //    int i = 0;
        setBackgroundColor(DARKGREY);
        ///Inicio de cabecera
          cout<<setfill(' ');
        cout<<"|"<<setw(4)<<centrar("ID", 4);
        cout<<"|"<<setw(20)<<centrar("RAZON SOCIAL", 20);
        cout<<"|"<<setw(16)<<centrar("CUIT", 16);
        cout<<"|"<<setw(20)<<centrar("APELLIDO Y NOMBRE", 20);
        cout<<"|"<<setw(20)<<centrar("DIRECCION ",20);
        cout<<"|"<<setw(20)<<centrar("EMAIL",20)<<"|"<<endl;
        setBackgroundColor(BLACK);
        while (aux.leerDeDisco(i++, 2)){
            estadoAux = aux.getEstado();
            if(estadoAux == true){
                cout<<left;
                cout<<" "<<setw(4)<<centrarInt(aux.idEntidad, 4);
                cout<<" "<<setw(20)<<aux.razonSocial;
                cout<<" "<<setw(16)<<aux.cuit;
                cout<<" "<<setw(20)<<aux.apenom;
                aux.domicilio.mostrarDireccion();                cout<<" "<<setw(20)<<aux.mail<<" "<<endl;

            }
        }
        cout<<right;
        cout<<" "<<setw(106)<<setfill('_')<<" "<<endl;
        system("pause");
        fclose(p);
        //return;
        break;
    }
}
Entidad Entidad::buscarRazonSocial(int tipoEnt){
    FILE *archivo;
    Entidad user;
    char cuit[14];
    int i=0;

    cout<<"\nIngrese el CUIT: ";
    fflush(stdin);
//    cin.ignore();
    cin.getline(cuit, 14, '\n');
    ///abrimos el archivo
    if(tipoEnt==1){
        archivo = fopen(FILE_CLIENTES,"rb");
    }else{
        archivo = fopen(FILE_PROVEEDORES,"rb");
    }

    while (this->leerDeDisco(i++, tipoEnt)){
       if( strcmp(this->cuit, cuit)==0 ){//busca un valor string en el archivo
                cls();
                cout<<"\nRAZON SOCIAL: "<<this->getRazonSocial()<<endl;
                cout<<"CUIT: "<<this->cuit<<endl;
                idEntidad=this->idEntidad;
                fclose(archivo);
            return user;
       }
    }

       if(tipoEnt==1){
        cls();
       cout<<"\nEl Cliente no existe, Por favor ingrese el nuevo cliente:"<<endl;
        this->cargarCliente();

       system("pause");
       }else{
         cls();
       cout<<"\nEl Proveedor no existe, Por favor ingrese el nuevo Proveedor:"<<endl;
       this->cargarProveedor();

       system("pause");
       }
       return user;

}

Entidad Entidad::buscarEntidadXId(int tipoEnt, int pos,  Entidad *user){
// FILE *archivo;
////    Entidad *user;
////user = new Entidad;
//    ///abrimos el archivo
//    if(tipoEnt==1){
//        archivo = fopen(FILE_CLIENTES,"rb");
//    }else{
//        archivo = fopen(FILE_PROVEEDORES,"rb");
//    }
//        ///buscamos y leemos en el;
//        while (this->leerDeDisco(pos, tipoEnt)){
//       if( this->idEntidad == (pos-1)){//Si el id entidad es igual al del archivo devuelve el objeto Entidad
//            fclose(archivo);
//            cout<<this->getRazonSocial();
//
//            return *user;
//
//       }
//    }
//            return *user;
}
//void Entidad::setIdEntidad(){}
	Entidad::~Entidad(){

	}
///--------------------- GLOBALES -------------------------


void listarEntidadPorID(int _tipoEntidad){

    Entidad entiAux;
    FILE *p, *c;
    int idAux;

    cout << "Ingrese ID a buscar:\t";
    cin >> idAux;

    switch(_tipoEntidad){

    case 1:
        c = fopen(FILE_CLIENTES, "rb");
        if(c==NULL){
        return;
        }

            while(fread(&entiAux,sizeof(Entidad),1,c)){
                if(entiAux.getIdEntidad() == idAux){
                    entiAux.mostrarEntidad();
                }
            }

        fclose(c);
        return;
    break;
    case 2:
        p = fopen(FILE_PROVEEDORES, "rb");
        if(p==NULL){
        return;
        }

            while(fread(&entiAux,sizeof(Entidad),1,p)){
                if(entiAux.getIdEntidad() == idAux){
                    entiAux.mostrarEntidad();
                }
            }

        fclose(p);
        return;
    break;
    }
}

bool existenciaEntidad(int idAux, int _tipoEntidad){

    Entidad *entiAux;
    FILE *p, *c;

    switch(_tipoEntidad){

    case 1:
        c = fopen(FILE_CLIENTES, "rb");
        if(c==NULL){return false;}

            while(fread(entiAux,sizeof(Entidad),1,c)){
                if(entiAux->getIdEntidad() == idAux){
                fclose(c);
                return true;
                }
            }

    break;

    case 2:
        p = fopen(FILE_PROVEEDORES, "rb");
        if(p==NULL){return false;}

            while(fread(entiAux,sizeof(Entidad),1,p)){
                if(entiAux->getIdEntidad() == idAux){
                fclose(p);
                return true;
                }
            }
    break;
    }

    return false;
}


int crearIdEntidades(int _tipoEntidad){

    int bytes, cant;
    FILE *c, *p;
    system("pause");
    switch(_tipoEntidad){
    case 1:
        c = fopen(FILE_CLIENTES, "rb");
        if (c == NULL){
            return 1;
        }
        fseek(c, 0, SEEK_END);
        bytes = ftell(c);
        fclose(c);
        cant = bytes / sizeof(Entidad);
        return cant+1;
    break;
    case 2:
        p = fopen(FILE_PROVEEDORES, "rb");
        if (p == NULL){
            return 1;
        }
         fseek(p, 0, SEEK_END);
            bytes = ftell(p);
            fclose(p);

        cant = bytes / sizeof(Entidad);
        return cant+1;
    break;
    }
}

void listarEntidades(int _tipoEntidad){

    Entidad cliAux;
    bool estadoAux;
    FILE *p, *c;
    int idAux;

    switch(_tipoEntidad){
    case 1:
        c = fopen(FILE_CLIENTES, "rb");
        if(c==NULL){
                cout << "Error de archivo\n";
                system("pause");
                return;
        }

            while(fread(&cliAux,sizeof(Entidad),1,c)==1){
                estadoAux = cliAux.getEstado();
                if(estadoAux == true){
                    cliAux.mostrarEntidad();
                }
            }
        system("pause");
        fclose(c);
        return;
    break;
    case 2:
        p = fopen(FILE_PROVEEDORES, "rb");
        if(p==NULL){
                cout << "Error de archivo\n";
                system("pause");
                return;
        }

            while(fread(&cliAux,sizeof(Entidad),1,p)==1){
                estadoAux = cliAux.getEstado();
                if(estadoAux == true){
                    cliAux.mostrarEntidad();
                }
            }
        system("pause");
        fclose(p);
        return;
    break;

    }
}

