#ifndef VENTAS_H
#define VENTAS_H
#define FILE_VENTAS "Archivos/Ventas.dat"
#include "Fecha.h"
#include "DetalleFactura.h"
//#include "DetalleVenta.h"
#include "Calculadora.h"
#include "Producto.h"
#include "Entidad.h"

///-----------------------CLASE VENTAS

class Ventas
{

public:
    int  idCliente;
    char tipoFactura;
    int  nroFactura;
    Fecha fechaVenta;
public:
    Ventas();
    void cargarVtas();
    void setTipoFact();
    void setIdCliente();
    void setNroFact();
    int getIdCliente(){return idCliente;}
    char getTipoFact(){  return tipoFactura; }
    int getNroFact(){ return nroFactura;}
    bool grabarEnDisco();
    bool leerDeDisco(int);
    void listado_facturas();
};

///-----------------------PROTOTIPOS GLOBALES

    int crearIdXFact();
    void listarVentas();

#endif // VENTAS_H

