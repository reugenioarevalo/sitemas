#ifndef COMPRAS_H
#define COMPRAS_H
#include "Fecha.h"
#include "DetalleCompra.h"
#include "Calculadora.h"
#include "Producto.h"
#include "Entidad.h"

class Compras
{

private:
    int idCompras;///Debe ser autoincremental
  char tipoFactura; ///Facturas de dos tipos (A: RI, C: monotributistas)
    int puntoVta;       ///Representa el numero de venta de la sucursal del proveedor( mayor a 0)
    int nroFactura;  ///Numero de factura autonumerico (-00000000)
    int idEntidad;
    bool cierra;
    Fecha fechaFactura;
    Entidad proveedor;
//        Producto producto;
public:
    Compras();
    void cargarCompras();  /// Carga los datos de las ventas
//        void mostrarDetalleCompras(); /// Muestra los datos de las ventas
    void setTipoFact(); /// Asigna el tipo de factura
    void setPuntoVta();
    void setIdCuenta(); /// Asigna el numero de factura autonumerico
    void setNroFactura(); /// Asigna el numero de factura autonumerico
    void setIdProveedor(); /// Asigna el Id del proveedor
    void setFechaFactura();
    char getTipoFact();  /// Muestra el tipo de factura
    int getNroFactura();  /// Muestra el numero de la factura
    int getPuntoVta();
    bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**

    int setIdCompras();
    int getIdCompras();

    void setIdEntidad();
    int getIdEntidad();
    bool leerDeDisco(int posicion);
    void listado_compras();
//        int setIdProducto();
//        int getIdProducto();

};
int crearIdXCompras();
#endif // COMPRAS_H
