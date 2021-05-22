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
    void cargarCompras();  /// Carga los datos de las ventas
    void setTipoFact(); /// Asigna el tipo de factura
    void setPuntoVta();
    void setIdCuenta(); /// Asigna el numero de factura autonumerico
    void setNroFactura(); /// Asigna el numero de factura autonumerico
    void setIdProveedor(); /// Asigna el Id del proveedor
    void setFechaFactura();
    bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**
    Fecha getFecha(){return this->fechaFactura;}
    int setIdCompras();
    int getIdCompras(){return this->idCompras;}
    int getPuntoVta(){return puntoVta;}
    int getNroFactura(){return nroFactura;}
    char getTipoFact(){return tipoFactura;}

    void setIdEntidad();
    int getIdEntidad();
    bool leerDeDisco(int posicion);
    void listado_compras();

};
int crearIdXCompras();
#endif // COMPRAS_H
