# Sistema de administración contable para PYMEs
TP LAB 2 2020 UTN FRGP

**[Integrantes:]**
------------------------------
**AREVALO, R. Eugenio**

**AROSTEGUI, Isidoro**

**AYALA, Elizabeth C.**

**QUINTEROS, David**

------------------------------

INTRODUCCION
------------
El sistema a desarrollar permitirá simular la administración contable de una Pyme.
Contará con un menú principal y una serie de submenúes que serán la interfaz grafica
para la gestión de contabilidad , compras, ventas y stock.

CONTABILIDAD
------------
El objetivo principal del programa es llevar a cabo el registro contable de la empresa.
Se registrará mediante asientos manuales, utilizando un pseudo “Plan de Cuentas”,
permitiendo clasificar las cuentas para poder ser registradas en el debe y haber del
archivo de movimientos contables, es decir, indicara si la operación proviene del
sistema de compras o de ventas, asientos manuales, u otra operación. Calculará,
además impuestos del 10,5%, 21% según operaciones realizadas. Por otro lado, estos
impuestos se verán reflejados tanto en facturas como en órdenes de compras.
*Libro Diario:*
!["Libro Diario"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/libro%20diario1.JPG?raw=true "Libro Diario")

ENTIDADES
------------
La clase Entidad contendrá datos de los CLientes y Proveedores distinguiendolos con un campo TipoEntidad, y utilizaría un unico archivo para donde guardar los datos. 

*Entidades:*
!["Entidades"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/entidades.JPG?raw=true )

COMPRAS
------------
El sistema registrará las operaciones que impliquen la adquisición de bienes y/o
servicios, contabilizando mediante el código de proveedor, y discriminado los ítems de
la FC según corresponda

*Compras:*
!["Compras"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/productos.JPG?raw=true )

VENTAS
------------
Este sistema será para empresas calificadas como responsable inscripto (RI), por lo
tanto, en la gestión de ventas se emitirán facturas del tipo A. La factura A detallará el
CUIT del comprador, nombre y apellido o razón social y el Impuesto del Valor Agregado
entre otros.

*Facturas y Detalle:*
!["Facturas y Detalle"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/detalleweb.png?raw=true "Detalle de facturas y facturas")


STOCK - PRODUCTOS
------------
Este sistema presentará un modelo de stock basado en archivos en el cual podremos
cargar productos de forma manual o podrán aumentar mediante una compra realizada
por la empresa o disminuir por una venta realizada.
*Sotck:*
!["Prodcutos"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/productos.JPG?raw=true )


MODULOS
------------
Contaría con los siguientes módulos estimativos

CONTABILIDAD
------------
- Libro Mayor
- Libro Diario
- Asientos Manuales
- Sumas y saldos
- Cierre de caja
- Apertura de caja


VENTAS
------------
- Registro de Ventas
- Emisión de comprobante


COMPRAS
------------
- Orden de compras
- Pagos a proveedores


STOCK/PRODUCTOS
------------
- Inventario
- Carga de almacén


