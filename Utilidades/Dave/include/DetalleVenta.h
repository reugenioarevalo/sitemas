#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#include "Ventas.h"

class DetalleVenta{
    private:
    int nroFactura, codProd, cantidad, idDetalle, idCliente;
    float precio;
    char tipoFactura;
    Ventas *dato;
    calculadora calculo;
    bool Estado;
    public:
    Producto prod;

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
    void setPrecio(){this->precio=prod.getPrecioCosto();}
    int getIdDetalle(){return  idDetalle;}
    int getCodProducto(){return codProd;}
    int getCantProducto(){return cantidad;}
    float getPrecio(){return precio;}
    void mostrarDetalleVenta(int);
   bool  ModificarVta();
   bool grabarDetalleEnDisco();
   bool leerDeDiscoD(int );
   void listado_detalle();
void imprimirFactura();
};

///-----------------------------FUNCIONES GLOBALES------
int buscarXCodProd(int );
int crearIdDetalle();
#endif // DETALLEVENTA_H
