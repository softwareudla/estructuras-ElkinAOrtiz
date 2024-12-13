#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 20

struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[11];
};


void agregar();
void mostrar_libros();
void buscar();
void actualizar();
void eliminar();
int buscar_id(int id);
int id_unico(int id);

#endif