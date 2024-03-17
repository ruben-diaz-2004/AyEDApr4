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


#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include "dynamicsequence.h"
#include "staticsequence.h"
#include "dispersionfunction.h"
#include "explorationfunction.h"


template <class key, class Container=StaticSequence<key>>
class HashTable: public Sequence<key> {
 public:
  HashTable(unsigned tablesize, DispersionFunction<key>& fd, ExplorationFunction<key>& fe, unsigned blockSize) : fd_{fd}, fe_{fe} {
    tableSize_ = tablesize;
    blockSize_ = blockSize;
    table_ = new Container[tableSize_];
    for (unsigned i = 0; i < tableSize_; i++) {
      table_[i].Initialize(blockSize_);
    }
  }

  ~HashTable() {
    delete[] table_;
  }

  bool Search(const key& k) const {
    unsigned position = fd_(k);
    unsigned intento{0};
    bool runnig{true};
    while (runnig) {
      if (table_[position].Search(k)) {
        return true;
      }
      if (!table_[position].IsFull()) {
        runnig = false;
      }
      position = fe_(k, intento);
      intento++;
    }
  }

  bool Insert(const key& k) {
    unsigned position = fd_(k);
    unsigned intento{0};
    bool runnig{true};
    while (runnig) {
      if (table_[position].Insert(k)) {
        return true;
      }
      if (!table_[position].IsFull()) {
        runnig = false;
      }
      position = fe_(k, intento);
      intento++;
    }
  }

  void Print() const {
    for (unsigned i = 0; i < tableSize_; i++) {
      std::cout << "Posición " << i << ": ";
      table_[i].Print();
      std::cout << std::endl;
    }
  }

 private:
  unsigned tableSize_;
  Container* table_;  
  DispersionFunction<key>& fd_;
  ExplorationFunction<key>& fe_;
  unsigned blockSize_;
};










template <class key>
class HashTable<key, DynamicSequence<key>>: public Sequence<key> {
 public:
  HashTable(unsigned tablesize, DispersionFunction<key>& fd) : fd_{fd} {
    tableSize_ = tablesize;
    table_ = new DynamicSequence<key>[tableSize_];
  }

  ~HashTable() {
    delete[] table_;
  }

  bool Search(const key& k) const {
    unsigned position = fd_(k);
    return table_[position].Search(k);
  }

  bool Insert(const key& k) {
    unsigned position = fd_(k);
    return table_[position].Insert(k);
  }

  void Print() const {
    for (unsigned i = 0; i < tableSize_; i++) {
      std::cout << "Posición " << i << ": ";
      table_[i].Print();
      std::cout << std::endl;
    }
  }

 private:
  unsigned tableSize_;
  DynamicSequence<key>* table_;  
  DispersionFunction<key>& fd_;
};





#endif  // HASHTABLE_H