#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void guardarRegistro(int diaE, int mesE, int anioE, int diaEnt, int mesEnt, int anioEnt) {
    ofstream archivo("registros.csv", ios::app);

    if(archivo.is_open()) {
        archivo << diaE << "/" << mesE << "/" << anioE << ";"
                << diaEnt << "/" << mesEnt << "/" << anioEnt << endl;
        archivo.close();
        cout << "Registro guardado correctamente" << endl;

    } else {
        cerr << "Error: no se pudo abrir el archivo." << endl;
    }
}

void mostrarRegistros() {
    ifstream archivo("registros.csv");
    string linea;
    int contador = 1;

    cout << "------ Registros guardados ------" << endl;
    while (getline(archivo, linea)) {
        cout << contador << ". " << linea << endl;
        contador++;
    }
    archivo.close();    
}

int main() {
    int day = 0;
    int moth = 0;
    int year = 0;

    //Variables para la fecha de entrega
    

    cout << "Ingresa el dia de hoy: " << endl;
    cin >> day;
    cout << "Ingresa el mes actual: " << endl;
    cin >> moth;
    cout << "Ingresa el anio actual: " << endl;
    cin >> year;

    int mesEntrada = moth + 1;
    int diaEntrega = day;
    int anioEntrega = year;
    int maxDias = 31;

    if(mesEntrada > 12) {
        mesEntrada = 1;
        anioEntrega++;
    }

    if(diaEntrega > 31) {
        diaEntrega = maxDias;
    }

    
    cout << endl;

    cout << "Fecha de salida: " << day << "-" << moth << "-" << year << endl;
    cout << "Fecha de entrega: " << diaEntrega << "-" << mesEntrada << "-" << anioEntrega << endl;


    guardarRegistro(day, moth, year, diaEntrega, mesEntrada, anioEntrega);

    return 0;
}