#include <stdio.h>
#include <string.h>
#include "funciones.h"

struct Usuario crear_usuario(struct Usuario admin, char nombre[20], char username[20], char password[10]){
  struct Usuario u;
  int opcion2;
  
  if (admin.tipo == ADMINISTRADOR){
    strncpy(u.nombre, nombre, sizeof(u.nombre)); 
    strncpy(u.username, username, sizeof(u.username));
    strncpy(u.password, password, sizeof(u.password));

    printf("Tipo de usuario:\n");
    printf("[1] Administrador\n");
    printf("[2] Bodeguero\n");
    printf("[3] Vendedor\n");
    printf("[4] Default");
    scanf("%i", &opcion2);
    switch (opcion2){
      case 1:
        u.tipo = ADMINISTRADOR;
        break;

      case 2:
        u.tipo = BODEGUERO;
        break;

      case 3:
        u.tipo = VENDEDOR;
        break;

      case 4:
        printf("Usuario asignado como vendedor\n");
        printf("Si desea cambiar el tipo de usuario, podrá hacerlo desde el menú\n");
        u.tipo = VENDEDOR;

        break;

      default:
        printf("Usuario asignado como vendedor\n");
        printf("Si desea cambiar el tipo de usuario, podrá hacerlo desde el menú\n");
        u.tipo = VENDEDOR;

        break;
    }
    
  } else {
    printf("ERROR. Usted no es administrador.");

  }
  return u;
}

struct Usuario actualizar_usuario(struct Usuario admin, struct Usuario usuario) {
    int opcion;
    char nombre[20];
    char user[10];
    char password[10];
    int opcion2;

    if (admin.tipo == ADMINISTRADOR) {
        printf("Seleccione una categoría:\n");
        printf("[1] Nombre\n");
        printf("[2] Usuario\n");
        printf("[3] Contraseña\n");
        printf("[4] Tipo de usuario\n");
        printf("[5] Cancelar\n");

        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                printf("Nombre: ");
                scanf("%s", nombre);
                // Evita desbordamiento del buffer
                strncpy(usuario.nombre, nombre, sizeof(usuario.nombre));
                break;

            case 2:
                printf("Usuario: ");
                scanf("%s", user);
                strncpy(usuario.username, user, sizeof(usuario.username));
                break;

            case 3:
                printf("Contraseña: ");
                scanf("%s", password);
                strncpy(usuario.password, password, sizeof(usuario.password));
                break;

            case 4:
                printf("Tipo de usuario:\n");
                printf("[1] Administrador\n");
                printf("[2] Bodeguero\n");
                printf("[3] Vendedor\n");
                printf("[4] Cancelar");
                scanf("%i", &opcion2);
                switch (opcion2) {
                    case 1:
                        usuario.tipo = ADMINISTRADOR;
                        break;

                    case 2:
                        usuario.tipo = BODEGUERO;
                        break;

                    case 3:
                        usuario.tipo = VENDEDOR;
                        break;

                    case 4:
                        printf("Saliendo...\n");
                        printf("Saliste exitosamente\n");
                        break;

                    default:
                        printf("Saliendo...\n");
                        printf("Saliste exitosamente\n");
                        break;
                }
                break;

            case 5:
                printf("Saliendo...\n");
                printf("Saliste exitosamente\n");
                break;

            default:
                printf("Opción incorrecta.\n");
                printf("Saliendo...\n");
                printf("Saliste exitosamente\n");
                break;
        }

    } else {
        printf("ERROR. Usted no es administrador.\n");
    }
    return usuario;
}

struct Producto crear_producto(struct Usuario bodeguero, char nombre[20], float precio_compra, char marca [20], char codigo [10]){
  struct Producto p;
  int opcion2;

