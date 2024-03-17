/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 19/02/2024
  * @brief Juego de la vida
  */

#include <iostream>
#include <fstream>
#include "parameters.cc"
#include "dispersionfunction.h"
#include "dispersiontypes.h"
#include "explorationfunction.h"
#include "explorationtypes.h"
#include "sequence.h"
#include "dynamicsequence.h"
#include "staticsequence.h"
#include "hashtable.h"
#include "nif.h"

#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char *argv[]) {
  parameters options = parse_args(argc, argv);

  std::cout << "Options menu:" << std::endl << "'i' to insert key.\n's' to search key.\n'x' to exit.\n";

  DispersionFunction<Nif>* dispersion;
  switch(options.fd_code) {
    case 0:
      dispersion = new ModuleDispersion<Nif>(options.tablesize);
      break;
    case 1:
      dispersion = new SumDispersion<Nif>(options.tablesize);
      break;
    case 2:
      dispersion = new PseudoRandomDispersion<Nif>(options.tablesize);
      break;
  }


  ExplorationFunction<Nif>* exploration;
  if (options.close_dispersion) {
    switch(options.exploration_code) {
      case 0:
        exploration = new LinearExploration<Nif>(options.tablesize);
        break;
      case 1:
        exploration = new QuadraticExploration<Nif>(options.tablesize);
        break;
      case 2:
        exploration = new DoubleDispersion<Nif>(options.tablesize, dispersion);
        break;
      case 3:
        exploration = new ReDispersion<Nif>(options.tablesize);
        break;
    }
  }

  HashTable<Nif>* hash_table;
  // if (options.close_dispersion) {
  //   hash_table = new HashTable<Nif, 
  // } else {
  //   hash_table = new HashTable<Nif,
  // }
  



  bool running = true;
  char stop;
  long clave;
  while(running) {
    hash_table->Print();
    std::cin >> stop;
    switch(stop) {
      case 'i':
        std::cin >> clave;
        hash_table->Insert(clave);
        break;
      case 's':
        std::cin >> clave;
        if (hash_table->Search(clave)) {
          std::cout << "Key found." << std::endl;
        } else {
          std::cout << "Key not found." << std::endl;
        }
        break;
      case 'x':
        running = false;
        break;
    }
  }

  return 0;
}