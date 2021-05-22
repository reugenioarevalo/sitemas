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

bool validarBackup(){

	const int POSMENUX = 30;
    const int POSMENUY = 2;
	int codConf, codAux;

	srand(time(NULL));
	codAux = 127+(rand()%(100000-1));
	locate(POSMENUX+5,POSMENUY+1);
	cout << "INGRESE " << codAux << " PARA CONFIRMAR LA OPERACION\n";
	locate(POSMENUX+5,POSMENUY+2);
	cout << ">  ";
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
