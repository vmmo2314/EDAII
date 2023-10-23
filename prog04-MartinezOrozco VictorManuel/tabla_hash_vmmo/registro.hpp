#ifndef REGISTRO_HPP_INCLUDED
#define REGISTRO_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int TAM_MAX_NOMBRE = 50;
const int TAM_MAX_TELEFONO = 20;
const int TAM_TABLA_INDICES = 100;

class Registro {
    private:
        int id;
        char nombre[TAM_MAX_NOMBRE];
        char telefono[TAM_MAX_TELEFONO];
    public:
        Registro() {
            id = -1;
            nombre[0] = '\0';
            telefono[0] = '\0';
        }
        int get_id() {
            return id;
        }
        char* get_nombre() {
            return nombre;
        }
        char* get_telefono() {
            return telefono;
        }
        void set_id(int nuevo_id) {
            id = nuevo_id;
        }
        void set_nombre(char* nuevo_nombre) {
            strcpy(nombre, nuevo_nombre);
        }
        void set_telefono(char* nuevo_telefono) {
            strcpy(telefono, nuevo_telefono);
        }
        void mostrar() {
            cout << "ID: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Telefono: " << telefono << endl;
        }
};

class Nodo {
    private:
        Registro* registro;
        Nodo* siguiente;
    public:
        Nodo() {
            registro = nullptr;
            siguiente = nullptr;
        }
        Registro* get_registro() {
            return registro;
        }
        Nodo* get_siguiente() {
            return siguiente;
        }
        void set_registro(Registro* nuevo_registro) {
            registro = nuevo_registro;
        }
        void set_siguiente(Nodo* nuevo_siguiente) {
            siguiente = nuevo_siguiente;
        }
};

#endif // REGISTRO_HPP_INCLUDED
