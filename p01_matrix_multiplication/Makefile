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
LDFLAGS =	-lstdc++			                                      # Linker options (if any)
SRCDIR = src
OBJDIR = obj
BINDIR = .

SOURCES := $(wildcard $(SRCDIR)/*.cc)
OBJECTS := $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)/p01_MatrixMultiply

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

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