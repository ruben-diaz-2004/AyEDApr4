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


#ifndef EXPLORATIONTYPES_H
#define EXPLORATIONTYPES_H


#include <iostream>
#include "explorationfunction.h"
#include "dispersionfunction.h"


// Exploración lineal, g(k,i) = i
template <class key>
class LinearExploration : public ExplorationFunction<key> {
 public:
    LinearExploration(unsigned tableSize) : tableSize_{tableSize} {}
    unsigned operator()(const key& k, unsigned i) const override {
        return (k + i) % tableSize_;
    }

 private:
  unsigned tableSize_;
};


// Exploración cuadrática, g(k,i) = i^2	
/**
 * En la implementación de la función de exploración cuadrática sólo se tienen en 
 * cuenta los desplazamientos positivos respecto a la posición inicial.
*/
template <class key>
class QuadraticExploration : public ExplorationFunction<key> {
 public:
    QuadraticExploration(unsigned tableSize) : tableSize_{tableSize} {}
    unsigned operator()(const key& k, unsigned i) const override {
        return (k + i * i) % tableSize_;
    }

 private:
  unsigned tableSize_;
};


// Doble dispersión, g(k,i) = f(k) * i
/**
 * En la implementación de la función de exploración por dispersión doble, la función
 * de dispersión auxiliar f(k) se pasa por parámetro al constructor de la clase derivada.
*/
template <class key>
class DoubleDispersion : public ExplorationFunction<key> {
 public:
    DoubleDispersion(unsigned tableSize, DispersionFunction<key>* f) : tableSize_{tableSize}, f_{f} {}
    unsigned operator()(const key& k, unsigned i) const override {
        return (f_->operator()(k) + i) % tableSize_;
    }

 private:
  unsigned tableSize_;
  DispersionFunction<key>* f_;
};



// Redispersión, g(k,i) = f^(i) * (k)
/**
 * En la implementación de la estrategia de exploración por redispersión se utiliza el 
 * generador de números pseudo-aleatorios. Se inicializa la semilla del generador con
 * el valor de la clave, srand(k), y se retorna el valor de la i-ésima llamada a
 * rand() como el valor de desplazamiento f^(i) * (k).
*/
template <class key>
class ReDispersion : public ExplorationFunction<key> {
 public:
    ReDispersion(unsigned tableSize) : tableSize_{tableSize} {}
    unsigned operator()(const key& k, unsigned i) const override {
        srand(k);
        for (unsigned j = 0; j < i; j++) {
            rand();
        }
        return rand() % tableSize_;
    }

 private:
  unsigned tableSize_;
};



#endif  // EXPLORATIONTYPES_H