  if (bodeguero.tipo == BODEGUERO){
    strncpy(p.nombre, nombre, sizeof(p.nombre)); 
    strncpy(p.marca, marca, sizeof(p.marca)); 
    strncpy(p.codigo, codigo, sizeof(p.codigo)); 
    p.precio_compra = precio_compra;

    printf("Tipo de usuario:\n");
    printf("[1] Laptops\n");
    printf("[2] Teclados\n");
    printf("[3] Procesadores\n");
    printf("[4] Default\n");
    scanf("%i", &opcion2);
    switch (opcion2){
      case 1:
        p.cat = LAPTOPS;
        break;

      case 2:
        p.cat = TECLADOS;
        break;

      case 3:
        p.cat = PROCESADORES;
        break;

      case 4:
        printf("Producto asignado como default\n");
        printf("Si desea cambiar la cat del producto, podrá hacerlo desde el menú\n");
        p.cat = DEFAULT;

        break;

      default:
        printf("Producto asignado como default\n");
        printf("Si desea cambiar la cat del producto, podrá hacerlo desde el menú\n");
        p.cat = DEFAULT;

        break;
    }
    

  } else {
    printf("ERROR. Usted no es bodeguero.");

  }
  return p;
}

struct Producto actualizar_producto(struct Usuario bodeguero, struct Producto producto) {
      int opcion;
      int opcion2;
      char nombre[20];
      float precio;
      char marca[20];

      if (bodeguero.tipo == BODEGUERO) {
          printf("Seleccione una categoría:\n");
          printf("[1] Nombre\n");
          printf("[2] Precio\n");
          printf("[3] Marca\n");
          printf("[4] Categoría\n");
          printf("[5] Cancelar\n");

          scanf("%i", &opcion);

          switch (opcion) {
              case 1:
                  printf("Nombre: ");
                  scanf("%s", nombre);
                  // Evita desbordamiento del buffer
                  strncpy(producto.nombre, nombre, sizeof(producto.nombre));
                  break;

              case 2:
                  printf("Nuevo Precio: ");
                  scanf("%f", &precio);
                  producto.precio_compra = precio;
                  break;

              case 3:
                  printf("Nueva Marca: ");
                  scanf("%s", marca);
                  strncpy(producto.marca, marca, sizeof(producto.marca));
                  break;

              case 4:
                  printf("Categorías disponibles:\n");
                  printf("[1] Laptops\n");
                  printf("[2] Teclados\n");
                  printf("[3] Procesadores\n");
                  printf("[4] Default\n");
                  printf("[5] Cancelar\n");
                  scanf("%i", &opcion2);
                  switch (opcion2) {
                      case 1:
                          producto.cat = LAPTOPS;
                          break;

                      case 2:
                          producto.cat = TECLADOS;
                          break;

                      case 3:
                          producto.cat = PROCESADORES;
                          break;

                      case 4:
                          producto.cat = DEFAULT;
                          break;

                      case 5:
                          printf("Saliendo...\n");
                          printf("Saliste exitosamente\n");
                          break;

                      default:
                          printf("Saliendo...\n");
                          printf("Saliste exitosamente\n");
                          break;
                  }
                  break;

              case 5:
                  printf("Saliendo...\n");
                  printf("Saliste exitosamente\n");
                  break;

              default:
                  printf("Opción incorrecta.\n");
                  printf("Saliendo...\n");
                  printf("Saliste exitosamente\n");
                  break;
          }
      } else {
          printf("ERROR. Usted no es bodeguero.\n");
      }
      return producto;
  }

struct Venta vender_producto(struct Usuario vendedor, struct Producto producto, struct Local *sucursal, float precio_venta){
  struct Venta nuevaventa;
  time_t tiempo;

  nuevaventa.local = *sucursal;
  nuevaventa.vendedor = vendedor;
  nuevaventa.producto = producto;

  // Obtener la fecha y hora actual
  time(&tiempo);
  nuevaventa.fecha = *localtime(&tiempo);

  // Establecer el precio de venta
  nuevaventa.precio_venta = precio_venta; // Aquí debes establecer el precio de venta adecuado

  struct Bodega bodega = sucursal->bodega;
  bodega.inventario -= 1;

  return nuevaventa;
  
}