#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
#include "Utilidades/menus.h"
#include "Include/Persona.h"
#include "Utilidades/validaciones.h"
#include "Direccion.h"
#include "Include/Entidad.h"
#include "Include/Ventas.h"
#include "DetalleFactura.h"
#include "Include/Usuario.h"
#include "DetalleVenta.h"
#include "DetalleCompra.h"
#include "Include/Usuario.h"
#include "Contable.h"
#include <vector>

//bool venta_nueva();

int main(){
    DetalleCompra reg;
    reg.imprimirNotaCredito(1);

//    menuLogin();
//    venta_nueva();
    return 0;
}

//bool venta_nueva(){
//    Ventas dato;
//    vector <DetalleVenta> vecVenta;
//    DetalleVenta detalle;
//    int i= crearIdXFact()-2;
//    dato.leerDeDisco(i);
//    int continuar;
//    do{
//        detalle.setIdDetalle();
//        detalle.setTipoFactura(dato.getTipoFact());
//        detalle.setNroFactura(dato.getNroFact());
//        detalle.setCodProducto();
//        detalle.setPrecio();
//        if(vecVenta.size() == 0){
//        vecVenta.push_back(detalle);
//        }else{
//       for(int i=0; i<vecVenta.size();i++){
//    if(vecVenta[i].getCodProducto() == detalle.getCodProducto()){
//            int aux=vecVenta[i].getCantProducto()+detalle.getCantProducto();
//        vecVenta[i].setCantProducto(aux);
//    }else{
//        vecVenta.push_back(detalle);
//    } } }
//        cout<<"PASE POR ACA";
//        cout<<vecVenta.size();
//        system("PAUSE");
//        system("cls");
//        cout<<"\nCountinua comprando?. "<<endl;
//        cout<<"\nSi: 1";
//        cout<<"\nNo : 0 "<<endl;
//    cin>> continuar;
//    while(!(continuar == 0 || continuar == 1)){
//        cout<<" Opcion incorrrecta : ";
//        system("pause");
//        system("cls");
//         cout<<"\nCountinua comprando?. "<<endl;
//        cout<<"\nSi: 1";
//        cout<<"\nNo : 0 "<<endl;
//        cin>> continuar;
//    }
////    grabarDetalleEnDisco();
////    ctb.imputarCta(getNroFactura(), getCantProducto(), 1, getCodProducto());
//    }while(continuar==1);
//   for(int i=0; i<vecVenta.size(); i++){
//    cout<<"F"<<vecVenta[i].getTipoFactura()<<endl;
//   cout<<"N"<<vecVenta[i].getNroFactura()<<endl;
//     cout<<"P"<<vecVenta[i].getCodProducto()<<endl;
//    cout<<vecVenta[i].getCantProducto()<<endl;
//    cout<<vecVenta[i].getPrecio()<<endl;
//   }
//
//}
