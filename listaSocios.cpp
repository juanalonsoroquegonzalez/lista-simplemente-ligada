#include "listaSocios.hpp"
#include "socios.hpp"

listaSocios::listaSocios() : ancla(nullptr)
{
}

listaSocios::~listaSocios()
{
    while (ancla != nullptr)
    {
        nodo *temp = ancla;
        ancla = ancla->getSiguiente();
        delete temp;
    }
}

void listaSocios::ordenar()
{
    if (ancla == nullptr || ancla->getSiguiente() == nullptr)
    {
        return;
    }

    bool intercambio = false;
    do
    {
        intercambio = false;
        nodo *actual = ancla;
        nodo *siguiente = actual->getSiguiente();
        while (siguiente != nullptr)
        {
            if (actual->getDato().getNumeroSocio() > siguiente->getDato().getNumeroSocio())
            {
                socios temp = actual->getDato();
                actual->setDato(siguiente->getDato());
                siguiente->setDato(temp);
                intercambio = true;
            }
            actual = siguiente;
            siguiente = siguiente->getSiguiente();
        }
    } while (intercambio);
}

void listaSocios::agregarSocio(const socios &socio)
{
    nodo *temp = ancla;
    while (temp != nullptr)
    {
        if (temp->getDato().getNumeroSocio() == socio.getNumeroSocio())
        {
            cout << "Error: Ya existe un socio con el mismo numero de socio." << endl;
            system("pause");
            return;
        }
        temp = temp->getSiguiente();
    }

    nodo *nuevoNodo = new nodo(socio);
    if (ancla == nullptr)
    {
        ancla = nuevoNodo;
    }
    else
    {
        temp = ancla;
        while (temp->getSiguiente() != nullptr)
        {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
    }
    ordenar();
    cout << "Socio Agregado..." << endl;
    system("pause");
}

void listaSocios::eliminarSocio(int numeroSocio)
{
    if (ancla == nullptr)
    {
        cout << "La lista esta vacia." << endl;
        system("pause");
        return;
    }

    if (ancla->getDatoPtr()->getNumeroSocio() == numeroSocio)
    {
        nodo *temp = ancla;
        ancla = ancla->getSiguiente();
        delete temp;
        cout << "Socio eliminado correctamente." << endl;
        system("pause");
        return;
    }

    nodo *anterior = nullptr;
    nodo *actual = ancla;

    while (actual != nullptr && actual->getDatoPtr()->getNumeroSocio() != numeroSocio)
    {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr)
    {
        cout << "El socio no existe en la lista." << endl;
        system("pause");
        return;
    }

    anterior->setSiguiente(actual->getSiguiente());
    delete actual;
    cout << "Socio eliminado correctamente." << endl;
    system("pause");
}

void listaSocios::crearReporte() const
{
    if (ancla == nullptr)
    {
        std::cout << "No hay socios registrados." << std::endl;
        return;
    }

    std::cout << "Reporte de socios:" << std::endl;
    std::cout << "------------------" << std::endl;

    nodo *temp = ancla;
    while (temp != nullptr)
    {
        std::cout << temp->getDato().toString() << std::endl;
        temp = temp->getSiguiente();
    }
    system("pause");
}

void listaSocios::buscar(const string &nombre, const string &domicilio)
{
    if (ancla == nullptr)
    {
        std::cout << "No hay socios registrados." << std::endl;
        return;
    }

    bool encontrado = false;
    nodo *temp = ancla;
    while (temp != nullptr)
    {
        if (temp->getDato().getNombreSocio() == nombre && temp->getDato().getDomicilio() == domicilio)
        {
            std::cout << "Socio encontrado:" << std::endl;
            std::cout << temp->getDato().toString() << std::endl;
            encontrado = true;
            break;
        }
        temp = temp->getSiguiente();
    }

    if (!encontrado)
    {
        std::cout << "No se encontro ningun socio con el nombre \"" << nombre << "\" y domicilio \"" << domicilio
                  << "\"." << std::endl;
    }
    system("pause");
}

int listaSocios::sociosRegistrados() const
{
    int cont = 0;
    nodo *temp = ancla;
    while (temp != nullptr)
    {
        cout << temp->getDato().toString() << endl;
        temp = temp->getSiguiente();
        cont++;
    }
    cout << "Socios registrados: " << cont << endl;
    system("pause");
    return cont;
}
