#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "DetalleFactura.h"
#include "Entidad.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
using namespace rlutil;

const char * FILE_DETFAC = "Archivos/DetalleFacturas.dat";
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
   char _tipoEnt ){
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
        fseek(p, posicion * sizeof(DetalleFactura), 0);
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

void mostrarDetalle(){
//    system("color 1E");
    system("color 4F");
    float  sTot, sIva, tTot, tPrUn;
    DetalleFactura aux,fac;
    fac.leerDeDisco(0);
    Entidad cli;
    cli.leerDeDisco(aux.codEnt, 1);
//    cli.leerDeDisco();
    char a='d'+42;
    int i = 0;
    //setBackgroundColor(RED);
        cout<<endl;
        cout<<"|"<<setw(89)<<setfill('¯')<<"|"<<endl;
        cout<<"|"<<setw(88)<<centrar("FACTURA", 88)<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;        cout<<"|"<<setw(69)<<""<<"Nro Fac: 0000-00"<<fac.nroFactura<<"|"<<endl;
        //cout<<cli.getApenom()<<endl;
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
        cout<<right;
        cout<<"|"<< "TONGA GESTION SRL   "<<setw(31)<<""<<"R.SOCIAL :"<<setw(27)<<"LARA COLA SRL"<<"|"<<endl;
        cout<<"|"<< "info@tongagest.com  "<<setw(31)<<""<<"MAIL     :"<<setw(27)<<"info@briancola.com"<<"|"<<endl;
        cout<<"|"<< "Dir: Yrigoyen 197   "<<setw(31)<<""<<"DIR      :"<<setw(27)<<"Games F"<<"|"<<endl;
        cout<<"|"<< "Cod Post : 1640     "<<setw(31)<<""<<"TEL      :"<<setw(27)<<"458-4584"<<"|"<<endl;
        cout<<"|"<< "Cuit: 30-12345678-0 "<<setw(31)<<""<<"CUIT     :"<<setw(27)<<"44-44444444-4"<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;

        cout<<"|"<<setw(9)<<centrar("CODPROD", 9);
        cout<<"|"<<setw(28)<<centrar("DESCRIPCION", 28);
        cout<<"|"<<setw(10)<<centrar("CANTIDAD", 10);
        cout<<"|"<<setw(10)<<centrar("PRECIO", 10);
        cout<<"|"<<setw(7)<<centrar("IVA", 7);
        cout<<"|"<<setw(9)<<centrar("SUB_TOT", 9);
        cout<<"|"<<setw(9)<<centrar("TOTAL", 9)<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
        while (aux.leerDeDisco(i++)){
        cout<<"|"<< setw(9)<<centrarInt(aux.codProd, 9);
        cout<<"|"<< setw(28)<<centrar("descripcion del prod", 28);
        cout<<"|"<< setw(10)<<centrarInt(aux.cantidad, 10);
        cout<<"|"<< setw(10)<<centrarfloat(aux.precioCosto,10);
        cout<<"|"<<setw(7)<<centrarfloat(aux.ivaTotalProd,7);
        cout<<"|"<<setw(9)<<centrarfloat(aux.subTotalProd,9);
        cout<<"|"<<setw(9 )<<centrarfloat(aux.TotalProd, 9)<<"|"<<endl;
        //cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;

        tPrUn+=aux.precioCosto;
        sIva+=aux.ivaTotalProd;
        sTot+=aux.subTotalProd;
        tTot+=aux.TotalProd;
        }
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
        cout<< right;
        cout<<"|"<<setw(80)<<"SubTotal:$"<<setw(8)<<derechafloat(sTot,8)<<"|"<<endl;
        cout<<"|"<<setw(80)<<"Total Iva:$"<<setw(8)<<derechafloat(sIva,8)<<"|"<<endl;
        cout<<"|"<<setw(80)<<"Total Final:$"<<setw(8)<<derechafloat(tTot,8)<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('¯')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('$')<<"|"<<endl;
        cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;

}
