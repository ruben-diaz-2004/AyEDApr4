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


#ifndef DYNAMICSEQUENCE_H
#define DYNAMICSEQUENCE_H


#include <iostream>
#include <vector>
#include "sequence.h"


template <class key>
class DynamicSequence : public Sequence<key> {
 public:
  DynamicSequence() { data_.clear(); }
  ~DynamicSequence() {}
  bool Search(const key& k) const override;
  bool Insert(const key& k) override;
  void Print() const;

  private:
  std::vector<key> data_;
};



template <class key>
bool DynamicSequence<key>::Search(const key& k) const {
  for (key element : data_) {
    if (element == k) {
      return true;
    }
  }
  return false;
}

template <class key>
bool DynamicSequence<key>::Insert(const key& k) {
  data_.push_back(k);
  return true;
}


template <class key>
void DynamicSequence<key>::Print() const {
  for (key element : data_) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}


#endif  // DYNAMICSEQUENCE_H