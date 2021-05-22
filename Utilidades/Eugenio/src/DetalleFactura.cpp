#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "DetalleFactura.h"
#include "Ventas.h"
#include "Entidad.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"

using namespace rlutil;

const char * FILE_DETFAC = "Archivos/DetalleVentas.dat";

void DetalleFactura::CDetalleFactura(
   int _nroFactura,
   int _codProd,
   int _cantidad,
   int _codEnt,
   int _planCta,
   float _precioCosto,
   float _ivaTotalProd,
   float _subTotalProd,
   float _TotalProd,
   char _tipoEnt){
    nroFactura    =    _nroFactura;
    codProd         =         _codProd;
    cantidad        =        _cantidad;
    codEnt           =           _codEnt;
    planCta          =         _planCta;
    precioCosto   =   _precioCosto;
    ivaTotalProd  = _ivaTotalProd;
    subTotalProd =_subTotalProd;
    TotalProd       =      _TotalProd;
    estado            =                false;
//    strcpy(tipoEnt, _tipoEnt) ;
}
bool DetalleFactura::guardarEnDisco(int posicion){
        bool grabo;
        FILE *p;

            p = fopen(FILE_DETFAC, "ab");
            if (p == NULL){
                return false;
            }

        grabo = fwrite(this, sizeof(DetalleFactura), 1, p);
        fclose(p);
        return grabo;
    }
    bool DetalleFactura::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_DETFAC, "rb");
        if (p == NULL){

            return false;
        }
//          fseek(p, 0, SEEK_END);
        fseek(p, (posicion-1) * sizeof(DetalleFactura), SEEK_END);
        leyo = fread(this, sizeof(DetalleFactura), 1, p);
        fclose(p);
        return leyo;
    }

void listado_facturas(){
        DetalleFactura aux;
        int i = 0;

        char sing = getch();
        //selecciona un caracter para darle forma a tu tabla
        //string dato="esta tabla";
        ///Inicio de cabecera
        cout<<"|"<<setw(88)<<centrar("DETALLE DE FACTURA", 88)<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(4)<<centrar("ID", 4);
        cout<<"|"<<setw(9)<<centrar("CodProd", 9);
        cout<<"|"<<setw(22)<<centrar("Descripcion", 22);
        cout<<"|"<<setw(9)<<centrar("PlanCta", 9);
        cout<<"|"<<setw(7)<<centrar("Cant", 7);
        cout<<"|"<<setw(10)<<centrar("Precio", 10);
        cout<<"|"<<setw(10)<<centrar("IVA", 10);
        cout<<"|"<<setw(10)<<centrar("Stock Min", 10)<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;

    while (aux.leerDeDisco(i++)){
        cout<<"|"<<setw(4)<<centrarInt(aux.nroFactura, 4);
        cout<<"|"<<setw(9)<<centrarInt(aux.codProd, 9);
        cout<<"|"<<setw(22)<<centrar("Descripcion del pro", 22);
        cout<<"|"<<setw(9)<<centrarInt(aux.planCta, 9);
        cout<<"|"<<setw(7)<<centrarInt(aux.cantidad, 7);
        cout<<"|"<<setw(10)<<centrarfloat(aux.precioCosto, 10);
        cout<<"|"<<setw(10)<<centrarfloat(aux.ivaTotalProd, 10);
        cout<<"|"<<setw(10)<<centrarInt(aux.TotalProd, 10)<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(sing)<<"|"<<endl;
        }
        }


