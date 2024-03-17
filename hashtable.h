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
  HashTable(unsigned tablesize, const DispersionFunction<key>& fd, const ExplorationFunction<key>& fe, unsigned blockSize);
  ~HashTable();
  bool Search(const key& k) const;
  bool Insert(const key& k);
  void Print() const;

 private:
  unsigned tableSize_;
  Container* table_;  
  const DispersionFunction<key>& fd_;
  const ExplorationFunction<key>& fe_;
  unsigned blockSize_;
};



template <class key, class Container>
HashTable<key, Container>::HashTable(unsigned tablesize, const DispersionFunction<key>& fd, const ExplorationFunction<key>& fe, unsigned blockSize) {
  tableSize_ = tablesize;
  fd_ = fd;
  fe_ = fe;
  blockSize_ = blockSize;
  table_ = new Container[tableSize_];
  for (unsigned i = 0; i < tableSize_; i++) {
    table_[i] = Container(blockSize_);
  }
}


template <class key, class Container>
HashTable<key, Container>::~HashTable() {
  for (unsigned i = 0; i < tableSize_; i++) {
    delete table_[i];
  }
}









#endif  // HASHTABLE_H