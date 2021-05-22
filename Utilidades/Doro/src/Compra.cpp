#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include "../include/Compra.h"
#include "../include/Producto.h"

using namespace std;

const char * FILE_COMPRAS = "Achivos/Compras.dat";

void Compras::cargarCompras(){

    setTipoFact();
    setpuntoVta();
    setnrofactura();
    setProducto();
    setCantProd();
    setPrecio();
    setImpuesto();

}

 void Compras::MostrarCompras(){
     cout<<"Tipo de Factura : "<<tipofactura<<endl;
     cout<<"Numero:  "<<getNroFactura()<<endl;
     cout<<"Numero:  "<<getpuntoVta()<<endl;
 }

 void Compras::setnrofactura(){
    cout<<"Numero de  Factura : ";
    cin>>nrofactura;
 }

 int  Compras::getNroFactura(){
     return nrofactura;
 }

 void Compras::setTipoFact(){
      cout<<"Tipo de factura : ";
      cin>>tipofactura;
 }

char Compras::getTipoFact(){
    return tipofactura;
}

void Compras::setProducto(){
     cout<<"\nProducto : ";
    cin>>IDproducto;
}

//void Compras::setProducto(){
//    int posicion;
//    Producto  reg;
//    cout<<" ID Producto : ";
//    cin>>IDproducto;
//    posicion=merca.buscarProd(IDproducto);
//    reg=obtenerProducto(posicion);
//    setPrecio(reg.getprecio());
//    setImpuesto(reg.getIva());
//}

void Compras::setPrecio(){
       cout<<"Precio : ";
    cin>>precio;
}


void Compras::setCantProd(){
       cout<<"Cantidad : ";
    cin>>cantidad;
}

void Compras::setImpuesto(){
    cout<<"Impuesto : ";
    cin>>impuesto;
}

void Compras::setpuntoVta(){
      cout<<"Punto de venta: ";
      cin>>puntoVta;
}

//  float Compras::getMonto(){
//  return total;
//  }

int Compras::getProducto(){
    return IDproducto;
}

float Compras::getPrecio(){
  return precio;
}

int Compras::getcantProd(){
   return cantidad;
}

int Compras::getpuntoVta(){
   return puntoVta;
}

bool Compras::grabarEnDisco(){

    system("cls");
    FILE *p;
    bool chequeo;

        p = fopen(FILE_COMPRAS,"ab");
        if(p==NULL){
            cout << "Error al abrir el archivo clientes\n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Compras),1,p);
        if(chequeo==1){

            //msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            cout << "Registro exitoso";
            fclose(p);
            system("pause");
            // cls();
            return true;
        }
        else{
            cout << "El registro no pudo guardarse en compras\n\n";
            fclose(p);
            system("pause");
            return false;
        }
}
