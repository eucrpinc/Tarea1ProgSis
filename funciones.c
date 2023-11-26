// funciones.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void crearUsuario(Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios < 10) {
        printf("\nCreación de nuevo usuario\n");
        printf("Rol (Administrador/Bodeguero/Vendedor): ");
        scanf("%s", usuarios[*numUsuarios].rol);
        printf("Usuario: ");
        scanf("%s", usuarios[*numUsuarios].usuario);
        printf("Clave: ");
        scanf("%s", usuarios[*numUsuarios].clave);

        (*numUsuarios)++;
        printf("Usuario creado con éxito.\n");
    } else {
        printf("Error: No se pueden agregar más usuarios.\n");
    }
}

void actualizarUsuario(Usuario usuarios[], int numUsuarios) {
    printf("\nActualización de usuario\n");
    char usuarioBuscado[20];
    printf("Ingrese el nombre de usuario a actualizar: ");
    scanf("%s", usuarioBuscado);

    int encontrado = 0;
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].usuario, usuarioBuscado) == 0) {
            printf("Nuevo rol (Administrador/Bodeguero/Vendedor): ");
            scanf("%s", usuarios[i].rol);
            printf("Nueva clave: ");
            scanf("%s", usuarios[i].clave);

            encontrado = 1;
            printf("Usuario actualizado con éxito.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Error: Usuario no encontrado.\n");
    }
}

void crearProducto(Producto productos[], int *numProductos) {
    if (*numProductos < 50) {
        printf("\nCreación de nuevo producto\n");
        printf("Nombre: ");
        scanf("%s", productos[*numProductos].nombre);
        printf("Categoría: ");
        scanf("%s", productos[*numProductos].categoria);
        printf("Marca: ");
        scanf("%s", productos[*numProductos].marca);
        printf("Código: ");
        scanf("%d", &productos[*numProductos].codigo);
        printf("Precio de compra: ");
        scanf("%f", &productos[*numProductos].precioCompra);
        printf("Bodega: ");
        scanf("%s", productos[*numProductos].bodega);

        (*numProductos)++;
        printf("Producto creado con éxito.\n");
    } else {
        printf("Error: No se pueden agregar más productos.\n");
    }
}

void actualizarProducto(Producto productos[], int numProductos) {
    printf("\nActualización de producto\n");
    int codigoBuscado;
    printf("Ingrese el código del producto a actualizar: ");
    scanf("%d", &codigoBuscado);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].codigo == codigoBuscado) {
            printf("Nuevo nombre: ");
            scanf("%s", productos[i].nombre);
            printf("Nueva categoría: ");
            scanf("%s", productos[i].categoria);
            printf("Nueva marca: ");
            scanf("%s", productos[i].marca);
            printf("Nuevo precio de compra: ");
            scanf("%f", &productos[i].precioCompra);
            printf("Nueva bodega: ");
            scanf("%s", productos[i].bodega);

            encontrado = 1;
            printf("Producto actualizado con éxito.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Error: Producto no encontrado.\n");
    }
}

void venderProducto(Producto productos[], int numProductos, Venta ventas[], int *numVentas) {
    printf("\nRegistro de venta\n");
    int codigoBuscado;
    printf("Ingrese el código del producto a vender: ");
    scanf("%d", &codigoBuscado);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].codigo == codigoBuscado) {
            printf("Local: ");
            scanf("%s", ventas[*numVentas].local);
            printf("Vendedor: ");
            scanf("%s", ventas[*numVentas].vendedor);
            printf("Fecha: ");
            scanf("%s", ventas[*numVentas].fecha);
            printf("Precio de venta: ");
            scanf("%f", &ventas[*numVentas].precioVenta);
            printf("Cantidad: ");
            scanf("%d", &ventas[*numVentas].cantidad);

            // Actualizar la cantidad de producto en bodega
            // (Asumiendo que hay un campo 'cantidad' en la estructura Producto)
            productos[i].cantidad -= ventas[*numVentas].cantidad;

            (*numVentas)++;
            encontrado = 1;
            printf("Venta registrada con éxito.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Error: Producto no encontrado.\n");
    }
}

void guardarDatos(Usuario usuarios[], int numUsuarios, Producto productos[], int numProductos, Venta ventas[], int numVentas) {
    FILE *usuariosFile = fopen("usuarios.txt", "w");
    FILE *productosFile = fopen("productos.txt", "w");
    FILE *ventasFile = fopen("ventas.txt", "w");

    if (usuariosFile == NULL || productosFile == NULL || ventasFile == NULL) {
        printf("Error al abrir archivos para escritura.\n");
        exit(1);
    }

    // Guardar usuarios en el archivo
    for (int i = 0; i < numUsuarios; i++) {
        fprintf(usuariosFile, "%s %s %s\n", usuarios[i].rol, usuarios[i].usuario, usuarios[i].clave);
    }
    fclose(usuariosFile);

    // Guardar productos en el archivo
    for (int i = 0; i < numProductos; i++) {
        fprintf(productosFile, "%s %s %s %d %.2f %s\n", productos[i].nombre, productos[i].categoria,
                productos[i].marca, productos[i].codigo, productos[i].precioCompra, productos[i].bodega);
    }
    fclose(productosFile);

    // Guardar ventas en el archivo
    for (int i = 0; i < numVentas; i++) {
        fprintf(ventasFile, "%s %s %s %.2f %d\n", ventas[i].local, ventas[i].vendedor, ventas[i].fecha,
                ventas[i].precioVenta, ventas[i].cantidad);
    }
    fclose(ventasFile);
}

void cargarDatosUsuarios(Usuario usuarios[], int *numUsuarios) {
    FILE *archivoUsuarios = fopen("usuarios.txt", "r");
    if (archivoUsuarios == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        exit(1);
    }

    while (fscanf(archivoUsuarios, "%s %s %s", usuarios[*numUsuarios].rol, usuarios[*numUsuarios].usuario, usuarios[*numUsuarios].clave) == 3) {
        (*numUsuarios)++;
    }

    fclose(archivoUsuarios);
}

void cargarDatosProductos(Producto productos[], int *numProductos) {
    FILE *archivoProductos = fopen("productos.txt", "r");
    if (archivoProductos == NULL) {
        printf("Error al abrir el archivo de productos.\n");
        exit(1);
    }

    while (fscanf(archivoProductos, "%s %s %s %d %f %s", productos[*numProductos].nombre, productos[*numProductos].categoria,
           productos[*numProductos].marca, &productos[*numProductos].codigo, &productos[*numProductos].precioCompra,
           productos[*numProductos].bodega) == 6) {
        (*numProductos)++;
    }

    fclose(archivoProductos);
}

void cargarDatosVentas(Venta ventas[], int *numVentas) {
    FILE *archivoVentas = fopen("ventas.txt", "r");
    if (archivoVentas == NULL) {
        printf("Error al abrir el archivo de ventas.\n");
        exit(1);
    }

    while (fscanf(archivoVentas, "%s %s %s %f %d", ventas[*numVentas].local, ventas[*numVentas].vendedor,
           ventas[*numVentas].fecha, &ventas[*numVentas].precioVenta, &ventas[*numVentas].cantidad) == 5) {
        (*numVentas)++;
    }

    fclose(archivoVentas);
}
