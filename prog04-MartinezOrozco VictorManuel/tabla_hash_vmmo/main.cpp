#include <iostream>

#include "registro.hpp"
#include "tabla_indices.hpp"

using namespace std;

int main() {
    TablaIndices tabla_indices;
    int opcion;
    do {
        cout << "Menu:" << endl;
        cout << "1) Nuevo registro \n2) Buscar registro   \n3) Mostrar Registro \n4) Guardar en archivo" <<endl;
        cout << "5) Cargar de archivo\n6) Salir"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1: {
                Registro* nuevo_registro = new Registro();
                int nuevo_id;
                char nuevo_nombre[TAM_MAX_NOMBRE];
                char nuevo_telefono[TAM_MAX_TELEFONO];
                cout << "Ingrese el ID del registro: ";
                cin >> nuevo_id;
                nuevo_registro->set_id(nuevo_id);
                cout << "Ingrese el nombre del registro: ";
                cin.ignore();
                cin.getline(nuevo_nombre, TAM_MAX_NOMBRE);
                nuevo_registro->set_nombre(nuevo_nombre);
                cout << "Ingrese el teléfono del registro: ";
                cin.getline(nuevo_telefono, TAM_MAX_TELEFONO);
                nuevo_registro->set_telefono(nuevo_telefono);
                tabla_indices.insertar(nuevo_registro);
                cout <<"Usuario: "<< nuevo_nombre <<" registrado exitosamente..."<<endl;
                system("pause");
                break;
            }
            case 2: {
                int id_buscar;
                cout << "Ingrese el ID del registro a buscar: ";
                cin >> id_buscar;
                Nodo* nodo_encontrado = tabla_indices.buscar(id_buscar);
                if (nodo_encontrado != NULL) {
                    nodo_encontrado->get_registro()->mostrar();
                } else {
                    cout << "Registro no encontrado" << endl;
                }
                system("pause");
                break;
            }
            case 3: {
                tabla_indices.mostrar();
                system("pause");
                break;
            }
            case 4: {
                cout << "Guardando en archivo" << endl;
                tabla_indices.guardar_en_archivo();
                system("pause");

                break;
            }
            case 5: {
                cout << "Cargando desde archivo" << endl;
                tabla_indices.cargar_desde_archivo();
                system("pause");

                break;
            }
            default: {
                cout << "Opcion invalida" << endl;
                system("pause");
                break;
            }
        }
        system("cls");
    } while(opcion != 4);

    return 0;
}
