#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;

    do {
        printf("Biblioteca\n");
        printf("1. Agregar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro\n");
        printf("4. Cambiar estado\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                agregar();
                break;
            case 2:
                mostrar_libros();
                break;
            case 3:
                buscar();
                break;
            case 4:
                actualizar();
                break;
            case 5:
                eliminar();
                break;
            case 6:
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 6);

    return 0;
}