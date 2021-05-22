#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

#include "Entidad.h"
#include "Ventas.h"
#include "Compras.h"
#include "DetalleVenta.h"
#include "DetalleFactura.h"
#include "DetalleCompra.h"
#include "Producto.h"
#include "Productos.h"

//const char * FILE_PROVEEDORES = "Archivos/Proveedores.dat";
//const char * FILE_CLIENTES = "Archivos/Clientes.dat";
//const char * FILE_DETALLE="Archivos/DetalleVentas.dat" ;
//const char * FILE_VENTAS = "Archivos/Ventas.dat";
//const char * FILE_COMPRAS="Archivos/Compras.dat";
//const char * FILE_PRODUCTOS = "Archivos/Productos.dat";
//const char * FILE_DET_COMPRAS="Archivos/DetalleCompras.dat";

bool validarBackup(){

	const int POSMENUX = 30;
    const int POSMENUY = 2;
	int codConf, codAux;

	srand(time(NULL));
	codAux = 127+(rand()%(10000-1));
	locate(POSMENUX+5,POSMENUY+1);
	cout << "INGRESE " << codAux << " PARA CONFIRMAR LA OPERACION\n";
	locate(POSMENUX+5,POSMENUY+2);
	cin >> codConf;

	if(codConf == codAux){
		msj("PIN CORRECTO",WHITE,GREEN,130,TEXT_LEFT);
		return true;
	}
	else{
		msj("PIN INCORRECTO",WHITE,RED,130,TEXT_LEFT);
		return false;
	}
}

void backupArchivos(int opcion){

	   title("BACKUP", WHITE, CYAN);
       switch(opcion){
		case 1:
			if(validarBackup()==true){
				CopyFile(FILE_PROVEEDORES,"Backup/Proveedores.bkp" , FALSE);
				msj("COPIA DE SEGURIDAD EXITOSA",WHITE,GREEN,130,TEXT_LEFT);
			}else{
				msj("COPIA DE SEGURIDAD FALLIDA",WHITE,RED,130,TEXT_LEFT);
			}
			break;
		case 2:
			if(validarBackup()==true){
				CopyFile(FILE_CLIENTES,"Backup/Clientes.bkp", FALSE);
				msj("COPIA DE SEGURIDAD EXITOSA",WHITE,GREEN,130,TEXT_LEFT);
			}else{
				msj("COPIA DE SEGURIDAD FALLIDA",WHITE,RED,130,TEXT_LEFT);
			}			break;
		case 3:
			if(validarBackup()==true){
				CopyFile(FILE_DETALLE,"Backup/DetalleVentas.bkp", FALSE);
				CopyFile(FILE_VENTAS,"Backup/Ventas.bkp", FALSE);
				/// FALTA PLAN DE CUENTAS
				msj("COPIA DE SEGURIDAD EXITOSA",WHITE,GREEN,130,TEXT_LEFT);
			}else{
				msj("COPIA DE SEGURIDAD FALLIDA",WHITE,RED,130,TEXT_LEFT);
			}
			break;
		case 4:
			if(validarBackup()==true){
				CopyFile(FILE_DET_COMPRAS,"Backup/DetalleCompras.bkp", FALSE);
				CopyFile(FILE_COMPRAS,"Backup/Compras.bkp", FALSE);
				msj("COPIA DE SEGURIDAD EXITOSA",WHITE,GREEN,130,TEXT_LEFT);
			}else{
				msj("COPIA DE SEGURIDAD FALLIDA",WHITE,RED,130,TEXT_LEFT);
			}
			break;
		case 5:
			if(validarBackup()==true){
				CopyFile(FILE_PRODUCTOS,"Backup/Productos.bkp", FALSE);
				/// FALTA PLAN DE CUENTAS
				msj("COPIA DE SEGURIDAD EXITOSA",WHITE,GREEN,130,TEXT_LEFT);
			}else{
				msj("COPIA DE SEGURIDAD FALLIDA",WHITE,RED,130,TEXT_LEFT);
			}
			break;
		case 6:
			cout << "Plan de cuentas";
			break;
		case 7:
			if(validarBackup()==true){
				CopyFile(FILE_PROVEEDORES,"Backup/Proveedores.bkp" , FALSE);
				CopyFile(FILE_CLIENTES,"Backup/Clientes.bkp", FALSE);
				CopyFile(FILE_DETALLE,"Backup/DetalleVentas.bkp", FALSE);
				CopyFile(FILE_VENTAS,"Backup/Ventas.bkp", FALSE);
				CopyFile(FILE_DET_COMPRAS,"Backup/DetalleCompras.bkp", FALSE);
				CopyFile(FILE_COMPRAS,"Backup/Compras.bkp", FALSE);
				CopyFile(FILE_PRODUCTOS,"Backup/Productos.bkp", FALSE);
				/// FALTA PLAN DE CUENTAS
				msj("COPIA DE SEGURIDAD EXITOSA",WHITE,GREEN,130,TEXT_LEFT);
			}else{
				msj("COPIA DE SEGURIDAD FALLIDA",WHITE,RED,130,TEXT_LEFT);
			}
			break;
       }


	return;
}


//void  restaurarCopia(){
//        int opcion;
//      title("RESTAURAR COPIA DE SEGURIDAD DE COPIA A ARCHIVOS",BLACK,CYAN);
//       gotoxy(1,3);
//      cout<<"1. RESTAURAR COPIA"<<endl;
//      cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
//      cin>>opcion;
//      if(opcion==1){
//        CopyFile( "archivos/Entrenamientos.bkp", "archivos/Entrenamientos.dat", FALSE);
//        CopyFile("archivos/usuarios.bkp", "archivos/usuarios.dat",  FALSE);
//        cout<<"\n\t\t\tse realizo la restauracion  de  la copia de seguridad correctamente"<<endl;
//        system("PAUSE");
//      }else{
//          menu();
//      }
//
//        }
