#ifndef COMPRAS_H
#define COMPRAS_H
///Cambiar a camell case?????

class Compras{

    protected:
    char tipofactura; ///Facturas de dos tipos (A: empresa)
    int puntoVta;       ///Representa el numero de venta de la sucursal del proveedor( mayor a 0)
    int nrofactura;  ///Numero de factura autonumerico (-00000000)
     int IDproducto;
     int cantidad;  /// Cantidad del producto
     float precio;  /// Precio unitario del producto
     float impuesto;  /// Valor del Impuesto aplicado
     float total; /// Total a pagar, calculado con el impuesto, el precio y la cantidad
     ///Producto  mercad;

    public:
    void cargarCompras();  /// Carga los datos de las ventas
    void MostrarCompras(); /// Muestra los datos de las ventas
    void setTipoFact(); /// Asigna el tipo de factura
    void setnrofactura(); /// Asigna el numero de factura autonumerico
	void setProducto(); /// Asigna el Id de producto ingresado
    void setpuntoVta();
    void setPrecio(); ///Asigna el Precio Unitario del producto
    void setCantProd(); ///Asigna la cantidad de producto en stock
    void setImpuesto(); ///Asigna el impuesto
    char getTipoFact();  /// Muestra el tipo de factura
    int getNroFactura();  /// Muestra el numero de la factura
    int getProducto(); /// Muestra el numero de  id del producto
    int getpuntoVta();
    int getcantProd(); ///Muestra la cantidad de producto corroborado en setCantProd
    float getPrecio();  ///Muestra el precio unitario del producto
    float getImpuesto(); ///Muestra el Impuesto aplicado
    bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**
};

#endif // COMPRAS_H
