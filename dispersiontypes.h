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
  ModuleDispersion(unsigned tablesize) : tableSize_{tablesize} {}
  unsigned operator()(const key& k) const override {
    return long(k) % tableSize_;
  }

 private:
  unsigned tableSize_;
};



template <class key>
class SumDispersion : public DispersionFunction<key> {
 public:
  SumDispersion(unsigned tablesize) : tableSize_{tablesize} {}
  unsigned operator()(const key& k) const override {
    long clave = k;
    unsigned sum = 0;
    while (clave > 0) {
      sum += clave % 10;
      clave /= 10;
    }
    return sum % tableSize_;
  }

 private:
  unsigned tableSize_;
};




template <class key>
class PseudoRandomDispersion : public DispersionFunction<key> {
 public:
  PseudoRandomDispersion(unsigned tablesize) : tableSize_{tablesize} {}
  unsigned operator()(const key& k) const override {
    srand(long(k));
    return rand() % tableSize_;
  }

 private:
  unsigned tableSize_;
};



#endif  // DISPERSIONTYPES_H