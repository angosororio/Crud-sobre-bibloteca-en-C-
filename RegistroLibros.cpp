#include <iostream>
#include <vector> //Esta libreria permite usar vectores
#include <string>
#include <limits>
#include <fstream> //Esta libreria permite utilizar archivos
#include <sstream> //Esta libreria permite manipular cadenas de texto
#include <stdexcept>//Esta libreira sirve para manejar errores
using namespace std;

struct Libro //Esto es la estructura del Libro
{
    int id;
    string titulo;
    string autor;
    int dia; //Este es el dia en que fue registrado
    int mes; //Este es el mes en que fue registrado
    int anio; //Este es el año en que fue registrado
};

string rutaArchivoRegistros() { //rutaArchivosRegistros obtiene la ruta de donde esta ubicado el archivo "registros.csv"
    ifstream archivoLocal("registros.csv");
    if (archivoLocal.is_open()) {
        return "registros.csv";
    }

    ifstream archivoOutput("output\\registros.csv");
    if (archivoOutput.is_open()) {
        return "output\\registros.csv";
    }

    return "registros.csv";
}

void agregarLibro(vector<Libro>& bibloteca) { //Esta funcion tiene la tarea de. Registrar el libro con su respectiva informacion.
    Libro nuevoLibro;

    
    cout << "============ Registra Nuevo Libro =============" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    nuevoLibro.id = bibloteca.size() + 1; //Esta parte le asigna un Id aleatorio sumando 1 al Id que ya estaba para permiter que los ID no se repitan.

    cout << "Ingresa el titulo del libro: " << endl;
    getline(cin, nuevoLibro.titulo); //getline: Permite leer informacion con espacios y textos largos.

    cout << "Ingresa el autor del libro: " << endl;
    getline(cin, nuevoLibro.autor);

    cout << "Ingresa el dia del registro: " << endl;
    cin >> nuevoLibro.dia;

    cout << "Ingresa el mes del registro: " << endl;
    cin >> nuevoLibro.mes;

    cout << "Ingresa el anio del mes: " << endl;
    cin >> nuevoLibro.anio;

    bibloteca.push_back(nuevoLibro); // Al finalizar de ingresar la informacion .push_back() Ingresa toda la informacion del libro al VECTOR.
    cout << "Libro registrado exitosamente con ID " << nuevoLibro.id << endl; //Aqui se muestra el ID que tiene el libro.

    ofstream archivoRegistros(rutaArchivoRegistros(), ios::app);

    if(!archivoRegistros.is_open()) {
        cout << "Error al abrir el archivo:" << endl;
        return;
    }

    archivoRegistros << nuevoLibro.id << "," //En esta parte, el libro se ingresa al archivo registros.csv. Como un registro.
                     << nuevoLibro.titulo << ","
                     << nuevoLibro.autor << ","
                     << nuevoLibro.dia << ","
                     << nuevoLibro.mes << ","
                     << nuevoLibro.anio << endl;

                     archivoRegistros.close();

                     cout << "Estudiante guardado correctamente" << endl;

}


void mostrarLibros(const vector<Libro>& bibloteca) { //Esta funcion muestra todos los libros que han sido ingresados.
    cout << "\n========================================\n";
    cout << "          LISTA DE LIBROS               \n";
    cout << "========================================\n";

    if(bibloteca.empty()) { //Si no hay libro muestra un mensaje.
        cout << "No hay registros de libros " << endl;
        return;
    }

    for (const auto& Libro : bibloteca) { //Este for, recorre la bibloteca y muestra cada uno de sus libros almacenados en el vector.
        cout << "ID: " << Libro.id << endl;
        cout << "Titulo " << Libro.titulo << endl;
        cout << "Autor " << Libro.autor  << endl;
        cout << "Fecha " << Libro.dia << "-" << Libro.mes << "-" << Libro.anio << endl;

        cout << endl;
        cout << endl;
        }
}

void cargarDatos(vector<Libro>& bibloteca) { //void cargarDatos obtiene los datos del archivo (registros.csv) y los limpia y los introduce a el vector<Libro>
    //Esto ocurre cuando el programa se inicia o el programa se cierra y se vuelve abrir la funcion realiza su trabajo.
    ifstream archivoRegistros(rutaArchivoRegistros());

    if(!archivoRegistros.is_open()) {
        std::cout << "No se encontro el archivo" << endl;
        return;
    }

    string linea;
    int numeroLinea = 0;

    while (getline(archivoRegistros, linea))
    {
        ++numeroLinea;
        stringstream ss(linea);
        string idTexto, tituloNombre, autorNombre, diaTexto, mesTexto, anioTexto;

        if (!getline(ss, idTexto, ',') ||
            !getline(ss, tituloNombre, ',') ||
            !getline(ss, autorNombre, ',') ||
            !getline(ss, diaTexto, ',')) {
            cout << "Registro invalido en la linea " << numeroLinea << endl;
            continue;
        }

        if (getline(ss, mesTexto, ',')) {
            if (!getline(ss, anioTexto, ',')) {
                cout << "Registro invalido en la linea " << numeroLinea << endl;
                continue;
            }
        } else {
           
            if (diaTexto.length() != 8) {
                cout << "Fecha invalida en la linea " << numeroLinea << endl;
                continue;
            }
            mesTexto = diaTexto.substr(2, 2);
            anioTexto = diaTexto.substr(4, 4);
            diaTexto = diaTexto.substr(0, 2);
        }

        try {
            Libro libro;
            libro.id = stoi(idTexto);
            libro.titulo = tituloNombre;
            libro.autor = autorNombre;
            libro.dia = stoi(diaTexto);
            libro.mes = stoi(mesTexto);
            libro.anio = stoi(anioTexto);
            bibloteca.push_back(libro);
        } catch (const invalid_argument&) {
            cout << "Datos invalidos en la linea " << numeroLinea << endl;
        } catch (const out_of_range&) {
            cout << "Datos fuera de rango en la linea " << numeroLinea << endl;
        }
    }
}

