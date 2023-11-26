#include <stdio.h>
#include "funciones.h"

int main() {
    Usuario usuarios[10];
    int numUsuarios = 0;

    Producto productos[50];
    int numProductos = 0;

    Venta ventas[50];
    int numVentas = 0;

    cargarDatosUsuarios(usuarios, &numUsuarios);
    cargarDatosProductos(productos, &numProductos);
    cargarDatosVentas(ventas, &numVentas);

    int opcion;
    do {
        printf("\n----- Menú Principal -----\n");
        printf("1. Crear Usuario\n");
        printf("2. Actualizar Usuario\n");
        printf("3. Crear Producto\n");
        printf("4. Actualizar Producto\n");
        printf("5. Vender Producto\n");
        printf("6. Guardar Datos\n");
        printf("0. Salir\n");

        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearUsuario(usuarios, &numUsuarios);
                break;
            case 2:
                actualizarUsuario(usuarios, numUsuarios);
                break;
            case 3:
                crearProducto(productos, &numProductos);
                break;
            case 4:
                actualizarProducto(productos, numProductos);
                break;
            case 5:
                venderProducto(productos, numProductos, ventas, &numVentas);
                break;
            case 6:
                guardarDatos(usuarios, numUsuarios, productos, numProductos, ventas, numVentas);
                break;
            case 0:
                printf("Saliendo del programa. Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción correcta.\n");
        }
    } while (opcion != 0);

    return 0;
}
