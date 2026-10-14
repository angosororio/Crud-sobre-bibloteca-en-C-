#include <iostream>
using namespace std;

int main() {

    int opcion = 0;
    string nombreLibros;
    int costoLibros = 0;

    int day = 0;
    int moth = 0;
    int year = 0;

    cout << "==============================\n";
    cout << "     GESTION DE REGISTROS     \n";
    cout << "==============================\n";
    cout << " [1] Crear registro del libro\n";
    cout << " [2] Listas de registros\n";
    cout << " [3] Editar registros\n";
    cout << " [4] Eliminar registros\n";
    cout << " [0] Salir\n";
    cout << "------------------------------\n";
    cout << " Elige una opcion: \n";
    cin >> opcion;

    switch (opcion)
    {
        case 1: 
        cin.ignore();
        cout << "Ingresa el nombre del libro: " << endl;
                getline(cin, nombreLibros);
                cout << "Ingresa el costo del libro: " << endl;
                cin  >> costoLibros;
                cout << "A continuacion agregaras la fecha: " << endl;
                cout << "Ingresa el dia de hoy: " << endl;
                cin >> day;
                cout << "Ingresa el mes " << endl;
                cin >> moth;
                cout << "Ingresa el anio: " << endl;
                cin >> year;

                
                

    }

    cout << "===============================================" << endl;
    cout << "=                   REGISTRO DE LIBROS         =" << endl;
    cout << "===============================================" << endl;

    cout << "Nombre del Libro: " << nombreLibros << endl;
    cout << "Costo del libro:  " << costoLibros << endl;
    cout << "Fecha:            "<< day << "-"<< moth << "-" <<  year << endl;

    return 0;
}