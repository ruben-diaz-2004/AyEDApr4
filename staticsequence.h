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


#ifndef STATICSEQUENCE_H
#define STATICSEQUENCE_H


#include <iostream>
#include "sequence.h"


template <class key>
class StaticSequence : public Sequence<key> {
 public:
  StaticSequence(unsigned size);
  ~StaticSequence();
  bool Search(const key& k) const override;
  bool Insert(const key& k) override;
  virtual bool IsFull() const = 0; // This is a pure virtual function ???????????????????????????????????????

  private:
  unsigned size_;
  key* data_[];
};


template <class key>
StaticSequence<key>::StaticSequence(unsigned size) : size_(size) {
  for (unsigned i = 0; i < size_; i++) {
    data_[i] = 0;
  }
}

template <class key>
StaticSequence<key>::~StaticSequence() {
  delete[] data_;
}

template <class key>
bool StaticSequence<key>::Search(const key& k) const {
  for (unsigned i = 0; i < size_; i++) {
    if (data_[i] == k) {
      return true;
    }
  }
  return false;
}

template <class key>
bool StaticSequence<key>::Insert(const key& k) {
  if (IsFull()) {
    throw std::out_of_range("Sequence is full");
  }
  for (unsigned i = 0; i < size_; i++) {
    if (data_[i] == k) {
      return false;
    }
  }
  for (unsigned i = 0; i < size_; i++) {
    if (data_[i] == 0) {
      data_[i] = k;
      return true;
    }
  }
}


#endif  // STATICSEQUENCE_H