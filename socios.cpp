#include "socios.hpp"

socios::socios()
{
    
}

socios::socios(const socios &s)
        :   numeroSocio(s.numeroSocio),
            nombreSocio(s.nombreSocio),
            domicilio(s.domicilio),
            anioIngreso(s.anioIngreso) {}

socios::~socios()
{
    
}

int socios::getNumeroSocio() const
{
    return numeroSocio;
}

string socios::getNombreSocio() const
{
    return nombreSocio;
}

string socios::getDomicilio() const
{
    return domicilio;
}

int socios::getAnioIngreso() const
{
    return anioIngreso;
}

void socios::setNumeroSocio(const int& n)
{
    numeroSocio = n;
}

void socios::setNombreSocio(const string& n)
{
    nombreSocio = n;
}

void socios::setDomicilio(const string& n)
{
    domicilio = n;
}

void socios::setAnioIngreso(const int& n)
{
    anioIngreso = n;
}

string socios::toString() const
{
    string result;

    result += to_string(numeroSocio);
    result.resize(6, ' ');
    result += " | ";
    result += nombreSocio;
    result.resize(20, ' ');
    result += " | ";
    result += domicilio;
    result.resize(30, ' ');
    result += " | ";
    result += to_string(anioIngreso);
    result += " | ";

    return result;
}

socios& socios::operator=(const socios& s)
{
    numeroSocio = s.numeroSocio;
    nombreSocio = s.nombreSocio;
    domicilio = s.domicilio;
    anioIngreso = s.anioIngreso;

    return *this;
}

bool socios::operator==(const socios& s) const
{
    return numeroSocio == s.numeroSocio;
}

bool socios::operator!=(const socios& s) const
{
    return numeroSocio != s.numeroSocio;
}

bool socios::operator<(const socios& s) const
{
    return numeroSocio < s.numeroSocio;
}

bool socios::operator<=(const socios& s) const
{
    return numeroSocio <= s.numeroSocio;
}

bool socios::operator>(const socios& s) const
{
    return numeroSocio > s.numeroSocio;
}

bool socios::operator>=(const socios& s) const
{
    return numeroSocio >= s.numeroSocio;
}

ostream& operator<<(ostream& os, const socios& s)
{
    os << s.numeroSocio << endl;
    os << s.nombreSocio << endl;
    os << s.domicilio << endl;
    os << s.anioIngreso << endl;

    return os;
}

istream& operator>>(istream& is, socios& s)
{
    is >> s.numeroSocio;
    getline(is, s.nombreSocio);
    getline(is, s.domicilio);
    is >> s.anioIngreso;

    return is;
}
