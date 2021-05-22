#ifndef CALCULADORA_H
#define CALCULADORA_H


class calculadora
{
    private:
        float subTotalProducto;
        float imponible;
        float impuesto;
        float descuento;
        float impuestoAplicado;
        float descuentoAplicado;
        float total;

    public:
        float setTotlaImponible(int, float);//Cantidad * precio unitario de cada producto
        float setDescuento(int);// Se establece en True para Descuentos otorgados
        float getDescuentoAplicado();
        float setImpuesto(float);//Se establece en true para IVA y Recargos
        float getImponible();//obtiene el valor Bruto del total de un producto
        float getImpuestoAplicado();//Obtiene el total con el impuesto aplicado por producto
//        float setPorcentaje(float);// Porcentaje a calcular, para e IVA debe obtenerlo del campo iva del producto en otros caso es manual
//        float getPorcentaje();//Obtiene el porcentaje en tiempo de ejecucion

};

#endif // CALCULADORA_H
