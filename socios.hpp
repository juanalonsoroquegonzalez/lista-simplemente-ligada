#ifndef __SOCIOS_H__
#define __SOCIOS_H__

#include <iostream>
#include <string>

using namespace std;

class socios
{
private:
    int numeroSocio;
    string nombreSocio;
    string domicilio;
    int anioIngreso;
public:
    socios();
    socios(const socios &);
    ~socios();

    int getNumeroSocio() const;
    string getNombreSocio() const;
    string getDomicilio() const;
    int getAnioIngreso() const;

    void setNumeroSocio(const int&);
    void setNombreSocio(const string&);
    void setDomicilio(const string&);
    void setAnioIngreso(const int&);

    string toString() const;

    socios &operator=(const socios&);

    bool operator==(const socios&) const;
    bool operator!=(const socios&) const;
    bool operator<(const socios&) const;
    bool operator<=(const socios&) const;
    bool operator>(const socios&) const;
    bool operator>=(const socios&) const;

    friend istream &operator>>(istream&, socios&);
    friend ostream &operator<<(ostream&, const socios&);
};

#endif // __SOCIOS_H__