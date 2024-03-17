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


#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <iostream>

template <class key>
class Sequence {
  public:
  virtual bool Search(const key& k) const = 0;
  virtual bool Insert(const key& k) = 0;
  virtual void Print() const = 0;
};


#endif  // SEQUENCE_H