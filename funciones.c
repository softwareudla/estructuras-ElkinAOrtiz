#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

struct Libro libros[MAX];
int total = 0;

void agregar() {
    if (total >= MAX) {
        printf("Capacidad maxima alcanzada.\n");
        return;
    }

    struct Libro nuevo;

    do {
        printf("ID: ");
        scanf("%d", &nuevo.id);
        getchar();
        if (nuevo.id <= 0 || !id_unico(nuevo.id)) {
            printf("Error: el ID debe ser unico y mayor que 0.\n");
        }
    } while (nuevo.id <= 0 || !id_unico(nuevo.id));

    do {
        printf("Titulo: ");
        fgets(nuevo.titulo, 100, stdin);
        nuevo.titulo[strcspn(nuevo.titulo, "\n")] = 0;
        if (strlen(nuevo.titulo) == 0) {
            printf("Error: el titulo no puede estar vacio.\n");
        }
    } while (strlen(nuevo.titulo) == 0);

    do {
        printf("Autor: ");
        fgets(nuevo.autor, 50, stdin);
        nuevo.autor[strcspn(nuevo.autor, "\n")] = 0;
        if (strlen(nuevo.autor) == 0) {
            printf("Error: no se escribio ningun autor.\n");
        }
    } while (strlen(nuevo.autor) == 0);

    do {
        printf("Anio: ");
        scanf("%d", &nuevo.anio);
        getchar();
        if (nuevo.anio <= 0) {
            printf("Error: el anio debe ser mayor que 0.\n");
        }
    } while (nuevo.anio <= 0);

    do {
        printf("Estado (Disponible/Prestado): ");
        fgets(nuevo.estado, 11, stdin);
        nuevo.estado[strcspn(nuevo.estado, "\n")] = 0;
        if (strcmp(nuevo.estado, "Disponible") != 0 && strcmp(nuevo.estado, "Prestado") != 0) {
            printf("Error: el estado debe ser 'Disponible' o 'Prestado'.\n");
        }
    } while (strcmp(nuevo.estado, "Disponible") != 0 && strcmp(nuevo.estado, "Prestado") != 0);

    libros[total++] = nuevo;
    printf("Libro agregado correctamente.\n");
}

void mostrar_libros() {
    if (total == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("+----+----------------------+----------------------+-------+-------------+\n");
    printf("| ID | Titulo               | Autor                | Anio   | Estado      |\n");
    printf("+----+----------------------+----------------------+-------+-------------+\n");

    for (int i = 0; i < total; i++) {
        printf("| %-2d | %-20s | %-20s | %-5d | %-11s |\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio,
               libros[i].estado);
    }

    printf("+----+----------------------+----------------------+-------+-------------+\n");
}




void buscar() {
    int opcion;

    printf("Buscar por:\n1. ID\n2. Titulo\nOpcion: ");
    scanf("%d", &opcion);
    getchar();

    if (opcion == 1) {
        int id;
        do {
            printf("Ingrese un ID positivo: ");
            scanf("%d", &id);
            getchar();
            if (id <= 0) {
                printf("Error: el ID debe ser mayor que 0.\n");
            }
        } while (id <= 0);

        int idx = buscar_id(id);
        if (idx == -1) {
            printf("No encontrado.\n");
        } else {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\n", libros[idx].id);
            printf("Titulo: %s\n", libros[idx].titulo);
            printf("Autor: %s\n", libros[idx].autor);
            printf("Anio: %d\n", libros[idx].anio);
            printf("Estado: %s\n", libros[idx].estado);
        }

    } else if (opcion == 2) {
        char titulo[100];
        printf("Ingrese el titulo: ");
        fgets(titulo, 101, stdin);
        titulo[strcspn(titulo, "\n")] = 0;

        int encontrado = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(libros[i].titulo, titulo) == 0) {
                printf("\nLibro encontrado:\n");
                printf("ID: %d\n", libros[i].id);
                printf("Titulo: %s\n", libros[i].titulo);
                printf("Autor: %s\n", libros[i].autor);
                printf("Anio: %d\n", libros[i].anio);
                printf("Estado: %s\n", libros[i].estado);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) printf("No encontrado.\n");
    } else {
        printf("Opcion invalida.\n");
    }
}

void actualizar() {
    int id;
    printf("ID del libro a actualizar: ");
    scanf("%d", &id);
    getchar();

    int idx = buscar_id(id);
    if (idx == -1) {
        printf("No encontrado.\n");
        return;
    }

    printf("Estado actual: %s\n", libros[idx].estado);
    do {
        printf("Nuevo estado (Disponible/Prestado): ");
        fgets(libros[idx].estado, 11, stdin);
        libros[idx].estado[strcspn(libros[idx].estado, "\n")] = 0;
        if (strcmp(libros[idx].estado, "Disponible") != 0 && strcmp(libros[idx].estado, "Prestado") != 0) {
            printf("Error: el estado debe ser 'Disponible' o 'Prestado'.\n");
        }
    } while (strcmp(libros[idx].estado, "Disponible") != 0 && strcmp(libros[idx].estado, "Prestado") != 0);

    printf("Estado actualizado correctamente.\n");
}

void eliminar() {
    int id;
    printf("ID del libro a eliminar: ");
    scanf("%d", &id);
    getchar();

    int idx = buscar_id(id);
    if (idx == -1) {
        printf("No encontrado.\n");
        return;
    }

    for (int i = idx; i < total - 1; i++) {
        libros[i] = libros[i + 1];
    }
    total--;

    printf("Libro eliminado correctamente.\n");
}

int buscar_id(int id) {
    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) {
            return i;
        }
    }
    return -1;
}

int id_unico(int id) {
    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) {
            return 0;
        }
    }
    return 1;
}