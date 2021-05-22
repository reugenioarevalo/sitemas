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
#include "Contable.h"
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

void DetalleCompra::cDetalleCompra(){
    setlocale(LC_CTYPE, "Spanish");
    Compras  datoCp;
    Contable conta;
    int i= crearIdXCompras()-2;
    datoCp.leerDeDisco(i);//leer de Compras
    int continuar;
    do{
        setIdCompras(datoCp.getIdCompras());
        setIdDetalle();
        setTipoFactura(datoCp.getTipoFact());
        setPtoVta(datoCp.getPuntoVta());
        setNroFactura(datoCp.getNroFactura());
        setIdProducto();
        grabarDetalleEnDisco();
        conta.imputarCta(datoCp.fechaFactura.getDia(), datoCp.fechaFactura.getMes(), datoCp.fechaFactura.getAnio(), getNroFactura(), getcantProd(), 2, getIdProducto());
        system("cls");
        cout<<"\nContinua cargando?. ";
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;
        cin>> continuar;
         while(!(continuar == 0 || continuar == 1)){
        cout<<" Opcion incorrrecta : ";
        system("pause");
        system("cls");
         cout<<"\nCountinua cargando?. "<<endl;
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;
        cin>> continuar;
    }
    }while(continuar==1);
    ///DEBERIA MOSTRAR EL DETALLE DE LA COMPRA O LA ORDEN DE COMPRA
    imprimirOrdenCompra(getIdCompras());
    return;
}
void DetalleCompra::setIdProducto(){
    Producto prod;
    cout<<"Ingrese codigo producto : ";
    cin>>idProducto;
     while(idProducto < 1){
        cout<<"Codigo de producto incorrrecta : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese codigo producto : "<<endl;
        cin>> idProducto;
    }
    if (prod.buscarProdxId(idProducto) == -2){
        prod.cargarProducto();
        prod.mostrarProducto();
        idProducto=prod.getId();
        cantidad=prod.getStock();
        prod.setMod(idProducto, 2, cantidad,  prod.getPrecioCosto());
    }else{
        if(prod.buscarProdxId(idProducto)>0){
            cout<<"Precio: $"<< prod.getPrecioCosto()<<endl;
            prod.setPrecioCosto();
            setCantidad();
            prod.setMod(idProducto, 2, cantidad,  prod.getPrecioCosto());
        }else{
            return;
        }
    }
}
void DetalleCompra::setPrecio(){
    int precio;
    cout<<"Precio :"<<endl;
    cin>>precio;
    while(precio<1){
    cout<<"Valor ingresado no valido : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese precio : "<<endl;
        cin>> precio;
    }
    this->preBruto=precio;
}
void DetalleCompra::setCantidad(){
    int cant;
    cout<<"Ingrese la cantidad: "<<endl;
    cin>>cant;
     while(cant<1){
    cout<<"Valor ingresado no valido : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese cantidad : "<<endl;
        cin>> cant;
    }
    this->cantidad=cant;
}
void DetalleCompra::setImpuesto(){
    float imp;
    cout<<"Porcentaje de Iva"<<endl;
    cin>>imp;
    while(imp != 10.5 || imp != 21) {
    cout<<"Valor ingresado no valido : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese impuesto : "<<endl;
        cin>> imp;
    }
    this->impuesto=imp;
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
bool DetalleCompra::leerDeDisco(int posicion){
    bool leyo;
    FILE *p;
    p = fopen(FILE_DET_COMPRAS, "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, posicion * sizeof(DetalleCompra), 0);
    leyo = fread(this, sizeof(DetalleCompra), 1, p);
    fclose(p);
    return leyo;
}

void DetalleCompra::listado_detalle(){
    DetalleCompra aux;
    int i = 0;
    ///Inicio de cabecera
    title("DETALLE DE FACTURAS",WHITE, RED);
    cout<<endl;
    setBackgroundColor(DARKGREY);
    cout<<" "<<setw(15)<<centrar("Id", 15)<<"|";
    cout<<" "<<setw(15)<<centrar("# Fact", 15)<<"|";
    cout<<" "<<setw(38)<<centrar("Tipo de Factura", 38)<<"|"<<endl;
    setBackgroundColor(BLACK);

    while (aux.leerDeDisco(i++)){
    cout<<" "<<setw(15)<<centrarInt(aux.getIdDetalle(), 15);
    cout<<" "<<setw(15)<<centrarInt(aux.getNroFactura(), 15);
    cout<<" "<<setw(21)<<aux.getTipoFactura()<<endl;
     }
    cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
    system("pause");
}

//int posicionFact(int f){
//    Compras reg;
//    DetalleCompra aux;
//    int factura, contador=0, opcion;
//    bool b=false;
//    factura=f;
////   do{
//
//
//   FILE *p=fopen(FILE_COMPRAS,"rb");
//   if(p == NULL)return -1;
//
//   while(fread(p,sizeof(Compras), 1, p)){
//       if(aux.getNroFactura() == factura){
//            b=true;
//            fclose(p);
//            return contador;}
//    contador++;
//   }
//   cout<<contador;
//        cout<<"Numero de orden de compra";
//        fclose(p);
//        system("pause");
//        system("cls");
//        cout<<"\nIngresara un orden de compra?. ";
//        cout<<"\nSi: 1";
//        cout<<"\nNo : 0 "<<endl;
//        cin>> opcion;
//
////         while(!(opcion == 0 || opcion == 1)){
////            cout<<" Opcion incorrrecta : ";
////            system("pause");
////            system("cls");
////            cout<<"\n.Ingresara un orden de compra? "<<endl;
////            cout<<"\nSi: 1";
////            cout<<"\nNo : 0 "<<endl;
////            cin>> opcion;
////    }
////        if(opcion==1){
////            b=false;
////            aux.listado_detalle();
////            system("pause");
////            system("cls");
////             cout<<"Ingrese numero de factura : ";
////             cin>>factura;
////             while(factura < 0) {
////                cout<<"Numero de factura incorrecto ";
////                system("pause");
////                system("cls");
////                cout<<"\nIngrese el numero de factura que desea imprimir: ";
////                cin>>factura;}
////    }else{return -2;}
////    }while(b == false);
//    }

void DetalleCompra::imprimirOrdenCompra(int _n){
    float  sTot=0, sIva=0, tTot=0, tPrUn=0;
    Compras  dato;
    Entidad proveedor;
    Producto prod;
    int i =0, f, pos;
    cls();
    if(_n == 0){
        cout<<"INGRESE NUMERO DE ORDEN COMPRA : ";
        cin>>f;
        while(f < 0) {
             cout<<"Numero de factura incorrecto ";
             system("pause");
             system("cls");
             cout<<"\nIngrese el numero de factura que desea imprimir: ";
             cin>>f;}
//    pos=posicionFact(f);
    }else{
        f=_n ;
//    pos=posicionFact(f);
    }
    if(pos >= 0){
    cls();
    dato.leerDeDisco(f-1);
    proveedor.leerDeDisco(dato.getIdEntidad()-1,2);
    char a[30];
    strcpy(a, "ORDEN DE COMPRA ");
            cout<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(88)<<centrar(a, 87)<<"|"<<endl;
            cout<<"|"<<setw(88)<<dato.getTipoFact()<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(69)<<""<<derechaInt(dato.getPuntoVta(),4)<<"-"<<derechaInt(dato.getNroFactura(), 5)<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<< getTipoFactura()<<endl;
            cout<<"|"<< proveedor.getMail()<<endl;
            cout<<"|"<< proveedor.getDomicilio().getCalle()<<endl;
            cout<<"|"<< proveedor.getCuit()<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<right;
            cout<<"|"<<setw(9)<<centrar("CODPROD", 9);
            cout<<"|"<<setw(28)<<centrar("DESCRIPCION", 28);
            cout<<"|"<<setw(10)<<centrar("CANTIDAD", 10);
            cout<<"|"<<setw(10)<<centrar("PRECIO", 10);
            cout<<"|"<<setw(10)<<centrar("IVA", 10);
            cout<<"|"<<setw(16)<<centrar("SUB TOT", 16)<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
        while ( leerDeDisco(i++)){
        if(getIdCompras()==f){
             prod.leerDeDisco(prod.buscarProdxId(getIdProducto()));
                cout<<setfill(' ');
                cout<<"|"<< setw(9)<<centrarInt(getIdProducto(), 9);
                cout<<left;
                cout<<"|"<< setw(28)<<prod.getDescripcion();
                cout<<right;
                cout<<"|"<< setw(10)<<centrarInt(getcantProd(), 10);
                cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<prod.getPrecioCosto();
                cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<(prod.getPrecioCosto()*prod.getIva()/100);
                cout<<"|"<<setw(16)<<fixed<<setprecision(2)<<((prod.getPrecioCosto()+(prod.getPrecioCosto()*prod.getIva()/100))*getcantProd())<<"|"<<endl;
                tPrUn+=prod.getPrecioCosto();
                sTot+=(prod.getPrecioCosto()*getcantProd());
                sIva+=((prod.getPrecioCosto()*prod.getIva())/100*getcantProd());
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
}
