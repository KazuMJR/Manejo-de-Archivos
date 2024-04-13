#include <iostream>
#include <dirent.h>
#include <cstdlib>
#include <fstream>

using namespace std;

// Variables
string ruta_archivo;
string nuevoruta_archivo;
string destino;

// Funciones prototipo
void identificador();
void list_dir(string dir);
void init();
void abrir();
void eliminar();
void renombrar();
void mover();

int main(int argc, char *argv[]){
    init();
    system ("pause");
    return 0;
}

// Función para ingresar ruta
void init(){
    string dir;
    int opcion;

    while (true) {
        cout << "Ruta del directorio a listar (o 'q' para salir): ";
        getline(cin, dir);

        if (dir == "q") {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        list_dir(dir);

        cout << "Seleccione la próxima acción:" << endl;
        cout << "Abrir archivo [1], Eliminar archivo [2], Renombrar archivo [3], Mover archivo [4], Listar otro directorio [5], Salir [q]" << endl;
        
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer del salto de línea

        switch (opcion) {
            case 1: abrir(); break;
            case 2: eliminar(); break;
            case 3: renombrar(); break;
            case 4: mover(); break;
            case 5: init(); return; // Volver al inicio del bucle
            default: cout << "Opción no válida. Por favor, intente de nuevo."<<endl;
        }
    }
}

// Función para listar archivos
void list_dir(string dir){
    DIR * directorio;
    struct dirent * elemento;
    string elem;
    if (directorio = opendir(dir.c_str()))
    {
        while ( elemento = readdir(directorio))
        {
            elem = elemento ->d_name;
            if (elem != "." && elem != "..")
                cout<< elem << endl;
        }
    }
    closedir(directorio);
}

// Función para abrir archivo
void abrir(){
    identificador();

    ifstream archivo(ruta_archivo);
    string linea, texto;
    while(getline(archivo, linea)){
        texto += linea + "\n";
    }
    cout << "Contenido del archivo:\n" << texto << endl;
}

// Función para eliminar archivo
void eliminar(){
    identificador();

    if (remove(ruta_archivo.c_str()) == 0) {
        cout << "Archivo eliminado correctamente." << endl;
    } else {
        cout << "Error al eliminar el archivo." << endl;
    }
}

// Función para renombrar un archivo
void renombrar(){
    identificador();

    cout << "Escriba el nuevo nombre del archivo: ";
    getline(cin, nuevoruta_archivo);

    if (rename(ruta_archivo.c_str(), nuevoruta_archivo.c_str()) == 0) {
        cout << "Archivo renombrado correctamente." << endl;
    } else {
        cout << "Error al renombrar el archivo." << endl;
    }
}

// Función para mover archivo
void mover(){
    identificador();
    cout << "Ingrese la ruta de destino: ";
    getline(cin, destino);

    if (rename(ruta_archivo.c_str(), destino.c_str()) == 0) {
        cout << "Archivo movido correctamente." << endl;
    } else {
        cout << "Error al mover el archivo." << endl;
    }
}

// Función para obtener la ruta del archivo
void identificador(){
    cout << "Escriba la ruta del archivo: ";
    getline(cin, ruta_archivo);
}
