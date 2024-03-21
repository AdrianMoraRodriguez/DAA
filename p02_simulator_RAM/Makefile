CC = g++
CFLAGS = -std=c++17 -g
LDFLAGS = -lstdc++
SRCDIR = src
OBJDIR = lib
BINDIR = .

SOURCES := $(wildcard $(SRCDIR)/*.cc)
OBJECTS := $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)/p02_simulator_RAM

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@ $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@ mkdir -p $(OBJDIR)
	@ echo "Compiling $<..."
	@ $(CC) $(CFLAGS) -c -o $@ $<

clean :
	@ rm -f *.o string doc
	@ rm -f p01_MatrixMultiply
	@ rm -rf *~ basura b i
	@ rm -rf a.out
	@ rm -f $(OBJECTS) $(EXECUTABLE)
	@ rm -f lib/*.o
	@ find . -name '*~' -exec rm {} \;
	@ find . -name basura -exec rm {} \;

tar:
	@ tar -cvzf ../targz/p02_Adrian_Mora_Rodriguez.tar.gz .

tarclean:
	@ rm -f ../targz/p02_Adrian_Mora_Rodriguez.tar.gz
