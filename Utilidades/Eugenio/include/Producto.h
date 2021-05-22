#ifndef PRODUCTO_H
#define PRODUCTO_H
#define FILE_PRODUCTOS "Archivos/Productos.dat"

class Producto
{
    private:
        int id,codProv,planCta,stock,stockMin;
        float precioCosto,iva;
        bool estado;
        char descripcion[50];
    public:
        void cargarProducto();

        ///SETTERS A
        int setId(int idAux);
        void setCodProv(int codProv);
        void setDescripcion(char *descripcion);
        void setPlanCta(int planCta);
        void setStock(int stock);
        void setPrecioCosto(float precioCosto);
        void setIva(float iva);
        void setStockMin(int stockMin);
        void setEstado(bool estado);
        bool setMod(int id, int tipoOperacion,int cant, float precio);

        ///SETTERS B
        int setId();
        void setCodProv();
        void setDescripcion();
        void setPlanCta();
        void setStock();
        void setPrecioCosto();
        void setIva();
        void setStockMin();
        void setEstado();
        void setProducto(Producto target);

        ///DEVUELVEN:
        int getId();
        int getCodProv();
        char* getDescripcion();
        int getPlanCta();
        int getStock();
        float getPrecioCosto();
        float getIva();
        int getStockMin();
        bool getEstado();
        Producto getProducto(int idProd);/// Devuelve un producto producto recibiendo su id como parametro.
        int checkStock(int id, int cant);///verificar cantidad en existencia

        bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**
        bool leerDeDisco(int posicion);///Lee de disco un producto cuya posicion se pasa como parámetro **HECHA
        void mostrarProducto();///muestra un producto
        int buscarProdxId(int idAux);///DEVUELVE LA POSICION DE UN PRODUCTO POR ID QUE ES PASADO COMO PARAMETRO **HECHA
        void Modificar_en_disco(int , int, float);
};

#endif // PRODUCTO_H
