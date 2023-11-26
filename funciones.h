#include <stdio.h>
#include <time.h>

enum tipo_usuario {
  ADMINISTRADOR,
  BODEGUERO,
  VENDEDOR,

};

enum categoria{
  LAPTOPS,
  TECLADOS,
  PROCESADORES,
  DEFAULT,

};

struct Usuario {
  enum tipo_usuario tipo;
  char nombre[20];
  char username[10];
  char password[10];
};

struct Bodega {
  char nombre [20];
  int id;
  int inventario;
};

struct Local {
  char nombre[20];
  struct Bodega bodega;
};

struct Producto {
  char nombre[20];
  enum categoria cat;
  char marca[20];
  char codigo[10];
  float precio_compra;
  struct Bodega bodega;
};

struct Venta {
  struct Local local;
  struct Usuario vendedor;
  struct tm fecha;
  struct Producto producto;
  float precio_venta;
};

struct Usuario crear_usuario(struct Usuario admin, char nombre[20], char username[20], char password[10]);

struct Usuario actualizar_usuario(struct Usuario admin, struct Usuario usuario);

struct Producto crear_producto(struct Usuario bodeguero, char nombre[20], float precio_compra, char marca [20], char codigo [10]);

struct Producto actualizar_producto(struct Usuario bodeguero, struct Producto producto);

struct Venta vender_producto(struct Usuario vendedor, struct Producto producto, struct Local *sucursal, float precio_venta);