#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<cstring>
using namespace std;
#include "Productos.h"
#include "Producto.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/rlutil.h"
#include "../Utilidades/ui.h"
using namespace rlutil;

//const char *FILE_PRODUCTOS="Archivos/Productos.dat";


/*void Productos::mostrarEntidad(){

	mostrarPersona();
	cout << setw(40) << "RAZON SOCIAL:" << setw(30) << this->razonSocial << endl;
	cout << setw(40) << "EMAIL:" << setw(30) << this->mail << endl;
	cout << setw(40) << "CATEGORIA:" << setw(30);
	switch(this->tipoEntidad){
	case 1: cout << "CLIENTE" << endl; break;
	case 2: cout << "PROVEEDOR" << endl; break;
	}
	cout << setw(40) << "ID:" << setw(30) << this->idEntidad << endl;

}*/

void Productos::listarProductos(){

    Producto aux;
    bool estadoAux;
    FILE *p;
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
      cout<<endl;
//      locate(POSMENUX+1,POSMENUY+1);
    title("LISTADO DE  PRODUCTOS", WHITE, RED);
//        system("color 0F");
    locate(cursorX,cursorY);
///---------------------------------------------------------------------
    p = fopen("Archivos/Productos.dat", "rb");
    if(p==NULL){
        cout << "Error de archivo\n";
        system("pause");
        return;
        }
    int i = 0;
    setBackgroundColor(DARKGREY);
    ///Inicio de cabecera
    cout<<"|"<<setw(4)<<centrar("ID", 4);
    cout<<"|"<<setw(38)<<centrar("DETALLE", 38);
    cout<<"|"<<setw(10)<<centrar("STOCK", 10);
    cout<<"|"<<setw(9)<<centrar("STOCK MIN", 9);
    cout<<"|"<<setw(16)<<centrar("PRECIO COSTO",16);
    cout<<"|"<<setw(16)<<centrar("ID PROVEEDOR",16);
    cout<<"|"<<setw(6)<<centrar("ESTADO",6)<<"|"<<endl;


    setBackgroundColor(BLACK);

    while (aux.leerDeDisco(i++)){
        estadoAux = aux.getEstado();
        if(estadoAux == true){
            cout<<left;
            cout<<" "<<setw(4)<<centrarInt(aux.getId(), 4);
            cout<<" "<<setw(38)<<aux.getDescripcion();
            cout<<right;
            cout<<" "<<setw(10)<<centrarInt(aux.getStock(),10);
            cout<<" "<<setw(9)<<centrarInt(aux.getStockMin(),9);
            cout<<" "<<setw(16)<<aux.getPrecioCosto();
            cout<<" "<<setw(16)<<centrarInt(aux.getCodProv(),16);
            //cout<<" "<<setw(6)<<aux.getEstado()<<" "<<endl;
            if(aux.getEstado()){
                cout<<" "<<setw(6)<<"Activo"<<" "<<endl;
            }else{cout<<" "<<setw(6)<<"Pasivo"<<" "<<endl;}
        }
    }

    cout<<" "<<setw(107)<<setfill('_')<<" "<<endl;
    cout<<" ";
    system("pause");
    fclose(p);

}

void Productos::listarProdXIdProv(int idPr){
    Producto aux;
    FILE *p;
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
      cout<<endl;
//      locate(POSMENUX+1,POSMENUY+1);
    title("LISTADO DE  PRODUCTOS", WHITE, RED);
//        system("color 0F");
    locate(cursorX,cursorY);
///---------------------------------------------------------------------
    p = fopen("Archivos/Productos.dat", "rb");
    if(p==NULL){
        cout << "Error de archivo\n";
        system("pause");
        return;
        }
    int i = 0;
    setBackgroundColor(DARKGREY);
    ///Inicio de cabecera
    cout<<"|"<<setw(4)<<centrar("ID", 4);
    cout<<"|"<<setw(38)<<centrar("DETALLE", 38);
    cout<<"|"<<setw(10)<<centrar("STOCK", 10);
    cout<<"|"<<setw(9)<<centrar("STOCK MIN", 9);
    cout<<"|"<<setw(16)<<centrar("PRECIO COSTO",16);
    cout<<"|"<<setw(16)<<centrar("ID PROVEEDOR",16);
    cout<<"|"<<setw(6)<<centrar("ESTADO",6)<<"|"<<endl;


    setBackgroundColor(BLACK);

    while (aux.leerDeDisco(i++)){

        if(idPr == aux.getCodProv()){
            cout<<left;
            cout<<" "<<setw(4)<<centrarInt(aux.getId(), 4);
            cout<<" "<<setw(38)<<aux.getDescripcion();
            cout<<right;
            cout<<" "<<setw(10)<<centrarInt(aux.getStock(),10);
            cout<<" "<<setw(9)<<centrarInt(aux.getStockMin(),9);
            cout<<" "<<setw(16)<<aux.getPrecioCosto();
            cout<<" "<<setw(16)<<centrarInt(aux.getCodProv(),16);
            //cout<<" "<<setw(6)<<aux.getEstado()<<" "<<endl;
            if(aux.getEstado()){
                cout<<" "<<setw(6)<<"Activo"<<" "<<endl;
            }else{cout<<" "<<setw(6)<<"Pasivo"<<" "<<endl;}
        }
    }

    cout<<" "<<setw(107)<<setfill('_')<<" "<<endl;
    cout<<" ";
    system("pause");
    fclose(p);

}

