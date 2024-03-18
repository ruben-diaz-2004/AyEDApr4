# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# 
# @author Rubén Díaz Marrero
# @date 18/12/2023
# 

CXX = g++
CXXFLAGS = -std=c++17 -g 



all: TablaHash

TablaHash: main_hash_table.cc nif.cc
		$(CXX) $(CXXFLAGS) -o $@ $^
	

	
.PHONY: all clean
clean:
		rm -f TablaHash