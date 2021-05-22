
#include <iostream>
using namespace std;

#include "Fecha.h"
#include "Entidad.h"
#include "Producto.h"
#include "Compra.h"
#include "DetalleCompra.h"
//  DetalleCompra::DetalleCompra(int _idProveedor=0, int _idProducto=0, bool _cierra=false ){
//       idProveedor=_idProveedor;
//       idProducto=_idProducto;
//       cierra = _cierra;
//    }

void DetalleCompra::setProveedor(){this->proveedor.buscarRazonSocial(2);}
void DetalleCompra::setIdProveedor(){int idPrv= proveedor.getIdEntidad();}
Entidad DetalleCompra::getProveedor(){return this->proveedor;}


void DetalleCompra::setProducto(){
    int idp=0;
    cout<<"ingrese el id";
    cin>>idp;
    this->producto.buscarProdxId(idp);
    producto.getProducto();
    producto.getDescripcion();
}
//void DetalleCompra::setIdProducto(){ this->idProducto= producto.getId();}
//Producto DetalleCompra::getProducto(){return this->producto;}
