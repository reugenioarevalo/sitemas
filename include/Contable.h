#ifndef CONTABLE_H
#define CONTABLE_H
#define FILE_MOVIMIENTOS "Archivos/Movimientos.dat"
#include "Fecha.h"
#include "Calculadora.h"

class Contable
{
    private:
        int operacion, nroCta, nroFact;
//        int consolidar=0;
        float debe, haber, saldo, saldoAnterior;
        Fecha fOpe, fDesde, fHasta;


    public:

        ///setters
        void setOperacion(int);
        void setNroFact(int);
        void setNroCta(int);
        void  setDebe(float);
        void  setHaber(float);
        void  setSaldo(float);
        void  setSaldoAnterior();
        void setFechaOp(int, int, int);
        void setFechaDesde();
        void setFechaHasta();
        void setSumasSaldos(float, int);

        ///getters
        int getOperacion();
        int getNroFact();
        int getNroCta();
        float  getDebe();
        float  getHaber();
        float  getSaldo();
        float  getSaldoAnterior();
        Fecha getFechaOp();
        Fecha getFechaDesde();
        Fecha getFechaHasta();

        ///funciones
        // ctb.imputarCta(dato.fechaVenta.getDia(), dato.fechaVenta.getMes(), dato.fechaVenta.getAnio(),  nroFactura, cantidad, 1, getCodProducto());
        void imputarCta(int, int, int, int, int, int, int);///recibe parametros
        bool leerDeDisco(int);
        bool grabarEnDisco();///graba la imputacion linea por linea con "rb+"
        void listarMovimientos();
        void listarLibroDiario();///lista todas las cuentas  de una fecha determinada
        void listarLibroMayor();  ///de  un determinado mes y una determinada cuenta contable.
//        void listarSumasSaldos();
        void asientoManual();
};
        void listarPlanCtas();

#endif // CONTABLE_H
