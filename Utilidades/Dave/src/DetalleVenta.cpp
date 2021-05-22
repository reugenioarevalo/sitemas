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
using namespace rlutil;

const char *FILE_DETALLE="Archivos/DetalleVentas.dat" ;

void DetalleVenta::cDetalleVenta(){
 setlocale(LC_CTYPE, "Spanish");
    dato = new Ventas;
    int i= crearIdXFact()-2;
    dato->leerDeDisco(i);
    int continuar;
    do{
        this->idDetalle= crearIdDetalle();
        tipoFactura= dato->getTipoFact();
        nroFactura= dato->getNroFact();
        setCodProducto();
        setPrecio();
        Estado=true;
        grabarDetalleEnDisco();

        system("cls");
        cout<<"\nContinua comprando?. ";
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;

        cin>> continuar;
    }while(continuar==1);
    delete dato;
    return;
}
void DetalleVenta::setCodProducto(){
    cout<<"Ingrese codigo producto : ";
    cin>>codProd;
    prod.buscarProdxId(codProd);
    cout<<"Precio: $"<< prod.getPrecioCosto()<<endl;
//    cout<< prod.getIva();
    setCantProducto();
    prod.setMod(codProd, 1, cantidad,  prod.getPrecioCosto());
}
void DetalleVenta::setCantProducto(){
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
   // cout<<" "<<setw(89)<<setfill('_')<<"|"<<endl;
    cout<<" "<<setw(15)<<centrar("Id", 15)<<"|";
    cout<<" "<<setw(15)<<centrar("# Fact", 15)<<"|";
    cout<<" "<<setw(38)<<centrar("Tipo de Factura", 38)<<"|"<<endl;
    setBackgroundColor(BLACK);

    //cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
    //cout<<" "<<setw(89)<<setfill(' ')<<" "<<endl;

    while (aux.leerDeDiscoD(i++)){
    cout<<" "<<setw(15)<<centrarInt(aux.idDetalle, 15);
    cout<<" "<<setw(15)<<centrarInt(aux.getNroFactura(), 15);
    cout<<" "<<setw(21)<<aux.getTipoFactura()<<endl;
    //        cout<<"|"<<setw(89)<<setfill(sing)<<"|"<<endl;
    }
    cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
    system("pause");
}
void DetalleVenta::mostrarDetalleVenta(int posicion){
//    cout<<"Fecha : "<<codProd<<endl;
//    cout<<"Tipo de factura hola : " <<dato->getTipoFact()<<endl;
//    cout<<"Numero de factura" <<dato->getNroFact()<<endl;
}
bool DetalleVenta::ModificarVta(){
    FILE *p;
    int posicion, cod;
    bool chequeo;

    cout<<"Ingrese el id de producto : " ;
    cin>>cod;
    posicion= buscarXCodProd(cod);

    if(posicion >= 0)
    {
        p=fopen(FILE_DETALLE,"wb" );
        if(p == NULL)
        {
            return false;
        }
        fseek(p, posicion*sizeof(DetalleVenta), SEEK_SET);
        fread(this, sizeof(DetalleVenta),1,p);
        Estado == false;

        fseek(p, posicion*sizeof(DetalleVenta), SEEK_SET);
        chequeo= fwrite(this, sizeof(DetalleVenta),1,p);
        if(chequeo==true)
        {
            cout<<"Se modifico exitosamente "<<endl;
            fclose(p);
            return true;
        }
        fclose(p);

        cout<<"No se puso modificar el archivo "<<endl;
        return false;
    }
    else
    {
        if(posicion == -2)
        {
            cout<<"No se encontro el producto "<<endl;
            return false;
        }
    }
}
void DetalleVenta::setTipoFactura(){

//    this->tipoFactura= dato->getTipoFact;
//    strcpy(this->tipoFactura, dato->getTipoFact);
}
char DetalleVenta::getTipoFactura(){
    return tipoFactura;}
void DetalleVenta::setIdCliente(){
    this->idCliente=dato->getIdCliente();}
char DetalleVenta::getIdCliente(){
    return idCliente;}
void DetalleVenta::setNroFactura(){
    this->nroFactura=dato->getNroFact();}
void DetalleVenta::setIdDetalle(){
    this->idDetalle=crearIdDetalle();}
int DetalleVenta::getNroFactura(){

    return nroFactura;}
///----------------------FUNCIONES GLOBALES-----------------

