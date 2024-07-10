#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <fstream>  
#include <sstream> 
#include <windows.h>

using namespace std;
const int max_historial_size = 100;  
// Registro de usuarios//
struct Usuario {string Nombre;string Cargo;string contra;};
Usuario trabajador1 = {"STEVIE", "OPERADOR N�1", "123"};
Usuario trabajador2 = {"USHER", "OPERADOR N�1", "456"};
Usuario trabajador3 = {"SEBASTIAN", "OPERADOR N�2", "789"};
Usuario trabajador4 = {"JIMMY", "OPERADOR N�2", "159"};
Usuario trabajador5 = {"HAYDEE", "ADMINISTRADOR", "753"};
// Definici�n de la estructura para almacenar la informaci�n de las gasolinas
struct Gasolina {int codigo;string nombre;double precio;int cantidad;string tipo;bool activo;};
//Definici�n de la estructura del Historial
struct Historial {string usuario;string accion;int codigoProducto;
// Funci�n para guardar el historial en un archivo
void guardarHistorial(ofstream& archivo) const {
        archivo << usuario << "," << accion << "," << codigoProducto << "\n";}};// Funci�n para mostrar el men� de inserci�n y manejar la entrada del usuario
void mostrarMenuinsertar(Gasolina gasolinas[], int& size, Historial historial[], int& historial_size, const string& usuario) {
    int opcion;
    do {
    	system("cls"); 
		cout << "|-----------------------------|" << endl;
		cout << "|      MENU DE OPCIONES:      |" << endl;
		cout << "|-----------------------------|" << endl;
        cout << "|  1. INSERTAR NUEVO PRODUCTO |" << endl;
        cout << "|  2. ";
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
		cout << "SALIR";
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
		cout <<"                  |" << endl;
        cout << "|-----------------------------|" << endl;
        cout << "Ingrese su opci�n: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string op = "S";
                do {
                	system("cls");
                    Gasolina nuevaGasolina;
                    cout<< " ------------------------------------- "<<endl;
                    cout<< "|Ingrese el c�digo del nuevo producto: |";cin >> nuevaGasolina.codigo;
                    cout<< "|Ingrese el nombre del nuevo producto: |";cin.ignore(); // Ignorar el salto de l�nea anterior
                    getline(cin, nuevaGasolina.nombre);
                    cout <<"|Ingrese el precio del nuevo producto: |";cin >> nuevaGasolina.precio;
                    cout <<"|Ingrese la cantidad:                  |";cin >> nuevaGasolina.cantidad;
                    cout <<"|Ingrese el tipo del nuevo producto:   |";cin.ignore(); // Ignorar el salto de l�nea anterior
                    getline(cin, nuevaGasolina.tipo);
                    gasolinas[size] = nuevaGasolina;
                    size++;
                     // Agregar al historial
                    historial[historial_size].usuario = usuario;
                    historial[historial_size].accion = "INSERTAR";
                    historial[historial_size].codigoProducto = nuevaGasolina.codigo;
                    historial_size++;
                    cout << "�Desea insertar otro nuevo producto? (S/N): ";
                    cin >> op;
                    
                } while (op == "S" || op == "s");
                break;
            }
            case 2: {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
                cout << "Saliendo del sistema...\n";
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
                return;}
            default: {cout << "Opci�n no v�lida. Int�ntelo de nuevo.\n";break;}
        }
    } while (true);
}
void RegistroTotal(const Gasolina gasolinas[], int size) {
    cout << "Registro Total de Gasolinas:\n";
    cout << "+-----------------------------------------------------------------------------------------+\n";
    cout << "| C�digo |        Nombre                      | Precio | Cantidad |     Tipo     | Activo |\n";
    cout << "+-----------------------------------------------------------------------------------------+\n";
    for (int i = 0; i < size; ++i) {
        cout << "| " << setw(6) << gasolinas[i].codigo << " | "
             << setw(30) << gasolinas[i].nombre.substr(0, 30) << " | "
             << setw(6) << fixed << setprecision(2) << "S/" << gasolinas[i].precio << " | "
             << setw(8) << gasolinas[i].cantidad << " | "
             << setw(12) << gasolinas[i].tipo.substr(0, 12) << " | "
             << setw(6) << (gasolinas[i].activo ? "Si" : "No") << " |\n";
    }
    cout << "+-----------------------------------------------------------------------------------------+\n";
}

