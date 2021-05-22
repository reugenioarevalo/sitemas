#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto{

    private:
        int id,codProv,planCta,stock,stockMin;
        float precioCosto,iva;
        bool estado;
        char descripcion[50];
    public:
        void cargarProducto();
        ///Producto(int,const char*);

        int setId();///ASIGNA EL CAMPO ID DE UN OBJETO TIPO PRODUCTO **HECHA
        void setCodProv();///Setea el Codigo de proveedor de un Producto **HECHA**
        void setDescripcion();///**HECHO**
        void setPlanCta();///**HECHO**
        void setStock();///Setea el stock de un producto en inventario. **HECHA**
        void setPrecioCosto();///**HECHO**
        void setIva();///**HECHO**
        void setStockMin();
        void setEstado();
        bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**
        bool leerDeDisco(int posicion);///Lee de disco un producto cuya posicion se pasa como parámetro **HECHA
        int buscarProdxId(int idAux);///DEVUELVE LA POSICION DE UN PRODUCTO POR ID QUE ES PASADO COMO PARAMETRO **HECHA
        void getId();///MUESTRA EL ID DE UN OBJETO TIPO PRODUCTO **FALTA**
        void getCodProv();
        void getDescripcion();
        void getPlanCta();
        void getStock();///Devuelve el stock de un producto en inventario.
        void getPrecioCosto();
        void getIva();///**HECHO**
        void getStockMin();///
        void getEstado();
        void listarProductos();///LISTA LOS PRODUCTOS QUE SE ENCUENTRAN EN EL ARCHIVO DE PRODUCTOS (INVENTARIO)
        void getProducto();/// Devuelve un producto producto recibiendo su id como parametro.**HECHA**
};

#endif // PRODUCTO_H
