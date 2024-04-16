#ifndef __NODO_H__
#define __NODO_H__

#include "socios.hpp"

 class nodo {
   private:
    socios* datoPtr;
    nodo* siguiente;
    nodo* prev;

   public:
    nodo();
    nodo(const socios&);

    ~nodo();

    socios getDato();
    socios* getDatoPtr();
    nodo* getSiguiente();
    nodo* getPrev();

    void setDatoPtr(socios*);
    void setDato(const socios&);
    void setSiguiente(nodo*);
    void setPrev(nodo*);
  };

#endif // __NODO_H__