#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <locale.h>
using namespace std;
#include "Compras.h"
#include "Fecha.h"
#include "DetalleVenta.h"
#include "DetalleVenta.h"
#include "DetalleFactura.h"
#include "Calculadora.h"
#include "Producto.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/menus.h"
#include "Entidad.h"

const char *FILE_COMPRAS="Archivos/Compras.dat";
Compras::Compras(){
    this->idCompras=crearIdXCompras();
//    cout<<"este es el ID COMPRAS \n"<<idCompras;
}
void Compras::cargarCompras(){
    Compras();
    setlocale(LC_CTYPE, "Spanish");
    setTipoFact();
    setPuntoVta();
    setNroFactura();
    system("cls");
    cout<<" Cargar la Compra?. ";
    cout<<"\nSi: 1";
    cout<<"\nNo : 0 "<<endl;
    int ok;
    cin>>ok;
    if(ok==1){
        bool grabo=grabarEnDisco();
        if(grabo==true )    {
                cout<<"\nSe cargo la cabecera."<<endl;
            DetalleCompra  det;
            det.cDetalleCompra();
        }else{
            cout<<"Error en la carga!!!. Volver a intentar ";
            return;
        }
    }
    return;
}
void Compras::setTipoFact(){
    char tipo;
    cout<<"FACTURA A o C? : ";
    cin>>tipo;
    while(!(tipo == 'A'  || tipo == 'C' ))
    {
        cout<<"Tipo de factura incorrecta";
        system("pause");
        system("cls");
        cout<<"Tipo de factura : ";
        cin>>tipo;
    }
    setIdEntidad();
    this->tipoFactura=tipo;

}
void Compras::setIdEntidad(){
    proveedor.buscarRazonSocial(2);
    idEntidad=proveedor.getIdEntidad();
}
int Compras::getIdEntidad(){
    return this->idEntidad;
}
void Compras::setPuntoVta(){
     cout<<"\npunto de Vta: ";
    cin>>this->puntoVta;
}
void Compras::setNroFactura(){
    int a;
    cout<<"Numero de Factura: ";
    cin>>a;
    this->nroFactura=a;
}
bool Compras::grabarEnDisco(){
    system("cls");
    FILE *p;
    bool chequeo;
    p = fopen(FILE_COMPRAS,"ab");
    if(p==NULL){return false;}
    chequeo = fwrite(this, sizeof(Compras),1,p);
    if(chequeo==1){
            fclose(p);return true;
    }else{
        fclose(p);return false;
    }
}
bool Compras::leerDeDisco(int posicion){
    bool leyo;
    FILE *p;
        p = fopen(FILE_COMPRAS, "rb");
        if (p == NULL){ return false;}
        fseek(p, posicion * sizeof(Compras), 0);
        leyo = fread(this, sizeof(Compras), 1, p);
        fclose(p);
        return leyo;
}
void Compras::listado_compras(){
    Compras aux;
    int i = 0;

        ///Inicio de cabecera
        cout<<"|"<<setw(104)<<centrar("CABECERA DETALLE DE COMPRAS", 104)<<"|"<<endl;
        cout<<"|"<<setw(105)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(4)<<centrar("ID", 4);
        cout<<"|"<<setw(7)<<centrar("TIPO", 7);
        cout<<"|"<<setw(12)<<centrar("FECHA", 12);
        cout<<"|"<<setw(22)<<centrar("PROVEEDOR ", 22)<<"|"<<endl;
        cout<<"|"<<setw(105)<<setfill('_')<<"|"<<endl;
        cout<<" "<<setw(105)<<setfill(' ')<<" "<<endl;

        while (aux.leerDeDisco(i++)){
            cout<<"|"<<setw(4)<<centrarInt(aux.idCompras, 4);
            cout<<" "<<setw(7)<<aux.tipoFactura;
            cout<<" "<<setw(2)<<aux.fechaFactura.getDia()<<setw(1)<<"/";
            cout<<setw(2)<<aux.fechaFactura.getMes()<<setw(1)<<"/";
            cout<<setw(4)<<aux.fechaFactura.getAnio()<<setw(2)<<" ";
            cout<<" "<<setw(22)<<centrarInt(aux.getIdEntidad(), 22)<<endl;
        }
            cout<<setfill(' ')<<endl;

}
int Compras::getPuntoVta(){return puntoVta;}
int Compras::getNroFactura(){return nroFactura;}
char Compras::getTipoFact(){return tipoFactura;}
///--------------------------------------FUNCIONES GLOBALES------------------------------------
int crearIdXCompras(){
    int bytes, cant;
    FILE *p = fopen(FILE_COMPRAS, "rb");
    if (p == NULL){return 1; }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Ventas);
    return cant+1;
}
