#include "guiatlf.h"

list<pair<string, string>> Guia_Tlf::ObtenerPorPrefijo(const string &prefijo) {
  list<pair<string, string>> resultado;
  map<string, string>::iterator it;
  for (it = this->datos.begin(); it != this->datos.end(); ++it) {
    if (it->second.find(prefijo) != std::string::npos) {
      resultado.insert(resultado.begin(), *it);
    }
  }
  return resultado;
}

string Guia_Tlf::getnombre(const string &telefono) {
  map<string, string>::iterator it;
  for (it = this->datos.begin(); it != this->datos.end(); ++it) {
    if (it->second == telefono) {
      return it->first;
    }
  }

  return "Nombre no encontrado";
}

void Guia_Tlf::modificaNumero(const string &nombre, const string &telefono) {
  map<string, string>::iterator it = datos.find(nombre);
  if (it == datos.end())
    return;
  else {
    it->second = telefono;
  }
}

string &Guia_Tlf::operator[](const string &nombre) { return datos[nombre]; }

string Guia_Tlf::gettelefono(const string &nombre) {
  map<string, string>::iterator it = datos.find(nombre);
  if (it == datos.end())
    return string("");
  else
    return it->second;
}

pair<map<string, string>::iterator, bool> Guia_Tlf::insert(string nombre,
                                                           string tlf) {
  pair<string, string> p(nombre, tlf);
  pair<map<string, string>::iterator, bool> ret;

  ret = datos.insert(p); // datos.insert(datos.begin(),p); tambien funcionaría
  return ret;
}

pair<map<string, string>::iterator, bool>
Guia_Tlf::insert(pair<string, string> p) {

  pair<map<string, string>::iterator, bool> ret;

  ret = datos.insert(p); // datos.insert(datos.begin(),p); tambien funcionaría
  return ret;
}

void Guia_Tlf::borrar(const string &nombre) {
  map<string, string>::iterator itlow =
      datos.lower_bound(nombre); // el primero que tiene dicho nombre
  map<string, string>::iterator itupper =
      datos.lower_bound(nombre); // el primero que ya no tiene dicho nombre
  datos.erase(itlow, itupper); // borramos todos aquellos que tiene dicho nombre
  // OTRA ALTERNATIVA
  // pair<map<string,string>::iterator,map<string,string>::iterator>ret;
  // ret = datos.equal_range(nombre
  // datos.erase(ret.first,ret.second);
}

void Guia_Tlf::borrar(const string &nombre, const string &tlf) {
  map<string, string>::iterator itlow =
      datos.lower_bound(nombre); // el primero que tiene dicho nombre
  map<string, string>::iterator itupper =
      datos.upper_bound(nombre); // el primero que ya no tiene dicho nombre
  map<string, string>::iterator it;
  bool salir = false;
  for (it = itlow; it != itupper && !salir; ++it) {
    if (it->second == tlf) {
      datos.erase(it);
      salir = true;
    }
  }
}

int Guia_Tlf::size() const { return datos.size(); }

unsigned int Guia_Tlf::contabiliza(const string &nombre) {
  return datos.count(nombre);
}

void Guia_Tlf::clear() { datos.clear(); }

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf &g) {
  Guia_Tlf aux(*this);
  map<string, string>::const_iterator it;
  for (it = g.datos.begin(); it != g.datos.end(); ++it) {
    aux.insert(it->first, it->second);
  }
  return aux;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf &g) {
  Guia_Tlf aux(*this);
  map<string, string>::const_iterator it;
  for (it = g.datos.begin(); it != g.datos.end(); ++it) {
    aux.borrar(it->first, it->second);
  }
  return aux;
}

Guia_Tlf Guia_Tlf::previos(const string &nombre, const string &tlf) {
  map<string, string>::value_compare vc =
      datos.value_comp(); // map<string,string>::key_compare vc=datos.key_comp()
  Guia_Tlf aux;
  pair<string, string> p(nombre, tlf);
  map<string, string>::iterator it = datos.begin();
  while (vc(*it, p)) {
    aux.insert(*it++);
  }
  return aux;
}

Guia_Tlf::iterator Guia_Tlf::begin() {
  Guia_Tlf::iterator i;
  i.it = datos.begin();
  return i;
}

Guia_Tlf::iterator Guia_Tlf::end() {
  iterator i;
  i.it = datos.end();
  return i;
}

void Guia_Tlf::iterator::operator++() { ++it;}
void Guia_Tlf::iterator::operator--() { --it; }
pair<const string, string>  Guia_Tlf::iterator::operator*() { return *it; }
bool Guia_Tlf::iterator::operator==(const iterator &i) {
  return i.it == it;
}

bool Guia_Tlf::iterator::operator!=(const iterator &i) {
  return i.it != it;
}

ostream &operator<<(ostream &os, Guia_Tlf &g) {
  map<string, string>::iterator it;
  for (it = g.datos.begin(); it != g.datos.end(); ++it) {
    os << it->first << "\t" << it->second << endl;
  }
  return os;
}

istream &operator>>(istream &is, Guia_Tlf &g) {
  pair<string, string> p;
  Guia_Tlf aux;
  while (is >> p) {
    aux.insert(p);
  }
  g = aux;
  return is;
}

istream &operator>>(istream &is, pair<string, string> &d) {

  getline(is, d.first, '\t');
  getline(is, d.second);
  return is;
}