// Funci�n para buscar gasolina por c�digo
void buscarPorCodigo(const Gasolina gasolinas[], int size, int codigo) {
    system("cls");
    bool encontrado = false;
    for (int i = 0; i < size; ++i) {
        if (gasolinas[i].codigo == codigo) {
            cout << "C�digo  : " << gasolinas[i].codigo << "\n"
                 << "Nombre  : " << gasolinas[i].nombre << "\n"
                 << "Precio  : " <<"S/" << gasolinas[i].precio << "\n"
                 << "Cantidad: " << gasolinas[i].cantidad<<" "<<gasolinas[i].tipo << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
    	cout << "No se encontr� gasolina con el c�digo " << codigo << ".\n";
    	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
    }
    cout << "\n--- Registro Total ---\n";
    RegistroTotal(gasolinas, size); // Llamar a la funci�n que muestra el registro total
    getch();
    system("cls");
}

// Funci�n para buscar gasolina por nombre
void buscarPorNombre(const Gasolina gasolinas[], int size, const string& nombre) {
    system("cls");
    bool encontrado = false;
    for (int i = 0; i < size; ++i) {
        if (gasolinas[i].nombre == nombre) {
            cout << "C�digo  : " << gasolinas[i].codigo << "\n"
                 << "Nombre  : " << gasolinas[i].nombre << "\n"
                 << "Precio  : " <<"S/" << gasolinas[i].precio << "\n"
                 << "Cantidad: " << gasolinas[i].cantidad<<" "<<gasolinas[i].tipo << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) {
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
    	cout << "No se encontr� gasolina con el nombre " << nombre << ".\n";
    	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
    }
    cout << "\n--- Registro Total ---\n";
    RegistroTotal(gasolinas, size); // Llamar a la funci�n que muestra el registro total
    getch();
    system("cls");
}
// Funci�n para mostrar el men� y manejar la entrada del usuario
void mostrarMenu(Gasolina gasolinas[], int size) {
    system("cls");
    int opcion;
    do {
        cout << "-----------------------" << endl;
        cout << "|   Menu de opciones  |" << endl;
        cout << "|---------------------|" << endl;
        cout << "|1.| Buscar por c�digo|" << endl;
        cout << "|2.| Buscar por nombre|" << endl;
        cout << "|3.|";
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
		cout <<" Salir";
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
		cout <<"            |" << endl;
        cout << "|---------------------|" << endl;
        cout << "Ingrese su opci�n: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1: {int codigo;cout << "Ingrese el c�digo: ";cin >> codigo;buscarPorCodigo(gasolinas, size, codigo);break;}
            case 2: {string nombre;cout << "Ingrese el nombre: ";cin.ignore(); // Para ignorar el salto de l�nea anterior
                     getline(cin, nombre);
				     buscarPorNombre(gasolinas, size, nombre);break;}
            case 3:cout << "Saliendo del sistema...\n";system("cls");return;
            default:cout << "Opci�n no v�lida. Int�ntelo de nuevo.\n";}
        cout << "\n";
    } while (true);
}
//funcion para una actualizacion del precio y la cantidad
void actualizacion(Gasolina gasolinas[], int size, Historial historial[], int& historial_size, const string& usuario)
{
    int m1, m2, venta, p,codigo;
	system("cls");
	cout<<"el codigo es:";cin>>codigo;
	system("cls");
    for (int i = 0; i < size; ++i)
    {
        if (gasolinas[i].codigo == codigo)
        {
            cout << "|-------------------------|\n";
			cout << "|el nuevo precio es:";
            cin >> p;
            cout<<"\n";
            gasolinas[i].precio = p;
            
        }
        if (gasolinas[i].codigo > 4)
        {
            m1 = gasolinas[i].cantidad;
            cout << "|la nueva cantidad es:";
            cin >> m2;
            gasolinas[i].cantidad = m2;
            size=-1;
            cout<<"\n";
            cout << "|-------------------------|\n";
            cout<<"\n";
        }
		else
		{
			cout << "|-------------------------|\n";
		}
			
        if (m1 > m2)
        {
            venta = m1 - m2;
        }
	}
	historial[historial_size].usuario = usuario;
                    historial[historial_size].accion = "ACTUALIZAR";
                    historial[historial_size].codigoProducto = codigo;
                    historial_size++;
	return;
}

// Funci�n para marcar una gasolina como inactiva (eliminar simulado)
void eliminarProducto(Gasolina gasolinas[], int& size, Historial historial[], int& historial_size, const string& usuario) 
{int codigoEliminar;
cout << "|-------------------------------------------------|\n";
cout << "Ingrese el c�digo de la gasolina a eliminar: ";cin >> codigoEliminar; 
cout << "|-------------------------------------------------|\n";
for (int i = 0; i < size; ++i) 
    {
        if (gasolinas[i].codigo == codigoEliminar) 
        {
            gasolinas[i].activo = false;
            cout << "Producto con c�digo " << codigoEliminar << " eliminado correctamente.\n";
            // Ajustar el arreglo para "eliminar" el producto
            for (int j = i; j < size - 1; ++j) {
                gasolinas[j] = gasolinas[j + 1];
            }
            
            size--; // Reducir el tama�o del arreglo
            
            historial[historial_size].usuario = usuario;
            historial[historial_size].accion = "ELIMINAR";
            historial[historial_size].codigoProducto = codigoEliminar;
            historial_size++;
            return;
        }
    }
    
}

void mostrarHistorial(const Historial historial[], int historial_size) {
    system("cls");
    int OPH;
    cout << "-----------------------" << endl;
    cout << "|   Menu de opciones  |" << endl;
    cout << "|---------------------|" << endl;
    cout << "|1.| HISTORIAL ACTUAL |" << endl;
    cout << "|2.| HISTORIAL DEL MES|" << endl;
    cout << "|3.|";
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
	cout <<" Salir";
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
	cout <<"            |" << endl;
    cout << "|---------------------|" << endl;
    cout << "Ingrese su opci�n: ";
    cin >> OPH;

    switch (OPH) {
        case 1: {
            // Mostrar historial actual
            cout << "+---------------------------------------------------+\n";
            cout << "|                    HISTORIAL                      |\n";
            cout << "+---------------------------------------------------+\n";
            cout << "|   Usuario   |     Acci�n     | C�digo del Producto|\n";
            cout << "+---------------------------------------------------+\n";
            for (int i = 0; i < historial_size; ++i) {
                cout << "| " << setw(10) << historial[i].usuario << " | "
                     << setw(14) << historial[i].accion << " | "
                     << setw(17) << historial[i].codigoProducto << " |\n";
            }
            cout << "+---------------------------------------------------+\n";

            // Guardar historial en un archivo
            ofstream archivo_salida("historial.txt", ios::app);  // Abre el archivo en modo append
            if (archivo_salida.is_open()) {
                for (int i = 0; i < historial_size; ++i) {
                    historial[i].guardarHistorial(archivo_salida);
                }
                archivo_salida.close();
                cout << "Historial guardado en historial.txt\n";
            } else {
                cout << "No se pudo abrir el archivo para guardar el historial.\n";
            }

            cout << "Presione cualquier tecla para continuar...";
            getch();
            system("cls");
            break;
        }
        case 2: {
            // Mostrar historial del archivo
            ifstream archivo_entrada("historial.txt");
            if (archivo_entrada.is_open()) {
                string linea;
                cout << "+---------------------------------------------------+\n";
                cout << "|                    HISTORIAL                      |\n";
                cout << "+---------------------------------------------------+\n";
                cout << "|   Usuario   |     Acci�n     | C�digo del Producto|\n";
                cout << "+---------------------------------------------------+\n";
                while (getline(archivo_entrada, linea)) {
                    stringstream ss(linea);
                    string usuario, accion;
                    int codigoProducto;
                    getline(ss, usuario, ',');
                    getline(ss, accion, ',');
                    ss >> codigoProducto;
                    cout << "| " << setw(10) << usuario << " | "
                         << setw(14) << accion << " | "
                         << setw(17) << codigoProducto << " |\n";
                }
                cout << "+---------------------------------------------------+\n";
                archivo_entrada.close();
            } else {
                cout << "No se pudo abrir el archivo historial.txt\n";
            }
            cout << "Presione cualquier tecla para continuar...";
            getch();
            system("cls");
            break;
        }
        case 3:
            // Opci�n para salir
            break;
        default:
            cout << "OPCI�N NO V�LIDA. Ingrese nuevamente: ";
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Spanish");
    system("color F1");
    Historial historial[max_historial_size];
    int historial_size = 0;
    int OPCION,  cargo;
    int contador = 0;
    int i=1;
    string usuario;
    string contrasena;
    bool accesoPermitido = false;
  

    Usuario usuarios[] = {trabajador1, trabajador2, trabajador3, trabajador4, trabajador5};
    // Lista de gasolinas con sus respectivos c�digos, nombres y precios
    const int max_size = 1000;
    int size = 11;
    Gasolina gasolinas[max_size] = {
        {1, "Gasolina Regular", 14.89, 1000, "Galones"},
        {2, "Gasolina Premium", 16.39, 1000, "Galones"},
        {3, "Diesel", 15.94, 1000, "Galones"},
        {4, "GLP", 10.99, 1000, "Galones"},
        {5, "Castrol", 50.96, 100, "Aceites"},
        {6, "Mannol", 90.54, 100, "Aceites"},
        {7, "LubricantE WD-40", 36.90, 100, "Lubricantes"},
        {8, "Inka Kola 500ml", 3.00, 100, "Bebidas"},
        {9, "Coca Cola 500ml", 3.00, 100, "Bebidas"},
        {10, "Cielo 1L", 2.40, 100, "Botellas"},
        {11, "San Luis 625ml", 1.60, 100, "Botellas"},
    };
    // MODIFICACION DEL EXCEL//
    // Apertura del archivo
    std::ofstream archivoExcel("productos.csv");
    if (!archivoExcel.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }
    // Escritura del encabezado
    archivoExcel << "CODIGO,NOMBRE,PRECIO,CANTIDAD,TIPO" << std::endl;
    // Iteraci�n sobre el arreglo y escritura de datos
    for(i=;i<size;++i)
    {
    	archivoExcel << gasolinas[i].codigo << ","<< gasolinas[i].nombre << ","<< gasolinas[i].precio << ","<< gasolinas[i].cantidad << ","<<gasolinas[i].tipo << std::endl;
	}
    archivoExcel.close();
	// FIN DE LISTA //
    // BUCLE DE CARGO //
    do {
        cout << " ----------------------------" << endl;
		cout << "| ESCOJA UNA DE LAS OPCIONES |" << endl;
		cout << "|----------------------------|" << endl;
		cout << "|          OPERADOR       | 1|" << endl;
		cout << "|----------------------------|" << endl;
        cout << "|        ADMINISTRADOR    | 2|" << endl;
		cout << "|----------------------------|" << endl;
		cout << "|          OPCI�N:        | ";cin >> cargo;
        // BUCLE DE USUARIOS //
        do {
            system("cls");
            cout << " ____________________________ " << endl;
            cout << "|       BIENVENIDO           |" << endl;
            cout << "|----------------------------|" << endl;
            cout << "|   INGRESE LOS DATOS:       |" << endl;
            cout << "|----------------------------|" << endl;
            cout << "|01. USUARIO    | ";
            if (cargo == 2) {cout << trabajador5.Nombre << endl;usuario = trabajador5.Nombre;} 
			else {cin >> usuario;}
            cout << "|02. CONTRASE�A | ";
            char caracter;
            caracter= _getch();
            while (caracter != 13 ){contrasena.push_back(caracter);cout << "*";caracter = _getch();} // CONTRASELA OCULTA

            for (int i = 0; i < 5; i++) {
                if (usuario == usuarios[i].Nombre && contrasena == usuarios[i].contra) {
                    accesoPermitido = true;
                    // Bucle para volver al men� de opciones
                    while (true) {
                        system("cls");
                        cout << " -------------------------- " << endl;
                        cout << "|----SISTEMA DE REGISTRO---|" << endl;
                        cout << "|--------------------------|" << endl;
                        cout << "|NOMBRE: " << usuarios[i].Nombre << "          " << endl;
                        cout << "|CARGO : " << usuarios[i].Cargo << "      " << endl;
                        cout << "|--------------------------|" << endl;
                        cout << "|---SELECCIONE LA OPCI�N---|" << endl;
                        cout << "|01.| INSERTAR ------------|" << endl;
                        cout << "|02.| BUSCAR --------------|" << endl;
                        if (usuario == "STEVIE" || usuario == "USHER") {
                            cout << "|03.|"; 
                            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
							cout << " BLOQUEADO";
							SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
							cout <<" -----------|" << endl;
                            cout << "|04.|";
                            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
							cout << " BLOQUEADO";
							SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
							cout <<" -----------|" << endl;
							cout << "|05.|";
                            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
							cout << " BLOQUEADO";
							SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
							cout <<" -----------|" << endl;
						} else if (usuario == "SEBASTIAN" || usuario == "JIMMY") {
                            cout << "|03.| ACTUALIZAR ----------|" << endl;
                            cout << "|04.| ELIMINAR ------------|" << endl;
                            cout << "|05.|";
                            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
							cout <<" BLOQUEADO";
							SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
							cout <<" -----------|" << endl;
                        } else {
                            cout << "|03.| ACTUALIZAR ----------|" << endl;
                            cout << "|04.| ELIMINAR ------------|" << endl;
                            cout << "|05.| HISTORIAL -----------|" << endl;
                        }
                        cout << "|06.|";
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
						cout <<" SALIR";
						SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
						cout <<" ---------------|" << endl;
                        cout << " -------------------------- " << endl;
                        cout << "Ingrese la Opci�n: ";
                        cin >> OPCION;
                        
                        switch (OPCION) {
                            case 1:
                                mostrarMenuinsertar(gasolinas, size, historial, historial_size, usuario);
                                break;
                            case 2:
                                mostrarMenu(gasolinas, size);
                                system("cls");
                                break;
                            case 3:
                                if (usuario != "STEVIE" && usuario != "USHER") {
                                    // C�digo para la opci�n ACTUALIZAR
                                    cout << "Opci�n ACTUALIZAR seleccionada." << endl;
                                    actualizacion(gasolinas, size, historial, historial_size, usuario);} 
								else {
                                    system("cls");
                                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
                                    cout << "OPCI�N BLOQUEADA" << endl;
                                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
                                }
                                break;
                            case 4:
    							if (usuario != "STEVIE" && usuario != "USHER") {system("cls");eliminarProducto(gasolinas, size, historial, historial_size, usuario);} 
								else {
        							system("cls");
        							SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
        							cout << "OPCI�N BLOQUEADA" << endl;
        							SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
    							}
    							break;
                            case 5:
    							if (usuario == "HAYDEE") {system("cls");mostrarHistorial(historial, historial_size);} 
								else {
                                    system("cls");
                                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
                                    cout << "OPCI�N BLOQUEADA" << endl;
                                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
                                }
    							break;
                            case 6:
                                return 0;
                            default:
                                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
                                cout << "OPCI�N NO V�LIDA. Ingrese nuevamente: ";
                                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
                                break;
                        }
                        cout << "Presione una tecla para continuar..." << endl;
                        getch(); // Espera a que el usuario presione una tecla
                    }
                }
            }
            // ACCESO DENEGADO Y CONTADOR DE INTENTOS//
            if (!accesoPermitido) 
			{
				contador++;contrasena.clear(); 
				cout <<endl;
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
                cout << "DATOS INCORRECTOS" << endl;
                cout << "Presione una tecla para continuar..." << endl;
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
				getch(); system("cls");
			}
        } while (!accesoPermitido && contador < 3);
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "HICISTE EL M�XIMO DE INTENTOS, VUELVA M�S TARDE" << endl;
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);getch();system("cls");
    } while (true);
    return 0;
}
