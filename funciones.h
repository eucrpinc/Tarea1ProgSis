// funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
    char rol[20];
    char usuario[20];
    char clave[20];
} Usuario;

typedef struct {
    char nombre[50];
    char categoria[20];
    char marca[20];
    int codigo;
    float precioCompra;
    char bodega[20];
} Producto;

typedef struct {
    char local[20];
    char vendedor[20];
    char fecha[20];
    float precioVenta;
    int cantidad;
} Venta;

void crearUsuario(Usuario usuarios[], int *numUsuarios);
void actualizarUsuario(Usuario usuarios[], int numUsuarios);
void crearProducto(Producto productos[], int *numProductos);
void actualizarProducto(Producto productos[], int numProductos);
void venderProducto(Producto productos[], int numProductos, Venta ventas[], int *numVentas);
void guardarDatos(Usuario usuarios[], int numUsuarios, Producto productos[], int numProductos, Venta ventas[], int numVentas);
void cargarDatosUsuarios(Usuario usuarios[], int *numUsuarios);
void cargarDatosProductos(Producto productos[], int *numProductos);
void cargarDatosVentas(Venta ventas[], int *numVentas);

#endif
