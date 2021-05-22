#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "../Utilidades/Backup.h"
#include "../Utilidades/menus.h"
#include "../Include/Entidad.h"
#include "../Include/Ventas.h"
#include "../Include/Contable.h"
#include "../Include/Compras.h"
#include "../Include/DetalleVenta.h"
#include "../Include/DetalleFactura.h"
#include "../Include/DetalleCompra.h"
#include "../Include/Producto.h"
#include "../Include/Productos.h"
#include "../Include/Usuario.h"


///---------------------------------------------- MENU LOGIN

void menuLogin(){
    setlocale(LC_ALL, "spanish");
	int attempts = 3, chequeo=0;

    while(attempts != 0){
		title("LOGIN", WHITE, RED);
		cout << endl << endl;
        chequeo = login();

        if(chequeo == 1 || chequeo == 2){
            attempts = 0;
        }else{
        attempts--;
		}
		system("cls");

    }

    if(chequeo == 1){
        menuPrincipal();
        return;
    }else if(chequeo == 2){
        menuMaestro();
        return;
    }else{
        msj("HA SUPERADO EL LIMITE DE INTENTOS",WHITE,RED,130,TEXT_LEFT);
        return;
    }
    return;
}

///---------------------------------------------- MENU MAESTRO

void menuMaestro(){

        const int POSMENUX = 0;
        const int POSMENUY = 0;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = RED;

    setlocale(LC_ALL, "spanish");
//    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("TONGA GESTION - ADMINISTRADOR", WHITE, CYAN);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "COMPRAS";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "VENTAS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "INVENTARIOS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "ENTIDADES";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "CONTABILIDAD";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "CONFIGURACION";
      locate(POSMENUX+3,POSMENUY+9);
      cout << "SALIR\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=6;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                menuCompras();
        break;
        case 2:
                menuVentas();
        break;
        case 3:
				menuInventario();
        break;
        case 4:
                menuEntidades();
        break;
        case 5:
            menuContable();
                anykey();
        break;
        case 6:
                menuConfiguracion();
        break;
        case 0:
                return;
        break;
      }
    }
    return;
}

///---------------------------------------------- MENU PRINCIPAL

void menuPrincipal(){

        const int POSMENUX = 0;
        const int POSMENUY = 0;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = RED;
        Usuario usuarioPiloto;
        bool check;

    setlocale(LC_ALL, "spanish");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("TONGA GESTION", WHITE, RED);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "COMPRAS";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "VENTAS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "INVENTARIOS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "ENTIDADES";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "CONTABILIDAD";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "CAMBIAR CONTRASEÑA";
      locate(POSMENUX+3,POSMENUY+9);
      cout << "SALIR\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 7){
                opc++;
            }else{
                opc=1;
            }
            break;
        case KEY_UP:
            if(opc > 1){
                opc--;
            }else{
                opc=7;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                menuCompras();
        break;
        case 2:
                menuVentas();
        break;
        case 3:
				menuInventario();
        break;
        case 4:
                menuEntidades();
        break;
        case 5:
                cout << "Opcion 5";
                system("pause");
        break;
        case 6:
            check = usuarioPiloto.cambiarPasswordUser();
            if(check==true){
            msj("CONTRASEÑA GUARDADA",WHITE,GREEN,130,TEXT_LEFT);
            }
            else msj("ERROR",WHITE,RED,130,TEXT_LEFT);
        break;
        case 7:
            return;
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;
}

///---------------------------------------------- MENU COMPRAS

void menuCompras(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;
        Entidad EntidadPiloto;
        Compras cmpr;
        DetalleCompra detComp;


    setlocale(LC_ALL, "spanish");
    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      //setBackgroundColor(FONDO);
      locate(POSMENUX+5,POSMENUY+1);
      title("COMPRAS", WHITE, BLUE);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "CARGAR COMPRA";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "LISTAR TODAS LAS COMPRAS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "CARGAR PROVEEDOR";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "BUSCAR PROVEEDOR POR CUIT";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "LISTAR PROVEEDORES";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "ATRAS\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 5){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=5;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 8;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                cmpr.cargarCompras();
        break;
        case 2:
                cmpr.listado_compras();
                system("pause");
        break;
        case 3:
                EntidadPiloto.cargarCliente();
//                EntidadPiloto.grabarEnDisco(1);
                EntidadPiloto.mostrarEntidad();
                system("pause");
        break;
        case 4:
                EntidadPiloto.buscarRazonSocial(2);
                system("pause");
        break;
        case 5:
                    EntidadPiloto.listarEntidadesTabla(2);
        break;
        case 0:
        return;
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;

}

///---------------------------------------------- MENU VENTAS

void menuVentas(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;
        Entidad EntidadPiloto;
        Ventas vtas;
        DetalleVenta deta;

    setlocale(LC_ALL, "spanish");
    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("VENTAS", WHITE, BLUE);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "CARGAR VENTA";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "IMPRIMIR FACTURA";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "LISTAR DETALLE DE TODAS LAS VENTAS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "LISTADO DE FACTURAS EMITIDAS"; /// ver como validad que no cargue en el arhcivo incorrecto
      locate(POSMENUX+3,POSMENUY+7);
      cout << "BUSCAR CLIENTE POR CUIT";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "LISTAR CLIENTES";
      locate(POSMENUX+3,POSMENUY+9);
      cout << "ATRAS\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=6;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
           vtas.cargarVtas();
        break;
        case 2:
            deta.imprimirFactura();
        break;
        case 3:
            deta.listado_detalle();
        break;
        case 4:
           vtas.listado_facturas();
        break;
        case 5:
            EntidadPiloto.buscarRazonSocial(1);
        break;
        case 6:
            EntidadPiloto.listarEntidadesTabla(1);
        break;
        case 0:
        return;
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;

}

