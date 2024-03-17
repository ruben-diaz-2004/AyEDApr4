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


#ifndef EXPLORATIONFUNCTION_H
#define EXPLORATIONFUNCTION_H


#include <iostream>

template <class key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const key& k, unsigned i) const = 0;
};


#endif  // EXPLORATIONFUNCTION_H