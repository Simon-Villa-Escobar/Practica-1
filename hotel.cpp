#include "hotel.h"

ListaHuespedes::ListaHuespedes() {
    primero = NULL;
    ultimo = NULL;
}
/*
ListaHuespedes::~ListaHuespedes() {
    Huesped* actual = primero;
    while (actual != NULL) {
        Huesped* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}*/

void ListaHuespedes::cargarHuesped(string nombre, int habitacion) {
    Huesped* nuevoHuesped = new Huesped();
    nuevoHuesped->nombre = nombre;
    nuevoHuesped->habitacion = habitacion;
    nuevoHuesped->siguiente = NULL;

    if (primero == NULL) {
        nuevoHuesped->anterior = NULL;
        primero = nuevoHuesped;
        ultimo = nuevoHuesped;
    }
    else {
        nuevoHuesped->anterior = ultimo;
        ultimo->siguiente = nuevoHuesped;
        ultimo = nuevoHuesped;
    }
}

void ListaHuespedes::imprimirHuespedes() {
    Huesped* actual = primero;
    while (actual != NULL) {
        cout << "Nombre: " << actual->nombre << ", Habitación: " << actual->habitacion << endl;
        actual = actual->siguiente;
    }
}

void ListaHuespedes::agregarHuesped(string nombre, int habitacion){
  Huesped* nuevoHuesped = new Huesped();
  nuevoHuesped->nombre = nombre;
  nuevoHuesped->habitacion = habitacion;
  nuevoHuesped->siguiente = NULL;
  nuevoHuesped->anterior = ultimo;
  ultimo->siguiente = nuevoHuesped;
  ultimo = nuevoHuesped;

  //Agregando el nuevo huesped en huespedes.txt
  ofstream archivo("huespedes.txt", ios::app);
    archivo << nombre << "\n" << habitacion<<"\n";
    archivo.close();
  
}

void ListaHuespedes::buscarHuespedNombre(string nombre){
  Huesped* actual = primero;
  while(actual != NULL){
    if (actual->nombre ==  nombre){
      cout<<nombre<<" está en la habitación: "<<actual->habitacion<<endl;
    }
    actual = actual->siguiente;
  }
}

void ListaHuespedes::buscarHuespedHabitacion(int habitacion){
  Huesped* actual = primero;
  while(actual!= NULL){
    if (actual->habitacion == habitacion){
      cout<<"El huesped que está en la habitación "<<habitacion<<" es: "<<actual->nombre<<endl;
    }
    actual = actual->siguiente;
  }
}

void ListaHuespedes::ordenarLista() {
    Huesped* sortedHead = NULL;
    Huesped* current = primero;
    while (current != NULL) {
        Huesped* newNode = new Huesped();
        newNode->nombre = current->nombre;
        newNode->habitacion = current->habitacion; // Asignar el número de habitación
        newNode->anterior = NULL;
        newNode->siguiente = NULL;
        if (sortedHead == NULL) {
            sortedHead = newNode;
        } else {
            Huesped* temp = sortedHead;
            while (temp != NULL) {
                if (newNode->nombre < temp->nombre) {
                    if (temp->anterior != NULL) {
                        temp->anterior->siguiente = newNode;
                        newNode->anterior = temp->anterior;
                    } else {
                        sortedHead = newNode;
                    }
                    temp->anterior = newNode;
                    newNode->siguiente = temp;
                    break;
                } else if (temp->siguiente == NULL) {
                    temp->siguiente = newNode;
                    newNode->anterior = temp;
                    break;
                }
                temp = temp->siguiente;
            }
        }
        current = current->siguiente;
    }
    Huesped* temp = sortedHead;
    while (temp != NULL) {
        cout << "Nombre: " << temp->nombre << ", Habitación: " << temp->habitacion << endl;
        temp = temp->siguiente;
    }
}






void ListaHuespedes::consultarVecinos(int habitacion){
  int ant = habitacion -1;
  int sig = habitacion + 1;
  Huesped* actual  = primero;
  bool a = true;
  bool b = true;
  while(actual != NULL){
    if(actual->habitacion == ant){
      cout<<"El vecino en la habitacion de antes es: "<<actual->nombre<<endl;
      a = false;
    }
    if(actual->habitacion == sig){
      cout<<"El vecino en la habitacion siguiente es: "<<actual->nombre<<endl;
      b = false;
    }
    actual = actual-> siguiente;
  }
  if(a == true){
    cout<<"No hay vecino en la habitacion de antes..."<<endl;
  }
  if(b == true){
    cout<<"No hay vecino en la habitacion siguiente..."<<endl;
  }

  
}
  


int ListaHuespedes::consultarHabitacion(int habitacion){
  int a = 0;
  bool b = false;
  bool c = false;
  int ant = habitacion - 1;
  int sig = habitacion + 1;
  Huesped* actual = primero;
  Huesped* ante = primero;
  Huesped* siguien = primero;
  while(actual!=NULL){
    if(actual->habitacion == habitacion){
      a = 4;
      while(ante!=NULL){
        if(ante->habitacion == ant){
          a = 1;
          b = true;
        }
        ante = ante->siguiente;
      }
      while(siguien!=NULL){
        if(siguien->habitacion == sig){
          a = 2;
          c = true;
        }
        siguien = siguien->siguiente;
      }
    }
    if(b==true && c == true){
      a = 3;
    }
    actual = actual->siguiente;
  }
  return a;
  /* a=0, el numero de habitacion esta disponible,
     a=1, la habitacion escogida y la anterior estan ocupadas
     a=2, la habitacion escogida y la siguiente estan ocupadas
     a=3, la habitacion escogida, la anterior y la siguiente estan ocupadas
     a=4, la habitacion escogida esta ocupada
  */
}
