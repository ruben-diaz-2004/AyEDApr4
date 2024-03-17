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
#include <vector>
#include <string>
#include <fstream>


struct parameters {
  int dimension;
  bool two_dim = false;
  int size_x;
  int size_y;
  int cell_type; // 0: Ace110, 1: Ace30, 2: Life23_3, 3: Life51_346
  int border; // 0: open, 1: periodic, 2: reflective, 3: no border
  bool open_type = false;
  std::fstream filename;
  bool initial_file = false;
};

parameters parse_args(int argc, char* argv[]) {
  std::vector<std::string> args(argv + 1, argv + argc);
  parameters options;
  for (auto it = args.begin(), end = args.end(); it != end; ++it) {
    if (*it == "-dim") {
      options.dimension = std::stoi(*++it);
      if (options.dimension == 2) {
        options.two_dim = true;
      }
    }
    else if (*it == "-cell") {
      if (*++it == "Ace110") {
        options.cell_type = 0;
      } else if (*it == "Ace30") {
        options.cell_type = 1;
      } else if (*it == "Life23_3") {
        options.cell_type = 2;
      } else if (*it == "Life51_346") {
        options.cell_type = 3;
      }
    }
    else if (*it == "-size") {
      options.size_x = std::stoi(*++it);
      if (options.two_dim) options.size_y = std::stoi(*++it);
    } else if (*it == "-border") {
        if (*++it == "open") {
          options.border = 0;
          if (*++it == "1") {
            options.open_type = true;
          }
        } else if (*it == "periodic") {
          options.border = 1;
        } else if (*it == "reflective") {
          options.border = 2;
        } else if (*it == "noborder") {
          options.border = 3;
        }
    } else if (*it == "-init") {
      options.filename = std::fstream(*++it);
      options.initial_file = true;
    }
    else {
      std::cerr << "Error: argumento no válido" << std::endl;
    }
  }
  return options;
}

  

