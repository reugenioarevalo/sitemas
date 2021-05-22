#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <locale.h>
using namespace std;
#include "DetalleVenta.h"
#include "Ventas.h"
#include "Producto.h"
#include "Productos.h"
#include "Entidad.h"
#include "Calculadora.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "../Utilidades/menus.h"
#include "Contable.h"
using namespace rlutil;

void DetalleVenta::cDetalleVenta(){
 setlocale(LC_CTYPE, "Spanish");
    Ventas dato;
        Contable ctb;
    //    Contable cont;
    int i= crearIdXFact()-2;
    dato.leerDeDisco(i);

    int continuar;
    do{
        this->idDetalle= crearIdDetalle();
        tipoFactura= dato.getTipoFact();
        nroFactura= dato.getNroFact();
        setCodProducto();
        setPrecio();
        grabarDetalleEnDisco();
        ctb.imputarCta(dato.fechaVenta.getDia(), dato.fechaVenta.getMes(), dato.fechaVenta.getAnio(),  nroFactura, cantidad, 1, getCodProducto());

        system("cls");
        cout<<"\nCountinua comprando?. ";
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;
    cin>> continuar;
    }while(continuar==1);
    imprimirFactura(getNroFactura());
    return;
}
void DetalleVenta::setCodProducto(){
    Producto prod;
    cout<<"Ingrese codigo producto : ";
    cin>>codProd;
    while(codProd<=0){
         cout<<"ERROR en el idProducto, Ingrese un codigo de producto valido : ";
        cin>>codProd;
    }
        prod.buscarProdxId(codProd);
        cout<<"Precio: $"<< prod.getPrecioCosto()<<endl;
        setCantProducto();
        prod.setMod(codProd, 1, cantidad,  prod.getPrecioCosto());
}
void DetalleVenta::setCantProducto(){
    Producto prod;
    prod.setStock(0);
    this->cantidad=prod.getStock();
}
bool DetalleVenta::grabarDetalleEnDisco(){

    system("cls");
    FILE *p;
    bool chequeo;

    p = fopen(FILE_DETALLE,"ab");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return false;
    }

    chequeo = fwrite(this, sizeof(DetalleVenta),1,p);
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
bool DetalleVenta::leerDeDiscoD(int posicion){
    bool leyo;
    FILE *p;
    p = fopen(FILE_DETALLE, "rb");
    if (p == NULL)
    {

        return false;
    }
    fseek(p, posicion * sizeof(DetalleVenta), 0);
    leyo = fread(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return leyo;
}
void DetalleVenta::listado_detalle(){
    DetalleVenta aux;
    int i = 0;
    ///Inicio de cabecera
    title("DETALLE DE FACTURAS",WHITE, RED);
    cout<<endl;
    setBackgroundColor(DARKGREY);
    cout<<" "<<setw(15)<<centrar("Id", 15)<<"|";
    cout<<" "<<setw(15)<<centrar("# Fact", 15)<<"|";
    cout<<" "<<setw(38)<<centrar("Tipo de Factura", 38)<<"|"<<endl;
    setBackgroundColor(BLACK);

    while (aux.leerDeDiscoD(i++)){
    cout<<" "<<setw(15)<<centrarInt(aux.idDetalle, 15);
    cout<<" "<<setw(15)<<centrarInt(aux.getNroFactura(), 15);
    cout<<" "<<setw(21)<<aux.getTipoFactura()<<endl;
     }
    cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
    system("pause");
}
char DetalleVenta::getTipoFactura(){
    return tipoFactura;}
void DetalleVenta::setIdCliente(){
    Ventas dato;
    this->idCliente=dato.getIdCliente();}
char DetalleVenta::getIdCliente(){
    return idCliente;}
void DetalleVenta::setNroFactura(){
     Ventas dato;
    this->nroFactura=dato.getNroFact();}
void DetalleVenta::setIdDetalle(){
    this->idDetalle=crearIdDetalle();}
int DetalleVenta::getNroFactura(){
    return nroFactura;}
void DetalleVenta::imprimirFactura(int _n){
    int pos= crearIdXFact()-2;
    float  sTot=0, sIva=0, tTot=0, tPrUn=0;
    DetalleVenta aux;
    Ventas  dato;
    Entidad cliente;
    Producto prod;
    int i =0,  f;
    cls();
    if(_n == 0){
    cout<<"\nIngrese el numero de factura que desea imprimir: ";
    cin>>f;
    }else{
        f=_n;
    }
    cls();
    dato.leerDeDisco(f-1);
    cliente.leerDeDisco(dato.getIdCliente()-1,1);
    char a[30];
        if(dato.getTipoFact()=='A'){
             system("color 0E");
           setBackgroundColor(BLUE);
        }else{
             system("color 0F");
            setBackgroundColor(RED);
        }
    strcpy(a, "FACTURA ");
            cout<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(88)<<centrar(a, 87)<<"|"<<endl;
            cout<<"|"<<setw(88)<<dato.getTipoFact()<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;            cout<<"|"<<setw(69)<<""<<"Nro Fac: 0001-"<<derechaInt(f, 5)<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<right;
            cout<<"|"<< "TONGA GESTION SRL   "<<setw(31)<<""; if(dato.getTipoFact()=='A'){cout<<"R.SOCIAL :"<<setw(27)<<cliente.getRazonSocial() <<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
            cout<<"|"<< "info@tongagest.com  "<<setw(31)<<"";if(dato.getTipoFact()=='A'){cout<<"MAIL     :"<<setw(27)<<cliente.getMail()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
            cout<<"|"<< "Dir: Yrigoyen 197   "<<setw(31)<<"";if(dato.getTipoFact()=='A'){cout<<"DIR      :"<<setw(27)<<cliente.getDomicilio().getCalle()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
            cout<<"|"<< "Cod Post : 1640     "<<setw(31)<<"";if(dato.getTipoFact()=='A'){cout<<"CUIT     :"<<setw(27)<<cliente.getCuit()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(9)<<centrar("CODPROD", 9);
            cout<<"|"<<setw(28)<<centrar("DESCRIPCION", 28);
            cout<<"|"<<setw(10)<<centrar("CANTIDAD", 10);
            cout<<"|"<<setw(10)<<centrar("PRECIO", 10);
            cout<<"|"<<setw(10)<<centrar("IVA", 10);
            cout<<"|"<<setw(16)<<centrar("SUB TOT", 16)<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
        while (aux.leerDeDiscoD(i++)){
        if(aux.getNroFactura()==f){
             prod.leerDeDisco(prod.buscarProdxId(aux.getCodProducto()));
                cout<<setfill(' ');
                cout<<"|"<< setw(9)<<centrarInt(aux.getCodProducto(), 9);
                cout<<left;
                cout<<"|"<< setw(28)<<prod.getDescripcion();
                cout<<right;
                cout<<"|"<< setw(10)<<centrarInt(aux.getCantProducto(), 10);
                cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<aux.getPrecio();
                 cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<(aux.getPrecio()*prod.getIva()/100);
                 cout<<"|"<<setw(16)<<fixed<<setprecision(2)<<((aux.getPrecio()+(aux.getPrecio()*prod.getIva()/100))*aux.getCantProducto())<<"|"<<endl;
                tPrUn+=aux.getPrecio();
                sTot+=(aux.getPrecio()*aux.getCantProducto());
                sIva+=((aux.getPrecio()*prod.getIva())/100*aux.getCantProducto());
        }
        }
                tTot+=(sIva+sTot);
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<< right;
           cout<<"|"<<setw(80)<<"SubTotal:$"<<setw(8)<<fixed<<setprecision(2)<<sTot<<"|"<<endl;
            cout<<"|"<<setw(80)<<"Total Iva:$"<<setw(8)<<fixed<<setprecision(2)<<sIva<<"|"<<endl;
            cout<<"|"<<setw(80)<<"Total Final:$"<<setw(8)<<fixed<<setprecision(2)<<tTot<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
    system("pause");
}
///----------------------FUNCIONES GLOBALES-----------------

int buscarXCodProd(int codigo){
    FILE *p;
    DetalleVenta reg;
    int posicion=0;
    p=fopen(FILE_DETALLE, "rb");
    if(p == NULL){return -1;  }
    while( fread(&reg, sizeof(DetalleVenta), 1, p) == 1){
        if(reg.getCodProducto() == codigo){
            fclose(p);
            return posicion;
        }
        posicion++;
    }
    fclose(p);
    return -2;
}
int crearIdDetalle(){
    int bytes, cant;

    FILE *p = fopen(FILE_DETALLE, "rb");
    if (p == NULL){return 1;  }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant=bytes / sizeof(DetalleVenta);
    return cant+1;
}
