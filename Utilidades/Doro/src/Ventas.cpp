#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include "Ventas.h"
#include "../include/Producto.h"


using namespace std;

const char * FILE_VENTAS = "Achivos/Ventas.dat";
const char * FILE_FACTURAA = "Archivos/FacturaA.dat";
const char * FILE_FACTURAB = "Archivos/FacturaB.dat";
//const char * FILE_PRODUCTOS = "Archivos/Productos.dat";

//Ventas::Ventas(){
//    Bonificacion=0;
//    preciofinal=0;
//}

void Ventas::CargarVtas(){
    setTipoFact();
    setNrofactura();
     setProducto();
    setCantProd();
    setPrecio();
    setImpuesto();
    setModoPago();
}

 void Ventas::MostrarVtas(){
     cout<<"Tipo de Factura : "<<tipofactura<<endl;
     cout<<"Numero: 0001-00"<<getNroFactura()<<endl;
    cout<<"Condiciones de pago : "<<modoPago<<endl;
     cout<<"Bonificacion : "<<getBonificacion()<<endl;
     cout<<"Precio Final a pagar : "<<getPrecioFinal()<<endl;

 }


 int  Ventas::getNroFactura(){
     return Nrofactura;
 }

 void Ventas::setTipoFact(){
      cout<<"Tipo de factura : ";
      cin>>tipofactura;
 }



 void Ventas::setNrofactura(){
    Nrofactura= crearId(tipofactura);
 }


 char Ventas::getTipoFact(){
      return tipofactura;
 }

 void Ventas::setModoPago(){
    cout<<"Condiciones de pago : ";
    cin>>modoPago;
 }

 void Ventas::setBonificacion(){      ///PROBAR CON SWITCH
    int opc=getModoPago();
    switch(opc) {
    case  1:
    Bonificacion=0.9;
        break;
    case 2:
     Bonificacion=1.15;
     break;
    case 3:
    Bonificacion=1;
    break;
    } }

    int Ventas::getModoPago(){
     return modoPago;
}

 float Ventas::getBonificacion(){
       return Bonificacion;
 }

 void Ventas::setprecioFinal(){
     precio=getPrecio();
     Bonificacion=getBonificacion();
        preciofinal= precio*Bonificacion;
 }

float Ventas::getPrecioFinal(){
    return preciofinal;
}

void Ventas::setProducto(){
     cout<<"Producto : ";
    cin>>IDproducto;
}

//void Ventas::setProducto(){
//    int posicion;
//    Producto  reg;
//    cout<<" ID Producto : ";
//    cin>>IDproducto;
//    posicion=merca.buscarProd(IDproducto);
//    reg=obtenerProducto(posicion);
//    setPrecio(reg.getprecio());
//    setImpuesto(reg.getIva());
//}

void Ventas::setPrecio(){
       cout<<"Precio : ";
    cin>>precio;
}


void Ventas::setCantProd(){
       cout<<"Cantidad : ";
    cin>>cantidad;
}

void Ventas::setImpuesto(){
    cout<<"Impuesto : ";
    cin>>impuesto;
}

//  float Ventas::getMonto(){
//  return total;
//  }

int Ventas::getProducto(){
    return IDproducto;
}


float Ventas::getPrecio(){
  return precio;
}



int Ventas::getcantProd(){
   return cantidad;
}


//bool Producto::grabarEnDisco(){
//
//        system("cls");
//        FILE *p;
//        bool chequeo;
//
//        p = fopen(FILE_PRODUCTOS,"ab");
//        if(p==NULL){
//            cout << "Error al abrir el archivo \n";
//            return false;
//        }
//        chequeo = fwrite(this, sizeof(Producto),1,p);
//        if(chequeo==1){
//
//            //msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
//            //cout << "Registro exitoso";
//            fclose(p);
//            //system("pause");
//            return true;
//        }
//        else{
//            //cout << "El registro no pudo guardarse \n\n";
//            fclose(p);
//            //system("pause");
//            return false;
//        }
//    }

    int crearId(char tipo='B'){
    int bytes, cant;

    if(tipo == 'A' || tipo == 'a')  {
    FILE *p = fopen(FILE_FACTURAA, "rb");
     if (p == NULL){
        return 13;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
      fseek(p, 0, SEEK_END);
            bytes = ftell(p);
            fclose(p);
    }else{
        FILE *p = fopen(FILE_FACTURAB, "rb");
         if (p == NULL){
            return 18;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
      fseek(p, 0, SEEK_END);
            bytes = ftell(p);
            fclose(p);
     }
    cant = bytes / sizeof(Ventas);
    return cant+1;
}