///---------------------------------------------- MENU INVENTARIOS

void menuInventario(){

        Producto obj;
        Productos objA;
        const int POSMENUX = 0;
        const int POSMENUY = 0;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = RED;

    setlocale(LC_ALL, "spanish");
//    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("INVENTARIOS", WHITE, BLUE);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "CARGAR PRODUCTO";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "LISTAR PRODUCTO POR ID";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "LISTAR TODOS LOS PRODUCTOS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "ATRAS\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 4){
                opc++;
            }else{
                opc=1;
            }
            break;
        case KEY_UP:
            if(opc > 1){
                opc--;
            }else{
                opc=4;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 3; /// CHEQUEAR
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                obj.cargarProducto();
        break;
        case 2:
        int id;
                cout<<"\nINGRESE ID: ";
                cin>>id;
                obj.buscarProdxId(id);
                obj.mostrarProducto();
        break;
        case 3:
				objA.listarProductos();
        break;
        case 4:
                return;
        break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
        break;
      }
    }
    return;
}

///---------------------------------------------- MENU ENTIDADES

void menuEntidades(){

        const int POSMENUX = 0;
        const int POSMENUY = 0;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = RED;

        Entidad EntidadPiloto;

    setlocale(LC_ALL, "spanish");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("ENTIDADES", WHITE, BLUE);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "LISTAR CLIENTES";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "CARGAR CLIENTE";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "LISTAR PROVEEDORES";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "CARGAR PROVEEDOR";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "ATRAS\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 5){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 1){
                opc--;
            }else{
                opc=5;
            }
            break;
        }
        if(opc != 1){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 3; /// CHEQUEAR
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                EntidadPiloto.listarEntidadesTabla(1);
                cls();
        break;
        case 2:
                EntidadPiloto.cargarCliente();
        break;
        case 3:
                EntidadPiloto.listarEntidadesTabla(2);
                cls();
        break;
        case 4:
                EntidadPiloto.cargarProveedor();
        break;
        case 5:
                return;
        break;
      }
    }
    return;
}

///---------------------------------------------- CONFIGURACION

void menuConfiguracion(){

        Usuario usuarioPiloto;

        const int POSMENUX = 0;
        const int POSMENUY = 0;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = RED;

        Entidad EntidadPiloto;

    setlocale(LC_ALL, "spanish");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("CONFIGURACION", WHITE, CYAN);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "BACKUP";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "CREAR USUARIO";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "DAR DE BAJA USUARIO\n";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "LISTAR TODOS LOS USUARIOS\n";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "CAMBIAR CONTRASEÑA\n";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "ATRAS\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=1;
            }
            break;
        case KEY_UP:
            if(opc > 1){
                opc--;
            }else{
                opc=6;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 3; /// CHEQUEAR
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
            menuBackup();
        break;
        case 2:
            crearUsuario();
        break;
        case 3:
            bajaLogicaUsuario();
        break;
        case 4:
            listarUsuarios();
        break;
        case 5:
            cambiarPasswordAdmin();
        break;
        case 6:
            return;
        break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
        break;
      }
    }
    return;
}

///---------------------------------------------- MENU BACKUP

void menuBackup(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;
        Entidad EntidadPiloto;
        Ventas vtas;
        DetalleVenta deta;

    setlocale(LC_ALL, "spanish");
    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("BACKUP", WHITE, CYAN);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "PROVEEDORES";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "CLIENTES";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "FACTURAS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "ORDENES DE COMPRA";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "PRODUCTOS";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "PLAN DE CUENTAS";
      locate(POSMENUX+3,POSMENUY+9);
      cout << "TODOS LOS ARCHIVOS";
      locate(POSMENUX+3,POSMENUY+10);
      cout << "ATRAS\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 8){
                opc++;
            }else{
                opc=1;
            }
            break;
        case KEY_UP:
            if(opc > 1){
                opc--;
            }else{
                opc=8;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
            backupArchivos(1);
        break;
        case 2:
            backupArchivos(2);
        break;
        case 3:
            backupArchivos(3);
        break;
        case 4:
            backupArchivos(4);
        break;
        case 5:
            backupArchivos(5);
        break;
        case 6:
            backupArchivos(6);
        break;
        case 7:
            backupArchivos(7);
        break;
        case 8:
            return;
        break;
      }
    }
    return;
}
///---------------------------------------------- MENU CONTABLE

void menuContable(){
 Contable ctbl;
        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;
        Entidad EntidadPiloto;
        Compras cmpr;
        DetalleCompra detComp;


    setlocale(LC_ALL, "spanish");
    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      //setBackgroundColor(FONDO);
      locate(POSMENUX+5,POSMENUY+1);
      title("CONTABILIDAD", WHITE, BLUE);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "LISTAR MAYOR DE UNA CUENTA";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "LISTAR TODOS LOS MOVIMIENTOS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "LISTAR UN LIBRO DIARIO";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "GENERAR UN ASIENTO MANUAL";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "LISTAR PLAN DE CUENTAS";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "ATRAS\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 5){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=5;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 8;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
            ctbl.listarLibroMayor();
            anykey();
        break;
        case 2:
            ctbl.listarMovimientos();
            anykey();
        break;
        case 3:
           ctbl.listarLibroDiario();
            anykey();
        break;
        case 4:
            ctbl.asientoManual();
            anykey();
        break;
        case 5:
            listarPlanCtas() ;
            anykey();
       break;
        case 0:
        return;
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;

}

