#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Huesped {    //El nodo
    string nombre;
    int habitacion;
    Huesped* siguiente;
    Huesped* anterior;
};

class ListaHuespedes {
private:
    Huesped* primero;
    Huesped* ultimo;
public:
    ListaHuespedes();
    //~ListaHuespedes();
    void cargarHuesped(string nombre, int habitacion);
    void imprimirHuespedes();
    void agregarHuesped(string nombre, int habitacion);
    void buscarHuespedNombre(string nombre);
    void buscarHuespedHabitacion(int habitacion);
    void ordenarLista();
    void consultarVecinos(int habitacion);
    int consultarHabitacion(int habitacion);
    
};

#endif // HOTEL_H