int buscarXCodProd(int codigo){
    FILE *p;
    DetalleVenta reg;
    int posicion=0;

    p=fopen(FILE_DETALLE, "rb");
    if(p == NULL)
    {
        return -1;
    }
    while( fread(&reg, sizeof(DetalleVenta), 1, p) == 1)
    {
        if(reg.getCodProducto() == codigo)
        {
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
    if (p == NULL){
        return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant=bytes / sizeof(DetalleVenta);
    return cant+1;
}
void DetalleVenta::imprimirFactura(){
    system("color 0F");
    int pos= crearIdXFact()-2;
    float  sTot=0, sIva=0, tTot=0, tPrUn=0;
    DetalleVenta aux;
    Ventas  cli;

    int i =0,  f;

    cls();
    cout<<"\nIngrese el numero de factura que desea imprimir: ";
    cin>>f;
    cls();
    cli.leerDeDisco(f-1);
    char a[30];

    strcpy(a, "FACTURA ");

    if(cli.getNroFact()==f){

               setBackgroundColor(RED);
                cout<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
                cout<<"|"<<setw(88)<<centrar(a, 87)<<"|"<<endl;

                cout<<"|"<<setw(88)<<cli.getTipoFact()<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;                cout<<"|"<<setw(69)<<""<<"Nro Fac: 0001-"<<derechaInt(f, 5)<<"|"<<endl;
                //cout<<cli.getApenom()<<endl;
                cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
                cout<<right;
                cout<<"|"<< "TONGA GESTION SRL   "<<setw(31)<<""; if(cli.getTipoFact()=='A'){cout<<"R.SOCIAL :"<<setw(27)<<cli.cliente.getRazonSocial()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
                cout<<"|"<< "info@tongagest.com  "<<setw(31)<<"";if(cli.getTipoFact()=='A'){cout<<"MAIL     :"<<setw(27)<<cli.cliente.getMail()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
    //            cout<<"|"<< "Dir: Yrigoyen 197   "<<setw(31)<<""<<"DIR      :"<<setw(27);cli.cliente.domicilio.mostrarDireccion();cout<<"|"<<endl;
    //            cout<<"|"<< "Dir: Yrigoyen 197   "<<setw(31)<<""<<"DIR      :";
    //            cli.cliente.domicilio.mostrarDireccion(); cout<<setw(28)<<"|"<<endl;
                cout<<"|"<< "Cod Post : 1640     "<<setw(31)<<"";if(cli.getTipoFact()=='A'){cout<<"CUIT      :"<<setw(26)<<cli.cliente.getCuit()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
                cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
                cout<<"|"<<setw(9)<<centrar("CODPROD", 9);
                cout<<"|"<<setw(28)<<centrar("DESCRIPCION", 28);
                cout<<"|"<<setw(10)<<centrar("CANTIDAD", 10);
                cout<<"|"<<setw(10)<<centrar("PRECIO", 10);
                cout<<"|"<<setw(10)<<centrar("IVA", 10);
                cout<<"|"<<setw(16)<<centrar("SUB TOT", 16)<<"|"<<endl;
    //            cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;

    // }
            while (aux.leerDeDiscoD(i++)){
            if(aux.getNroFactura()==f){
                Producto *prod1;
                prod1 = new Producto;
                 prod1->leerDeDisco(prod1->buscarProdxId(aux.getCodProducto()));
                    cout<<setfill(' ');
                    cout<<"|"<< setw(9)<<centrarInt(aux.getCodProducto(), 9);
                    cout<<left;
                    cout<<"|"<< setw(28)<<aux.prod.getDescripcion();
                    cout<<right;
                    cout<<"|"<< setw(10)<<centrarInt(aux.getCantProducto(), 10);
                    cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<aux.getPrecio();
                     cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<(aux.getPrecio()*prod1->getIva()/100);
                     cout<<"|"<<setw(16)<<fixed<<setprecision(2)<<((aux.getPrecio()+(aux.getPrecio()*prod1->getIva()/100))*aux.getCantProducto())<<"|"<<endl;

                    tPrUn+=aux.getPrecio();
                    sTot+=(aux.getPrecio()*aux.getCantProducto());
                    sIva+=((aux.getPrecio()*prod1->getIva()/100)*aux.getCantProducto());
                delete prod1;
            }
            }
                    tTot+=(sIva+sTot);
                cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
    //            cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
                cout<< right;
               cout<<"|"<<setw(80)<<"SubTotal:$"<<setw(8)<<fixed<<setprecision(2)<<sTot<<"|"<<endl;
                cout<<"|"<<setw(80)<<"Total Iva:$"<<setw(8)<<fixed<<setprecision(2)<<sIva<<"|"<<endl;
                cout<<"|"<<setw(80)<<"Total Final:$"<<setw(8)<<fixed<<setprecision(2)<<tTot<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
    //            cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
    //            cout<<"|"<<setw(89)<<setfill('$')<<"|"<<endl;
                cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
    system("pause");
    }else{
        cout<<"\nNumero de Factura incorrecto!!!! poné bien los deditos!!! ";
        anykey();

    }
}
