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
  int tablesize;
  int fd_code;  // 0: mod, 1: suma, 2: pseudoaleatorio
  int dispersion_technique; // 0: close, 1: open
  bool close_dispersion = false;
  int blocksize;
  int exploration_code; // 0: linear, 1: quadratic, 2: double, 3: rehashing
};

parameters parse_args(int argc, char* argv[]) {
  std::vector<std::string> args(argv + 1, argv + argc);
  parameters options;
  for (auto it = args.begin(), end = args.end(); it != end; ++it) {
    if (*it == "-ts") {
      options.tablesize = std::stoi(*++it);
    }
    else if (*it == "-fd") {
      if (*++it == "mod") {
        options.fd_code = 0;
      } else if (*it == "suma") {
        options.fd_code = 1;
      } else if (*it == "pseudoaleatorio") {
        options.fd_code = 2;
      }
    }
    else if (*it == "-hash") {
      if (*++it == "close") {
        options.dispersion_technique = 0;
        options.close_dispersion = true;
      } else if (*it == "open") {
        options.dispersion_technique = 1;
      }
    }
    else if (*it == "-bs") {
      if (options.close_dispersion == false) {
        std::cerr << "Error: no se puede especificar el tamaño de bloque si la técnica de dispersión no es cerrada" << std::endl;
        exit(EXIT_SUCCESS);
      }
      options.blocksize = std::stoi(*++it);
    }
    else if (*it == "-fe") {
      if (*++it == "linear") {
        options.exploration_code = 0;
      } else if (*it == "quadratic") {
        options.exploration_code = 1;
      } else if (*it == "double") {
        options.exploration_code = 2;
      } else if (*it == "rehashing") {
        options.exploration_code = 3;
      }
    }
    else {
      std::cerr << "Error: argumento no válido" << std::endl;
    }
  }
  return options;
}

  

