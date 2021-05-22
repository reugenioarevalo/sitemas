#ifndef VENTAS_H
#define VENTAS_H

class Ventas{

    protected:
    char tipofactura; ///Facturas de dos tipos (A: empresa, B: consumidor final)
    int Nrofactura;  ///Numero de factura autonumerico (0000-00000000)
    int IDproducto;
    int cantidad;  /// Cantidad del producto
    int modoPago; /// Condicion de pago (1: efectivo, 2: tarjeta de credito, 3: transferencia)
    float Bonificacion; ///teniendo en cuenta el modo de pago (1: 10 % descuento, 2: 15% de recargo, 3: sin bonificacion)
    float precio;  /// Precio unitario del producto
    float impuesto;  /// Impuesto aplicado al 21 %,  iva = 21%
    float total; /// Total a pagar, calculado con el impuesto, el precio y la cantidad
    float preciofinal;
    ///Producto  mercad;

    public:
//    Ventas();
    void CargarVtas();  /// Carga los datos de las ventas
    void MostrarVtas(); /// Muestra los datos de las ventas
    void setTipoFact(); /// Asigna el tipo de factura
    void setNrofactura(); /// Asigna el numero de factura autonumerico
    void setModoPago(); ///Asigna el modo de pago
    void setBonificacion();  /// Asigna la bonificacion que requiera de acuerdo al modo de pago
    void setProducto(); /// Asigna el Id de producto ingresado
    void setPrecio(); ///Asigna el Precio Unitario del producto
    void setCantProd(); ///Asigna la cantidad de producto en stock
    void setImpuesto(); ///Asigna el impuesto
    void setprecioFinal();  /// Calcula el precio aplicando la bonificacion
    char getTipoFact();  /// Muestra el tipo de factura
    int getNroFactura();  /// Muestra el numero de la factura
    int getModoPago(); ///Muestra  el modo de pago
    float getBonificacion(); ///  Muestra la bonificacion aplicada
    float getPrecioFinal();  /// Muestra el precio con la bonificacion aplicada
    int getProducto(); /// Muestra el numero de  id del producto
    int getcantProd(); ///Muestra la cantidad de producto corroborado en setCantProd
    float getPrecio();  ///Muestra el precio unitario del producto
    float getImpuesto(); ///Muestra el Impuesto aplicado.
    bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**
};

///----------------------- PROTOTIPOS GLOBALES -----------------------


int crearId(char);

#endif // VENTAS_H