void EditarLibros(vector<Libro>& bibloteca) {
    ifstream archivoRegistros(rutaArchivoRegistros());
    int idBuscar;

    cout << "Ingresa el ID del libro que deseas editar: "; //Se ingresa el Id del libro que quieres editar.
    cin >> idBuscar;


    for(int i = 1; i < bibloteca.size(); i++) {

        if(bibloteca[i].id != idBuscar) {
             cout << "El ID no fue encontrado" << endl;
             return;
             cout << endl;
        }

        if(bibloteca[i].id == idBuscar) {
            cout << "==== Libro encontrado ====" << endl;
            cout << "Nombre del libro: " << bibloteca[i].titulo << endl;
            cout << "Autor: " << bibloteca[i].autor << endl;
            cout << "Fecha: " << bibloteca[i].dia << "-" << bibloteca[i].mes << "-" << bibloteca[i].anio << endl;
            cout << endl;
            cout << endl;

            cout << "Ingresa el nuevo titulo: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, bibloteca[i].titulo);

            cout << "Ingresa el nombre del autor: " << endl;
            getline(cin, bibloteca[i].autor);

            cout << "Ingresa el dia: " << endl;
            cin >> bibloteca[i].dia;

            cout << "Ingresa el mes: " << endl;
            cin >> bibloteca[i].mes;

            cout << "Ingresa el anio: " << endl;
            cin >> bibloteca[i].anio;

        }

        if(!archivoRegistros.is_open()) {
            cout << "Error al actualizar el archivo." << endl;
            return;
        }

        for(const auto& Libro : bibloteca) {
            cout << "ID: " << Libro.id << endl;
            cout << "Titulo " << Libro.titulo << endl;
            cout << "Autor " << Libro.autor  << endl;
            cout << "Fecha " << Libro.dia << "-" << Libro.mes << "-" << Libro.anio << endl;

            archivoRegistros.close();

        cout << "Registro actualizado correctamente: " << endl;
        return;
        }
    } 
     
}

void ElimarLibros(vector<Libro>& bibloteca) {

     ifstream archivoRegistros(rutaArchivoRegistros());
     int IdEliminar;
     int confrimacion;
     

    if(!archivoRegistros.is_open()) {
        cout << "No se encontro el archivo" << endl;
        return;
    }

    cout << "Ingresa el Id del libro que quieras eliminar" << endl;
    cin >> IdEliminar;

    for(int i = 0; i < bibloteca.size(); i++) {

        if(bibloteca[i].id != IdEliminar) {
             cout << "El ID no fue encontrado" << endl;
             return;
             cout << endl;
        }

        if(bibloteca[i].id == IdEliminar) {
            cout << "==== Libro encontrado ====" << endl;
            cout << "Nombre del libro: " << bibloteca[i].titulo << endl;
            cout << "Autor: " << bibloteca[i].autor << endl;
            cout << "Fecha: " << bibloteca[i].dia << "-" << bibloteca[i].mes << "-" << bibloteca[i].anio << endl;
            cout << endl;
            cout << endl;
        }

        cout << "Estas seguro de eliminar este libro: " << endl; // N = no y S = si
        cout << "1] Si" << endl;
        cout << "2] NO" << endl;
        cin >> confrimacion;

           if(confrimacion  == 1) {
              bibloteca.erase(bibloteca.begin() + i);

              ofstream archivoRegistros("registros.csv"); 

              if(!archivoRegistros.is_open()) {
                cout << "Error al actualizar el archivo" << endl;
                return;
              }

              for(const auto& Libro : bibloteca) {
                archivoRegistros << Libro.id << ","
                                 << Libro.titulo << ","
                                 << Libro.autor << ","
                                 << Libro.dia << "-" << Libro.mes << "-" << Libro.anio << endl;
              }

              archivoRegistros.close();

              cout << "Libro eliminado correctamente" << endl;

              cout << endl;
              cout << endl;

            }

          if(confrimacion == 2) {
            cout << "Eliminacion cancelada" << endl;
            return ;
            }
}
}


int main() {
    vector <Libro> bibloteca;
    int opcion = 0;
    cargarDatos(bibloteca);

    do{
    cout << "==============================\n";
    cout << "     GESTION DE REGISTROS     \n";
    cout << "==============================\n";
    cout << " [1] Crear registro del libro\n";
    cout << " [2] Listas de registros\n";
    cout << " [3] Editar registros\n";
    cout << " [4] Eliminar registros\n";
    cout << " [5] Salir\n";
    cout << "------------------------------\n";
    cout << " Elige una opcion: \n";
    cin >> opcion;

    switch (opcion)
    {
        
        case 1: 
        system("cls");
        agregarLibro(bibloteca); break;

        case 2: 
        mostrarLibros(bibloteca); break;

        case 3:
        EditarLibros(bibloteca); break;

        case 4:
        ElimarLibros(bibloteca); break;
        
        case 5: cout << "Saliendo del programa "; break;
    }
    
    } while (opcion != 5);
      
    return 0;
}