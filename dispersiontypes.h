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


#ifndef DISPERSIONTYPES_H
#define DISPERSIONTYPES_H


#include <iostream>
#include "dispersionfunction.h"


template <class key>
class ModuleDispersion : public DispersionFunction<key> {
 public:
 // Constructor
  ModuleDispersion(unsigned tablesize) : tableSize_{tablesize} {}
  unsigned operator()(const key& clave) const {
    std::cout << "ModuleDispersion: " << long(clave) % tableSize_ << std::endl;
    return long(clave) % tableSize_;
  }

 private:
  unsigned tableSize_;
};



template <class key>
class SumDispersion : public DispersionFunction<key> {
 public:
  SumDispersion(unsigned tablesize) : tableSize_{tablesize} {}
  unsigned operator()(const key& param_key) const {
    long clave = param_key;
    unsigned sum = 0;
    while (clave > 0) {
      sum += clave % 10;
      clave /= 10;
    }
    std::cout << "SumaDispersion: " << sum % tableSize_ << std::endl;
    return sum % tableSize_;
  }

 private:
  unsigned tableSize_;
};




template <class key>
class PseudoRandomDispersion : public DispersionFunction<key> {
 public:
  PseudoRandomDispersion(unsigned tablesize) : tableSize_{tablesize} {}
  unsigned operator()(const key& clave) const {
    srand(long(clave));
    return rand() % tableSize_;
  }

 private:
  unsigned tableSize_;
};



#endif  // DISPERSIONTYPES_H