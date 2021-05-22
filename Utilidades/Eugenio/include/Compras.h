#ifndef COMPRAS_H
#define COMPRAS_H
#define FILE_COMPRAS "Archivos/Compras.dat"
#include "Fecha.h"
#include "DetalleCompra.h"
#include "Calculadora.h"
#include "Producto.h"
#include "Entidad.h"

class Compras{

private:
    int idCompras;///Debe ser autoincremental
  char tipoFactura; ///Facturas de dos tipos (A: RI, C: monotributistas)
    int puntoVta;       ///Representa el numero de venta de la sucursal del proveedor( mayor a 0)
    int nroFactura;  ///Numero de factura autonumerico (-00000000)
    int idEntidad;

public:
    Fecha fechaFactura;
    //Compras();
    void cargarCompras();
    void setTipoFact();
    void setPuntoVta();
    void setNroFactura();
    void setIdCuenta();
    void setIdProveedor();

    char getTipoFact(){return tipoFactura;}
    int getNroFactura(){return nroFactura;}
    int getPuntoVta(){return puntoVta;}
    int getIdCuenta(){return idCompras;}
    int getIdProveedor(){return idEntidad;}

    bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**

    int setIdCompras();
    int getIdCompras(){return idCompras;}

    void setIdEntidad();
    int getIdEntidad();
    bool leerDeDisco(int posicion);
    void listado_compras();

};
int crearIdXCompras();
#endif // COMPRAS_H
