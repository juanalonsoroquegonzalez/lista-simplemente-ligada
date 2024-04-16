#ifndef __LISTASOCIOS_H__
#define __LISTASOCIOS_H__

#include "nodo.hpp"
#include "socios.hpp"

class listaSocios
{
  private:
    nodo *ancla;

  public:
    listaSocios();
    ~listaSocios();

    void ordenar();
    void agregarSocio(const socios &);
    void eliminarSocio(int numeroSocio);
    void crearReporte() const;
    void buscar(const string &nombreSocio, const string &domicilio);
    int sociosRegistrados() const;
};

#endif // __LISTASOCIOS_H__