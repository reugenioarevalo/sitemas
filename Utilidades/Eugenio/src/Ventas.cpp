#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <locale.h>
using namespace std;
#include "Ventas.h"
#include "Fecha.h"
#include "DetalleVenta.h"
#include "DetalleVenta.h"
#include "DetalleFactura.h"
#include "Calculadora.h"
#include "Producto.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/menus.h"


//const char * FILE_VENTAS = "Archivos/Ventas.dat";

///----------------------------METODOS CLASE VENTAS---------------------------

Ventas::Ventas(){
    idCliente=0;
    tipoFactura='B';
}
void Ventas::cargarVtas(){
    setlocale(LC_CTYPE, "Spanish");
    Ventas();
    setTipoFact();
    setNroFact();
char c;
system("cls");
cout<<" Abrir una venta?. ";
cout<<"\nSi: 1";
cout<<"\nNo : 0 "<<endl;
int ok;
cin>>ok;
if(ok==1){
    bool grabo=grabarEnDisco();
    if(grabo==true )    {
        DetalleVenta  det;
        det.cDetalleVenta();
    }    else{
        cout<<"Fallo la grabacion, volver a intentar ";
        system("pause");
        return;
    }
}
return;
}
void Ventas::setNroFact(){
    this->nroFactura=crearIdXFact();
}
void Ventas::setIdCliente(){
    Entidad cliente;
    cliente.buscarRazonSocial(1);
    idCliente=cliente.getIdEntidad();
}
void Ventas::setTipoFact(){
    char tipo;
    cout<<"FACTURA A o B? : ";
    cin>>tipo;
    while(!(tipo == 'A'  || tipo == 'B' ))
    {
        cout<<"Tipo de factura incorrecta";
        system("pause");
        system("cls");
        cout<<"Tipo de factura : ";
        cin>>tipo;
    }
    if(tipo=='A'){
        setIdCliente();
    }

    this->tipoFactura=tipo;
    int crearIdXFact();

}
bool Ventas::grabarEnDisco(){
    system("cls");
    FILE *p;
    bool chequeo;

        p = fopen(FILE_VENTAS,"ab");
        if(p==NULL)
        {
            cout << "Error al abrir el archivo \n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Ventas),1,p);
        if(chequeo==1)
        {
             fclose(p);
              return true;
        }
        else
        {
            cout << "El registro no pudo guardarse \n\n";
            fclose(p);

            system("pause");
            return false;
        }


}
bool Ventas::leerDeDisco(int posicion){
    bool leyo;
    FILE *p;
        p = fopen(FILE_VENTAS, "rb");
        if (p == NULL)
        {
            return false;
        }
        fseek(p, posicion * sizeof(Ventas), 0);
        leyo = fread(this, sizeof(Ventas), 1, p);
        fclose(p);
        return leyo;
}
void Ventas::listado_facturas(){

    Ventas aux;
    int i = 0;

        ///Inicio de cabecera
        cout<<"|"<<setw(104)<<centrar("CABECERA DETALLE DE VENTAS", 104)<<"|"<<endl;
        cout<<"|"<<setw(105)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(4)<<centrar("ID", 4);
        cout<<"|"<<setw(7)<<centrar("TIPO", 7);
        cout<<"|"<<setw(12)<<centrar("FECHA", 12);
        cout<<"|"<<setw(22)<<centrar("ID CLIENTE", 22)<<endl;

        cout<<"|"<<setw(105)<<setfill('_')<<"|"<<endl;
        cout<<" "<<setw(105)<<setfill(' ')<<" "<<endl;

        while (aux.leerDeDisco(i++))
        {
            cout<<"|"<<setw(4)<<centrarInt(aux.nroFactura, 4);
            cout<<" "<<setw(7)<<aux.tipoFactura;
            cout<<" "<<setw(2)<<aux.fechaVenta.getDia()<<setw(1)<<"/";
            cout<<setw(2)<<aux.fechaVenta.getMes()<<setw(1)<<"/";
            cout<<setw(4)<<aux.fechaVenta.getAnio()<<setw(2)<<" ";
            cout<<" "<<setw(22)<<centrarInt(aux.idCliente, 22)<<endl;
        }
            cout<<setfill(' ')<<endl;
            system("pause");
}

///--------------------------------------FUNCIONES GLOBALES------------------------------------

int crearIdXFact(){
    int bytes, cant;


        FILE *p = fopen(FILE_VENTAS, "rb");
        if (p == NULL)
        {
            return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        fclose(p);

    cant = bytes / sizeof(Ventas);
    return cant+1;
}

