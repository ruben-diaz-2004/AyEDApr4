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



#include "nif.h"
#include <iostream>
#include <ctime>

/**
 * Constructor por defecto que inicializa el NIF a un valor aleatorio
 */
Nif::Nif() {
  srand(time(NULL));
    nif_ = rand() % 1000000000;
}


/**
 * Constructor que inicializa el NIF a un valor dado
 * @param nif Valor del NIF
 */
Nif::Nif(const long& nif) {
  nif_ = nif;
}



bool Nif::operator>(const Nif& nif) const {
  return nif_ > long(nif);
}

bool Nif::operator<(const Nif& nif) const {
  return nif_ < long(nif);
}

bool Nif::operator==(const Nif& nif) const {
  return nif_ == long(nif);
}

bool Nif::operator!=(const Nif& nif) const {
  return nif_ != long(nif);
}


void Nif::operator/=(const int& pedro) {
  nif_ /= pedro;
}



/**
 * Conversión implícita a long
 * @return Valor del NIF
 */
Nif::operator long() const {
  return nif_;
}