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


#ifndef DISPERSIONFUNCTION_H
#define DISPERSIONFUNCTION_H


#include <iostream>
template <class key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const key& k) const = 0;
};


#endif  // DISPERSIONFUNCTION_H