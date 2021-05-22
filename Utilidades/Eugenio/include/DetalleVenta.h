#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#define FILE_DETALLE "Archivos/DetalleVentas.dat"
#include "Ventas.h"

class DetalleVenta{
    private:
    int nroFactura, codProd, cantidad, idDetalle, idCliente, nroCta;
    float precio;
    char tipoFactura;

    public:
    void cDetalleVenta();
    void setTipoFactura();
    char getTipoFactura();
    void setIdCliente();
    char getIdCliente();

    void setNroFactura();
    int getNroFactura();

    void setCodProducto();
    void setCantProducto();
    void setIdDetalle();
    void setPrecio(){Producto prod; this->precio=prod.getPrecioCosto();}
    int getIdDetalle(){return  idDetalle;}
    int getCodProducto(){return codProd;}
    int getCantProducto(){return cantidad;}
    float getPrecio(){return precio;}
    void mostrarDetalleVenta(int);
   bool grabarDetalleEnDisco();
   bool leerDeDiscoD(int );
   void listado_detalle();
void imprimirFactura(int _n=0);
};

///-----------------------------FUNCIONES GLOBALES------
int buscarXCodProd(int );
int crearIdDetalle();
#endif // DETALLEVENTA_H
