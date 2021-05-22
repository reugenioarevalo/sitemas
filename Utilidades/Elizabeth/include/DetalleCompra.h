#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H
#define FILE_DET_COMPRAS "Archivos/DetalleCompras.dat"
#include "Producto.h"
#include "Entidad.h"
#include "Compras.h"

class DetalleCompra{

private:
    char tipoFactura;
    int nroFactura, ptoVta;
    int idDetalle;
    int idProducto;
    int idCompras;
    int cantidad;
    int impuesto;
    float preBruto;
    float preTotal;

public:
///setters
    void setIdCompras(int d){this->idCompras=d;}
    void setIdDetalle(){ this->idDetalle= crearIdDetalle();}
    void setTipoFactura(char t){  this->tipoFactura= t;}
    void setPtoVta(int n){this->ptoVta=n;}
    void setNroFactura(int n){this->nroFactura=n;}
    void setPrecio();
    void setCantidad();
    void setImpuesto();
    void setIdProducto();

///gettes
    int getIdCompras(){return idCompras;}
    int getIdDetalle(){ return idDetalle;}
    char getTipoFactura(){ return tipoFactura;}
    int getPtoVta(){return ptoVta;}
    int getNroFactura(){return nroFactura;}
    int getIdProducto(){return idProducto;}
    float getPrecio(){return preBruto;}
    float getImpuesto(){return impuesto;}
    int getcantProd(){return cantidad;}

///Disco
    int crearIdDetalle();
    void cDetalleCompra();
    bool grabarDetalleEnDisco();
    bool leerDeDisco(int posicion);
    void listado_detalle();
    void imprimirOrdenCompra(int _n=0);
};

int posicionFact(int f);
#endif // DETALLECOMPRA_H

