#include "menuA.hpp"


BTree<alumno> MyArbol;
alumno myAlumno;

void Menu::mainMenu()
{
string salir;
do{
    cout << "************Arbol de alumnos************" << endl;
    int opc;
    cout << "Selecciona una opcion: " <<endl;
    cout << "1)insertar al arbol            2)muestreo de valores" << endl;
    cout << "3)mostrar elemento mayor       4)mostrar elemento menor" << endl;
    cout << "5)mostrar altura               6)eliminar todo" << endl;
    cout << "7)guardar en archivo           8)cargar desde archivo" <<endl;
    cout << "9)eliminar dato                10)Ver padre" <<endl;
    cout << "11)Salir" <<endl;

    cin>>opc;
        switch(opc){
            case 1: {
            string Nalumno, CodeAlumno, CareerAlumno;
            system("cls");
            cout <<"Digita el nombre del alumno: "; cin>>Nalumno;
            myAlumno.setNombre(Nalumno);
            cout <<"Digita el codigo del alumno: "; cin>>CodeAlumno;
            myAlumno.setCodigo(CodeAlumno);
            cout <<"Digita la carrera del alumno: "; cin>>CareerAlumno;
            myAlumno.setCarrera(CareerAlumno);
            MyArbol.insertData(myAlumno);
            cout << "Dato ingresado: " << myAlumno.toStringSinSeparadores()<< " al arbol." <<endl;
            system("pause"); system("cls");
            }break;

            case 2:{
            int op;
            cout << "preorder [1] \n inorder [2] \n postorder[3]" <<endl; cin>>op;
            system("cls");

            switch(op){
                case 1: {
                    if(MyArbol.isEmpty()){
                        cout << "Arbol vacio, intenta insertar datos" <<endl;
                        break;
                    }
                    else{
                        cout<< "Muestreo de los valores en PreOrder: " <<endl;
                        MyArbol.parsePreOrder();
                    }
                }break;

                case 2: {
                    if(MyArbol.isEmpty()){
                        cout << "Arbol vacio, intenta insertar datos" <<endl;
                        break;
                    }
                    else{
                    cout<< "Muestreo de los valores en InOrder: " <<endl;
                    MyArbol.parseInOrder();
                    }
                }break;

                case 3: {
                    if(MyArbol.isEmpty()){
                        cout << "Arbol vacio, intenta insertar datos" <<endl;
                        break;
                    }
                    else{
                    cout<< "Muestreo de los valores en PostOrder: " <<endl;
                    MyArbol.parsePostOrder();
                    }
                }break;
            }
            system("pause"); system("cls");
            }break;

            case 3: {
            system("cls");
            cout <<"El elemento mayor del arbol es: "<< MyArbol.retrieve(MyArbol.getHighest()).toStringSinSeparadores()<<endl;
            system("pause"); system("cls");
            }break;

            case 4: {
            system("cls");
            cout <<"El elemento menor del arbol es: "<< MyArbol.retrieve(MyArbol.getLowest()).toStringSinSeparadores()<<endl<<endl;
            system("pause"); system("cls");
            }break;

            case 5: {
            ///Altura segun el arbol
            int op;
            system("cls");
            cout << "Altura de arbol... \n derecho [1] \n izquierdo [2]?" <<endl; cin>>op;
                if(op == 1){
                system("cls");
                cout <<"La altura correspondiente al subarbol derecho respecto de la raiz es: "<<MyArbol.getHeight(MyArbol.getRoot()->getRight())<<endl; ///recibe la dirección desde donde partirá para obtener la altura
                }
                else{
                cout <<"La altura correspondiente al subarbol izquierdo respecto de la raiz es: "<<MyArbol.getHeight(MyArbol.getRoot()->getLeft())<<endl;
                }
            system("pause"); system("cls");
            }break;

            case 6: {
            ///Eliminar todo el arbol
            system("cls");
                if(MyArbol.isEmpty()){
                    cout<<"El arbol se encuentra vacio..."<<endl;
                    system("pause"); system("cls");
                }
            cout<< "Eliminando todo el contenido del arbol..." <<endl;
            MyArbol.deleteAll();
            system("pause"); system("cls");
            cout << "Eliminado :)"<<endl;
            system("pause"); system("cls");
            }break;

            case 7:{
            MyArbol.guardarArchivo();
            cout << "Datos guardados exitosamente..." <<endl;
            system("pause"); system("cls");
            }break;

            case 8:{
            MyArbol.cargarArchivo();
            cout << "Datos cargados exitosamente..." <<endl;
            system("pause"); system("cls");
            }break;

            case 9:{
            ///eliminacion
            string n;
            alumno a;
            cout << "Digita el nombre del alumno a eliminar: " <<endl;
            cin>>n;
            a.setNombre(n);
            MyArbol.eliminarDato(a);
            system("pause"); system("cls");
            }break;

            case 10:{
            ///ver padre
            string n;
            alumno a;
            cout << "Digita un nombre de referencia:" <<endl;
            cin>>n;
            a.setNombre(n);
            MyArbol.verPadre(a);
            system("pause"); system("cls");
            }break;

            case 11:{
            salir = "adios";
            }break;

            default: {
            cout << "opcion invalida... :(" <<endl;
            }
        }
    }while(salir != "adios");
}
