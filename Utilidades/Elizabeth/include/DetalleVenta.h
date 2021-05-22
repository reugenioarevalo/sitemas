#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#define FILE_DETALLE "Archivos/DetalleVentas.dat"
#include "Ventas.h"
///-----------------------------FUNCIONES GLOBALES------
int buscarXCodProd(int );
int crearIdDetalle();

class DetalleVenta{
    private:
    int nroFactura, codProd, cantidad, idDetalle, idCliente, nroCta;
    float precio;
    char tipoFactura;

    public:
    void cDetalleVenta();
    void setTipoFactura(const char n){this->tipoFactura=n;}
    void setNroFactura(int num){this->nroFactura=num;}
    void setIdCliente();
    void setIdDetalle(){this->idDetalle=crearIdDetalle();}
    void setCodProducto();
    void setCantProducto();
    void setCantProducto(int n){this->cantidad=n;}
    void setPrecio(){Producto prod; this->precio=prod.getPrecioCosto();}

    char getTipoFactura(){return tipoFactura;}
    int getIdCliente(){return idCliente;}
    int getNroFactura(){return nroFactura;}
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

#endif // DETALLEVENTA_H
