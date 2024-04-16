#include "listaSocios.hpp"
#include "socios.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    listaSocios lista;
    int opcion;

    do
    {
        cout << "///////////////////// Menu /////////////////////\n" << endl;
        cout << "1. Registrar un nuevo socio" << endl;
        cout << "2. Dar de baja un socio del club" << endl;
        cout << "3. Generar un reporte" << endl;
        cout << "4. Buscar por nombre y domicilio" << endl;
        cout << "5. Calcular e imprimir socios registrados" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: {
            system("cls");
            socios nuevoSocio;
            cout << "Ingrese el numero de socio: ";
            int numeroSocio;
            cin >> numeroSocio;
            nuevoSocio.setNumeroSocio(numeroSocio);
            cout << "Ingrese el nombre del socio: ";
            string nombre;
            cin.ignore();
            getline(cin, nombre);
            nuevoSocio.setNombreSocio(nombre);
            cout << "Ingrese el domicilio del socio: ";
            string domicilio;
            getline(cin, domicilio);
            nuevoSocio.setDomicilio(domicilio);
            cout << "Ingrese el anio de ingreso del socio: ";
            int anioIngreso;
            cin >> anioIngreso;
            nuevoSocio.setAnioIngreso(anioIngreso);

            lista.agregarSocio(nuevoSocio);
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            int numeroSocio;
            cout << "Ingrese el numero de socio del socio a dar de baja: ";
            cin >> numeroSocio;
            lista.eliminarSocio(numeroSocio);
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            lista.crearReporte();
            system("cls");
            break;
        }
        case 4: {
            system("cls");
            string nombre;
            cout << "Ingrese el nombre del socio a buscar: ";
            cin.ignore();
            getline(cin, nombre);
            string domicilio;
            cout << "Ingrese el domicilio del socio a buscar: ";
            getline(cin, domicilio);
            lista.buscar(nombre, domicilio);
            system("cls");
            break;
        }
        case 5: {
            system("cls");
            int totalSocios = lista.sociosRegistrados();
            cout << "El total de socios registrados es: " << totalSocios << endl;
            system("cls");
            break;
        }
        case 6: {
            cout << "Saliendo del programa..." << endl;
            break;
        }
        default:
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
            break;
        }

    } while (opcion != 6);

    return 0;
}
