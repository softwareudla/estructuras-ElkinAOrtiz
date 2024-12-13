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
    printf("ID: ");
    scanf("%d", &nuevo.id);
    getchar();

    if (!id_unico(nuevo.id)) {
        printf("ID ya registrado.\n");
        return;
    }

    printf("Titulo: ");
    fgets(nuevo.titulo, 100, stdin);
    nuevo.titulo[strcspn(nuevo.titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(nuevo.autor, 50, stdin);
    nuevo.autor[strcspn(nuevo.autor, "\n")] = 0;

    printf("Anio: ");
    scanf("%d", &nuevo.anio);
    getchar();

    printf("Estado (Disponible/Prestado): ");
    fgets(nuevo.estado, 11, stdin);
    nuevo.estado[strcspn(nuevo.estado, "\n")] = 0;

    libros[total++] = nuevo;
    printf("Libro agregado.\n");
}

void mostrar_libros() {
    if (total == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nLibro %d:\n", i + 1);
        printf("ID: %d\n", libros[i].id);
        printf("Titulo: %s\n", libros[i].titulo);
        printf("Autor: %s\n", libros[i].autor);
        printf("Anio: %d\n", libros[i].anio);
        printf("Estado: %s\n", libros[i].estado);
    }
}

void buscar() {
    char entrada[100];
    printf("Titulo o ID: ");
    fgets(entrada, 100, stdin);
    entrada[strcspn(entrada, "\n")] = 0;

    int encontrado = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(libros[i].titulo, entrada) == 0 || libros[i].id == atoi(entrada)) {
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

    if (!encontrado) {
        printf("No encontrado.\n");
    }
}

void actualizar() {
    int id;
    printf("ID: ");
    scanf("%d", &id);
    getchar();

    int idx = buscar_id(id);
    if (idx == -1) {
        printf("No encontrado.\n");
        return;
    }

    printf("Estado actual: %s\n", libros[idx].estado);
    printf("Nuevo estado (Disponible/Prestado): ");
    fgets(libros[idx].estado, 11, stdin);
    libros[idx].estado[strcspn(libros[idx].estado, "\n")] = 0;

    printf("Estado actualizado.\n");
}

void eliminar() {
    int id;
    printf("ID: ");
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

    printf("Libro eliminado.\n");
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