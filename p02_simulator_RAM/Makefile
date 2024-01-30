# Universidad de La Laguna
# Escuela Superior de IngIniería y Tecnología
# Grado En IngIniería Informática
# Asignatura: Algoritmos y Estructuras de Datos Avanzadas
# Curso: 2º
# Práctica 1: Big Ints
# Autor: Adrián Mora Rodríguez 
# Correo: alu0101465883@ull.edu.es
# Fecha:  11/02/23
# Archivo MakeFile
# Referencias:
# https://makefiletutorial.com/



CXX = g++						                                      # C++ compiler command
CXXFLAGS = -g -std=c++17 # C++ compiler options 
LDFLAGS =						                                      # Linker options (if any)

# The all target builds all of the programs handled by the makefile.
all: clean p01_MatrixMultiply

p01_MatrixMultiply: src/main.cc

	@echo "Linking $@"
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Compilation complete. $@ is ready to run."

# Indicate that the all and clean targets do not
# correspond to actual files.
.PHONY: all clean targz

# The following rule is effectively built into make and
# therefore need not be explicitly specified:
	@$(CXX) $(CXXFLAGS) -c $<

# The clean target removes all of the executable files
# and object files produced by the build process
# We can use it for additional housekeeping purposes
clean :
	@ rm -f *.o string doc
	@ rm -f p01_MatrixMultiply
	@ rm -rf *~ basura b i
	@ rm -rf a.out
	@ find . -name '*~' -exec rm {} \;
	@ find . -name basura -exec rm {} \;

tar:
	@ tar -cvzf ../targz/p01_Adrian_Mora_Rodriguez.tar.gz .

tarclean:
	@ rm -f ../targz/p01_Adrian_Mora_Rodriguez.tar.gz