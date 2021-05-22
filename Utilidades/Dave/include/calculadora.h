#ifndef CALCULADORA_H
#define CALCULADORA_H


class calculadora{
    private:
        float extraeIva;
        float imponible;
        float impuesto;
        float descuento;
        float impuestoAplicado;
        float descuentoAplicado;
        float importeBruto;
        float imponibleFinal;
        int cta;

    public:
        void setExtraeIva(float _iva=0);///Establece el valor para obtener el cociente de un importe con IVA incluido
        void setImporteBruto(float _precioUnitario=0);///Establece el importe bruto sin iva a partir de un precio final
        void setImponible(int _cantidad=1);///Establece el precio imponible para la venta
        void setDescuento(float  _descuento=0);///Establece el descuento total de un producto pagado con descuento
        void setDescuentoAplicado();
//        void setRecargo(float _rec=0);///recargo
//        void setRecargoAplicado();///aplica el recargo
        void setImpuesto(float _impuesto=0);///Establece el importe del impuesto a un producto para la venta.
        void setImpuestoAplicado();
        float getExtraeIva(); ///Entrega el divisor para un importe bruto de una compra
        float getImporteBruto(); ///Devuelve el precio bruto de una compra
        float getImponible();///devuelte el importe imponible para una venta
        float getDescuento();///Devuelve el importe de descuento por pago en efectivo
        float getDescuentoAplicado();///devuelve el importe con descuento aplicado.
//        float getRecargo();///Devuelve el Recargo por pago con tarjetas
//        float getRecargoAplicado();///devuelve el importe con Recargo aplicado.
        float getImpuesto(); ///devuelve el impuesto para a aplicar
        float getImpuestoAplicado();///Devuelve el importe final con descuentos e impuestos aplicados
};

#endif // CALCULADORA_H
