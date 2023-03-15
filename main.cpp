
//Practica 1 de Juan Diego Tamayo y Simon Villa Escobar

#include "hotel.h"

int main() {
    ListaHuespedes listaHuespedes;

    string nombre;
    int habitacion;

    

  ifstream archivoHuespedes("huespedes.txt");
  
  while (getline(archivoHuespedes, nombre) && archivoHuespedes >> habitacion) {
    listaHuespedes.cargarHuesped(nombre, habitacion);
    archivoHuespedes.ignore(); // ignorar el salto de línea después del número de habitación
}


    archivoHuespedes.close();
  bool m = true;
  int d;
  while(m == true){
    cout<<"\n";
    cout<<"1. Agregar un huesped"<<endl;
    cout<<"2. Buscar un huesped por el nombre"<<endl;
    cout<<"3. Buscar un huesped por su habitacion"<<endl;
    cout<<"4. Mostrar la lista de huespedes en orden alfabetico"<<endl;
    cout<<"5. Mostrar la lista de huespedes en orden de llegada"<<endl;
    cout<<"6. Consultar las vecinos"<<endl;
    cout<<"7. Salir"<<endl;
    cin>>d;

    if(d == 1){    //Agregar un huesped
      string n;
      cout<<"Cual es tu nombre?"<<endl;
      cin>>n;
      bool dc = true;
      while (dc == true){
        int h;
        cout<<"Que habitacion deseas?"<<endl;
        cin>>h;
        int ha;
        ha = listaHuespedes.consultarHabitacion(h);
        bool hab = true;
        while (hab == true){
          if(ha == 0){
           
            listaHuespedes.agregarHuesped(n, h);
            hab = false;
            dc = false;
          }
          if(ha==4){
            int dh;
            cout<<"La habitacion esta ocupada, quieres: 1.la habitacion anterior ("<<(h-1)<<"), 2.la habitacion siguiente ("<<(h+1)<<") o 3.deseas elegir otra habitacion?"<<endl;
            cin>>dh;
            if(dh == 1){
              
              listaHuespedes.agregarHuesped(n, (h-1));
              hab = false;
              dc = false;
            }
            if(dh == 2){
              
              listaHuespedes.agregarHuesped(n, (h+1));
              hab = false;
              dc = false;
              
            }
            if(dh == 3){
              hab = false;
            }
          }
          if(ha == 1){
            int dh;
            cout<<"La habitacion esta ocupada, quieres: 1. La habitacion siguiente ("<<(h+1)<<") o 2.Quieres escoger otra habitacion?"<<endl;
            cin>>dh;
            if(dh==1){
              listaHuespedes.agregarHuesped(n, (h+1));
              hab = false;
              dc = false;
              
            }
            if(dh==2){
              hab = false;
            }
          }
          if(ha==2){
            int dh;
            cout<<"La habitacion esta ocupada, quieres: 1.La habitacion anterior("<<(h-1)<<") o 2.Quieres escoger otra habitacion?"<<endl;
            cin>>dh;
            if(dh==1){
              listaHuespedes.agregarHuesped(n, (h-1));
              hab = false;
              dc = false;
              
            }
            if (dh == 2){
              hab = false;
            }
          }
          if(ha == 3){
            cout<<"La habitacion elegida, la anterior y la siguiente estan ocupadas. Elije otra habitacion"<<endl;
            hab = false;
          }
        }
      }
    }

    
    if(d==2){    //Buscar un huesped por el nombre
      string n;
      cout<<"Como se llama el huesped que estas buscando?"<<endl;
      cin>>n;
      listaHuespedes.buscarHuespedNombre(n);
      
    }

    if(d==3){    //Buscar un huesped por la habitacion
      int h;
      cout<<"En cual habitacion esta el huesped que estas buscando?"<<endl;
      cin>>h;
      listaHuespedes.buscarHuespedHabitacion(h);
    }
    if(d==4){    //Lista de los huespedes en orden alfabetico
      listaHuespedes.ordenarLista();
    }

    if(d==5){    //Lista de los huespedes en orden de llegada
      listaHuespedes.imprimirHuespedes();
    }

    if(d==6){    //Consultar los vecinos
      int h;
      cout<<"De cual habitacion deseas consultar los vecinos?"<<endl;
      cin>>h;
      listaHuespedes.consultarVecinos(h);
    }

    if(d==7){    //Salir del menu
      cout<<"Hasta luego!"<<endl;
      m = false;
    }  
  }
    return 0;
}
