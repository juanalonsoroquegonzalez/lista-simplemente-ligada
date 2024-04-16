#include "nodo.hpp"
#include "socios.hpp"

nodo::nodo() : datoPtr(nullptr), prev(nullptr), siguiente(nullptr)
{}

nodo::nodo(const socios& s): datoPtr(new socios(s)), prev(nullptr), siguiente(nullptr) {
  if (datoPtr == nullptr) {
    cout << "Memoria no disponible, creando Nodo";
  }
}

nodo::~nodo()
{
    delete datoPtr;
}

socios nodo::getDato()
{
    return *datoPtr;
}

socios* nodo::getDatoPtr()
{
    if (datoPtr == nullptr) {
    cout << "Error, el dato no existe, getDatoPtr";
  }
  return datoPtr;
}

nodo* nodo::getSiguiente()
{
    return siguiente;
}

nodo* nodo::getPrev()
{
    return prev;
}

void nodo::setDatoPtr(socios* s)
{
    datoPtr = s;
}

void nodo::setDato(const socios& s)
{
    delete datoPtr;

  datoPtr = new socios(s);

  if (datoPtr == nullptr) {
    cout << "Memoria no disponible, setDato";
  }
}

void nodo::setSiguiente(nodo* p)
{
    siguiente = p;
}

void nodo::setPrev(nodo* p)
{
    prev = p;
}
