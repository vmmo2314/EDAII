#ifndef TABLA_INDICES_HPP_INCLUDED
#define TABLA_INDICES_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>

#include "registro.hpp"

class TablaIndices {
    private:
        Nodo* tabla[TAM_TABLA_INDICES];
    public:
        TablaIndices() {
            for (int i = 0; i < TAM_TABLA_INDICES; i++) {
                tabla[i] = NULL;
            }
        }
        int funcion_hash(int id) {
            return id % TAM_TABLA_INDICES;
        }
        void insertar(Registro* registro) {
            int posicion = funcion_hash(registro->get_id());
            Nodo* nuevo_nodo = new Nodo();
            nuevo_nodo->set_registro(registro);
            if (tabla[posicion] == NULL) {
                tabla[posicion] = nuevo_nodo;
            } else {
                Nodo* actual = tabla[posicion];
                while (actual->get_siguiente() != NULL) {
                    actual = actual->get_siguiente();
                }
                actual->set_siguiente(nuevo_nodo);
            }
        }
        Nodo* buscar(int id) {
            int posicion = funcion_hash(id);
            Nodo* actual = tabla[posicion];
            while (actual != NULL) {
                if (actual->get_registro()->get_id() == id) {
                    return actual;
                }
                actual = actual->get_siguiente();
            }
            return NULL;
        }
        void mostrar() {
            for (int i = 0; i < TAM_TABLA_INDICES; i++) {
                Nodo* actual = tabla[i];
                while (actual != NULL) {
                    actual->get_registro()->mostrar();
                    actual = actual->get_siguiente();
                }
            }
        }
        void guardar_en_archivo() {
            ofstream archivo("file01", ios::binary);
            if (archivo.is_open()) {
                for (int i = 0; i < TAM_TABLA_INDICES; i++) {
                    Nodo* actual = tabla[i];
                    while (actual != NULL) {
                        Registro* reg = actual->get_registro();
                        archivo.write(reinterpret_cast<char*>(reg), sizeof(Registro));
                        actual = actual->get_siguiente();
                    }
                }
                archivo.close();
                cout << "Informacion guardada en archivo binario exitosamente." << endl;
            } else {
                cout << "Error al abrir archivo." << endl;
            }
        }
        void cargar_desde_archivo() {
            ifstream archivo("file01", ios::binary);
            if (archivo.is_open()) {
                Registro reg;
                while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) {
                    insertar(new Registro(reg));
                }
                archivo.close();
                cout << "Informacion cargada desde archivo binario exitosamente." << endl;
            } else {
                cout << "Error al abrir archivo." << endl;
            }
        }
};

#endif // TABLA_INDICES_HPP_INCLUDED
