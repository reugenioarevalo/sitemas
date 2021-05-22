
#include <iostream>
using namespace std;

#include "calculadora.h"

    float calculadora::setTotlaImponible(int cantidad=1,  float _precioUnitario=0){
        if(_precioUnitario>0){
            return imponible=_precioUnitario*cantidad;
        }else{
            return 0;
        }
    }
    float calculadora::setDescuento(int _descuento){
        if(_descuento>0){
            return descuento= (imponible*_descuento)/100;
        }
        return 0;
    }
   float calculadora::getDescuentoAplicado(){
        return this->imponible=imponible- descuento;
    }
    float calculadora::setImpuesto(float _impuesto=0){
        if(_impuesto>0){
            return  impuesto = (imponible*_impuesto)/100;
        }
        return 0;
    }
    float calculadora::getImponible(){
        return imponible;
    }
    float calculadora::getImpuestoAplicado(){
        return impuesto+imponible;
    }
