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


#ifndef NIF_H
#define NIF_H


#include <iostream>


class Nif {
  public:
  Nif();
  Nif(const long& nif);

  // Operador de comparación
  void operator=(int num);

  // Conversión implícita a long
  operator long() const;

  private:
  long nif_;
};




#endif  // NIF_H


// template <class key, class Container>
// HashTable<key, Container>::HashTable(unsigned tablesize, DispersionFunction<key>& fd, ExplorationFunction<key>& fe, unsigned blockSize) : fd_(fd), fe_(fe) {
//   tableSize_ = tablesize;
//   blockSize_ = blockSize;
//   table_ = new Container[tableSize_];
//   for (unsigned i = 0; i < tableSize_; i++) {
//     table_[i].Initialize(blockSize_);
//   }
// }


// template <class key, class Container>
// HashTable<key, Container>::~HashTable() {
//   for (unsigned i = 0; i < tableSize_; i++) {
//     delete table_[i];
//   }
// }


// template <class key, class Container>
// bool HashTable<key, Container>::Search(const key& k) const {
//   unsigned position = fd_(k);
//   unsigned intento{0};
//   bool runnig{true};
//   while (runnig) {
//     if (table_[position].Search(k)) {
//       return true;
//     }
//     if (!table_[position].IsFull()) {
//       runnig = false;
//     }
//     position = fe_(k, intento);
//     intento++;
//   }
// }


// template <class key, class Container>
// bool HashTable<key, Container>::Insert(const key& k) {
//   unsigned position = fd_(k);
//   unsigned intento{0};
//   bool runnig{true};
//   while (runnig) {
//     if (table_[position].Insert(k)) {
//       return true;
//     }
//     if (!table_[position].IsFull()) {
//       runnig = false;
//     }
//     position = fe_(k, intento);
//     intento++;
//   }
// }



// template <class key, class Container>
// void HashTable<key, Container>::Print() const {
//   for (unsigned i = 0; i < tableSize_; i++) {
//     std::cout << "Posición " << i << ": ";
//     table_[i].Print();
//     std::cout << std::endl;
//   }
// }