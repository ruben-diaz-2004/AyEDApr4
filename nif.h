/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 15/03/2024
  * @brief Búsqueda mediante tablas de dispersión
  */


#ifndef NIF_H
#define NIF_H


#include <iostream>


class Nif {
  public:
  Nif();
  Nif(const long& nif);
  // Sobrecarga de los operadores de comparación
  bool operator==(const Nif& nif) const;
  bool operator!=(const Nif& nif) const;
  bool operator<(const Nif& nif) const;
  bool operator>(const Nif& nif) const;
  operator long() const;

  private:
  long nif_;
};




#endif  // NIF_H