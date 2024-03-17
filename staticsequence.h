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
  StaticSequence();
  ~StaticSequence();
  bool Search(const key& k) const override;
  bool Insert(const key& k) override;
  void Initialize(unsigned size);
  void Print() const;
  bool IsFull() const; 

  private:
  unsigned size_;
  key* data_;
};


template <class key>
StaticSequence<key>::StaticSequence() {
  size_ = 0;
  data_ = nullptr;
}


template <class key>
void StaticSequence<key>::Initialize(unsigned size) {
  size_ = size;
  data_ = new key[size_];
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
    return false;
  }
  for (unsigned i = 0; i < size_; i++) {
    if (data_[i] == k) {
      return false;
    }
  }
  for (unsigned i = 0; i < size_; i++) {
    if (long(data_[i]) == 0) {
      data_[i] = k;
      return true;
    }
  }
}



template <class key>
void StaticSequence<key>::Print() const {
  for (unsigned i = 0; i < size_; i++) {
    std::cout << data_[i] << " ";
  }
  std::cout << std::endl;
}



template <class key>
bool StaticSequence<key>::IsFull() const {
  for (unsigned i = 0; i < size_; i++) {
    if (long(data_[i]) == 0) {
      return false;
    }
  }
  return true;
}


#endif  // STATICSEQUENCE_H