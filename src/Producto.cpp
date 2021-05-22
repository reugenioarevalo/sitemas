#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include "../Include/Producto.h"

using namespace std;

///ESTADO: CONTINUAR HACIENDO QUE LEA UN ARCHIVO DE PRODUCTOS QUE SERIA EL REGISTRO GENERAL DE PRODUCTOS.

    ///SETTERS

        int Producto::setId(int idAux){this->id=idAux;}
        void Producto::setCodProv(int codProv){this->codProv=codProv;}
        void Producto::setDescripcion(char *descripcion){strcpy(this->descripcion,descripcion);}
        void Producto::setPlanCta(int planCta){this->planCta=planCta;}
//        void Producto::setStock(int stock){this->stock=stock;}
        void Producto::setPrecioCosto(float precioCosto){this->precioCosto=precioCosto;}
        void Producto::setIva(float iva){this->iva=iva;}
        void Producto::setStockMin(int stockMin){this->stockMin=stockMin;}
        void Producto::setEstado(bool estado){this->estado=estado;}


    void Producto::cargarProducto(){
        id=setId();
        getId();
        setCodProv();
        setStock( 0);
        setDescripcion();
        setPlanCta();
        setPrecioCosto();
        setIva();
        setStockMin();
        setEstado();
        mostrarProducto();

        if(grabarEnDisco()==true){
            cout<<"Producto cargado con exito!";

        }else{
            cout<<"Error al guardar el Producto!";
            system("PAUSE");
            }
    }
    int Producto::setId(){
        int bytes, cant;
        FILE *p = fopen(FILE_PRODUCTOS, "rb");
        if (p == NULL){
            return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        fclose(p);
        cant = bytes / sizeof(Producto);
        return cant+1;
    }
    void Producto::setCodProv(){
        cout<<"\nCodigo de Proveedor: ";
        cin>>codProv;
    }
    void Producto::setStock(int _stock=0){
        if(_stock==0){
        cout<<"\nIngresar la Cantidad: ";
        cin>>stock;
        }else{
            this->stock=_stock;
        }
    }
    void Producto::setDescripcion(){
        cin.ignore();
        cout<<"\nDescripcion: ";
        cin.getline(descripcion,50);
    }
    void Producto::setPlanCta(){
        cout<<"\nPlan de Cuenta: ";
        cin>>planCta;
    }
    void Producto::setPrecioCosto(){
        cout<<"\nPrecio: ";
        cin>>precioCosto;
    }
    void Producto::setIva(){
        cout<<"\nIva: ";
        cin>>iva;
    }
    void Producto::setStockMin(){
        cout<<"\nStock minimo: ";
        cin>>stockMin;
    }
    void Producto::setEstado(){
        int opc;
        cout<<"Elija la opcion correspondiente"<<endl;
        cout<<"1-ACTIVO \n2-INACTIVO"<<endl;
        cout<<"\nOpcion: ";
        cin>>opc;

        switch(opc){
    case 1:
        estado=true;
        break;
    case 2:
        estado=false;
        break;
    default:
        cout<<"Opcion invalida";
        break;
        }
    }

    bool Producto::setMod(int id, int tipoOperacion,int cant, float precio){
        int cantidad=0;
        float prec=0;
        leerDeDisco(buscarProdxId(id));
        if(tipoOperacion==2){ // TipoEntidad 2 es proveedores osea q es compras
            cantidad = getStock()+cant;
            prec=precio;
        }else if(tipoOperacion==1){//TipoEntidad 1 es Clientes osea que es Venta
            cantidad = getStock()-cant;
            prec = getPrecioCosto();
        }
            Modificar_en_disco(buscarProdxId(id), cantidad, prec);
            return true;
    }
    ///DISCO
    bool Producto::grabarEnDisco(){

        system("cls");
        FILE *p;
        bool chequeo;

        p = fopen(FILE_PRODUCTOS,"ab");
        if(p==NULL){
            cout << "Error al abrir el archivo \n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Producto),1,p);
        if(chequeo==1){

            //msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            //cout << "Registro exitoso";
            fclose(p);
            //system("pause");
            return true;
        }
        else{
            //cout << "El registro no pudo guardarse \n\n";
            fclose(p);
            //system("pause");
            return false;
        }
    }
    bool Producto::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_PRODUCTOS, "rb");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof*this, 0);
        leyo = fread(this, sizeof(Producto), 1, p);
        fclose(p);
        //getProducto();
        return leyo;
    }
    ///GETTERS
    int Producto::getId(){
        return this->id;
    }
    int Producto::getCodProv(){
        return this->codProv;
    }
    char* Producto::getDescripcion(){
        return this->descripcion;
    }
    int Producto::getPlanCta(){
        return this->planCta;
    }
    int Producto::getStock(){
        return this->stock;
    }
    float Producto::getPrecioCosto(){
        return this->precioCosto;
    }
    float Producto::getIva(){
        return this->iva;
    }
    int Producto::getStockMin(){
        return this->stockMin;
    }
    bool Producto::getEstado(){
        return this->estado;
    }

    int Producto::checkStock(int id, int cant){
        while(leerDeDisco(buscarProdxId(id))){
            if(getStock()>=cant){
                return 1;//Hay stock
            }else if(getStock()<cant && getStock()>0) {
                return -1;//No hay suficiente en Stock
            }else{return -2;}//Stock 0
        }
    }
    void Producto::mostrarProducto(){
        cout<<getId()<<endl;
        cout<<getCodProv()<<endl;
        cout<<getDescripcion()<<endl;
        cout<<getPlanCta()<<endl;
        cout<<getStock()<<endl;
        cout<<getPrecioCosto()<<endl;
        cout<<getIva()<<endl;
        cout<<getStockMin()<<endl;
        cout<<getEstado()<<endl;
        system("PAUSE");
    }
    int Producto::buscarProdxId(int idAux){
        int contador=0;
        FILE *p;

        p = fopen(FILE_PRODUCTOS,"rb");

        if(p==NULL){
            return -1;///codigo de error de que no halló el archivo.
        }
        while(fread(this, sizeof(Producto),1, p)==1){
            if(getId() == idAux){
                fclose(p);
                return contador;
            }
            contador++;
        }
        fclose(p);
        return -2;///codigo de error de rutina inexistente.
}

void Producto::Modificar_en_disco(int pos, int  cantidad, float _pre){
    FILE *p;
    this->setStock(cantidad);
    this->setPrecioCosto(_pre);
    p=fopen(FILE_PRODUCTOS,"rb+");
    if(p==NULL){cout<<"Error de archivo";exit(1);}
    fseek(p,(pos)*sizeof(this),0);
    fwrite(this,sizeof(this),1,p);
    fclose(p);
}
