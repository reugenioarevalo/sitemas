#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <locale.h>
using namespace std;
#include "Producto.h"
#include "Productos.h"
#include "Entidad.h"
#include "Calculadora.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "../Utilidades/menus.h"
#include "Fecha.h"
#include "Entidad.h"
#include "Producto.h"
#include "DetalleCompra.h"
#include "Compras.h"
using namespace rlutil;

const char *FILE_DET_COMPRAS="Archivos/DetalleCompras.dat" ;

void DetalleCompra::cDetalleCompra(){
setlocale(LC_CTYPE, "Spanish");
Compras *datoCp;
    datoCp= new Compras;
    int i= crearIdXCompras()-2;
    datoCp->leerDeDisco(i);//leer de Compras
    int continuar;
    do{
        this->idDetalle= crearIdDetalle();
        this->tipoFactura= datoCp->getTipoFact();
        ptoVta= datoCp->getPuntoVta();
        nroFactura= datoCp->getNroFactura();
        setIdProducto();
        setPrecio();
//        Estado=true;
        grabarDetalleEnDisco();

        system("cls");
        cout<<"\nContinua cargando?. ";
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;

        cin>> continuar;
    }while(continuar==1);
//    delete dato;
    return;
}
void DetalleCompra::setIdProducto(){
    cout<<"Ingrese codigo producto : ";
    cin>>idProducto;
    prod.buscarProdxId(idProducto);
    cout<<"Precio: $"<< prod.getPrecioCosto()<<endl;
//    cout<< prod.getIva();
prod.setPrecioCosto();
    setCantidad();
    prod.setMod(idProducto, 2, cantidad,  prod.getPrecioCosto());
}
void DetalleCompra::setProveedor(){
    this->proveedor.buscarRazonSocial(2);}
void DetalleCompra::setIdProveedor(){
    int idPrv= proveedor.getIdEntidad();}
void DetalleCompra::setIdCuenta(){
    int a;
    cout<<"Cuenta Contable:"<<endl;
    cin>>a;
    this->idCuenta=a;
}
void DetalleCompra::setPrecio(){
    cout<<"Precio :"<<endl;
    cin>>this->preBruto;
}
void DetalleCompra::setCantidad(){
    cout<<"Ingrese la cantidad: "<<endl;
    cin>>this->cantidad;
}
void DetalleCompra::setImpuesto(){
    cout<<"Porcentaje de Iva"<<endl;
    cin>>this->impuesto;
}
int DetalleCompra::crearIdDetalle(){
    int bytes, cant;
    FILE *p = fopen(FILE_DET_COMPRAS, "rb");
    if (p == NULL){ return 1;}
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant=bytes / sizeof(DetalleCompra);
    return cant+1;
}
bool DetalleCompra::grabarDetalleEnDisco(){

    system("cls");
    FILE *p;
    bool chequeo;
    p = fopen(FILE_DET_COMPRAS,"ab");
    if(p==NULL) {
        cout << "Error al abrir el archivo \n";
        return false;
    }

    chequeo = fwrite(this, sizeof(DetalleCompra),1,p);
    if(chequeo==1)  {
        fclose(p);
        return true;
    }else {
        cout << "El registro no pudo guardarse \n\n";
        fclose(p);
        system("pause");
        return false;
    }
}
Entidad DetalleCompra::getProveedor(){
    return this->proveedor;}
