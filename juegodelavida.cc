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
#include "Cell.h"
#include "Lattice.h"
#include "1Dtypes.h"
#include "2Dtypes.h"
#include "Acetypes.h"
#include "Lifetypes.h"
#include "my_vector.h"
#include "FactoryCell.h"
#include "Factorytypes.h"
#include "position.h"

#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char *argv[]) {
  parameters options = parse_args(argc, argv);

  std::cout << "Options menu:" << std::endl << "'x' to exit.\n's' to save configuration.\n'n' to show next generation.\n";
  std::cout << "'L' to show next 5 generations.\n'c' to show population.\n";


  FactoryCell* factory;
  switch(options.cell_type) {
    case 0:
      factory = new FactoryCellACE110();
      break;
    case 1:
      factory = new FactoryCellACE30();
      break;
    case 2:
      factory = new FactoryCellLife23_3();
      break;
    case 3:
      factory = new FactoryCellLife51_346();
      break;
  }


  Lattice* lattice;
  switch(options.border) {
    case 0:
      if (options.initial_file) {
        lattice = new Lattice1D_open(options.filename, *factory, options.open_type);
      } else {
        lattice = new Lattice1D_open(options.size_x, *factory, options.open_type);
      }
      break;
    case 1:
      if (options.initial_file) {
        lattice = new Lattice1D_periodic(options.filename, *factory);
      } else {
        lattice = new Lattice1D_periodic(options.size_x, *factory);
      }
      break;
    case 2:
      if (options.initial_file) {
        lattice = new Lattice2D_reflective(options.filename, *factory);
      } else {
        lattice = new Lattice2D_reflective(options.size_x, options.size_y, *factory);
      }
      break;
    case 3:
      if (options.initial_file) {
        lattice = new Lattice2D_NoBorder(options.filename, *factory);
      } else {
        lattice = new Lattice2D_NoBorder(options.size_x, options.size_y, *factory);
      }
      break;
  }
  

  std::cout << *lattice << std::endl;
  bool population = false;
  bool running = true;
  char stop;
  while(running) {
    std::cin >> stop;
    switch (stop) {
      case 'x':
        running = false;
        break;
      case 'n': // Calcula y muestra la siguiente generación
        lattice->nextGeneration();
        if (population) {
          std::cout << lattice->Population() << std::endl;
        } else {
            std::cout << *lattice << std::endl;
          }
        break;
      case 'L': // Calcula y muestra las siguientes 5 generaciones
        for (int i = 0; i < 5; i++) {
          lattice->nextGeneration();
          if (population) {
            std::cout << lattice->Population() << std::endl;
          } else {
              std::cout << *lattice << std::endl;
            }
        }
        break;
      case 'c': // Se muestra la población (número de células vivas) actual
        population = (population) ? false : true;
        break;
      case 's': // Guarda la configuración actual en un fichero
        std::string file_name;
        std::cin >> file_name;
        std::ofstream output_file{file_name};
        output_file << *lattice;
        output_file.close();
        break;
    }
  }

  return 0;
}