#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H


class DetalleFactura{

    public:
        int id, nroFactura, codProd, cantidad, codEnt, planCta;
        float precioCosto, ivaTotalProd, subTotalProd, TotalProd;
        char tipoEnt[2];
        bool estado;
        void CDetalleFactura(int,int,int,int,int,float,float,float,float,char);
        bool guardarEnDisco(int posicion);
        bool leerDeDisco(int posicion);
};

///------------------------------------- GLOBAL

void listado_facturas();
void mostrarDetalle();


#endif // DETALLEFACTURA_H
