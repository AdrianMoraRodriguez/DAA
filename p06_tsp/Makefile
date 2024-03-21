CXX_FLAGS := -std=c++17 -g
PRE_FLAGS := -MMD -MP

# Project directory structure
SRC := src
LIB := lib
INC := include
MAINFILE := $(SRC)/main.cc

# Build directories and output
TARGET := p06_tsp
BUILD := build

# Library search directories and flags
EXT_LIB :=
LDFLAGS :=
LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# Include directories
INC_DIRS := $(INC) $(shell find $(SRC) -type d) 
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Construct build output and dependency filenames
SRCS := $(shell find $(SRC) -name *.cc)
OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# Build task
build: clean all

# Main task
all: $(TARGET)

# Task producing target from built files
$(TARGET): $(OBJS)
	@echo "🚧 Building..."
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cc files
$(BUILD)/%.o: $(SRC)/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

generador: $(BUILD)/generador.o
	@echo "🚧 Building generador..."
	g++ $(BUILD)/generador.o -o generador/generador

cleanGenerador:
	@ rm -f generador/generador
	@ rm -f $(BUILD)/generador.o

clean :
	@ rm -f *.o string doc
	@ rm -f p06_tsp
	@ rm -rf *~ basura b i
	@ rm -rf a.out
	@ rm -f $(OBJECTS) $(EXECUTABLE)
	@ rm -f lib/*.o
	@ find . -name '*~' -exec rm {} \;
	@ find . -name basura -exec rm {} \;

tar:
	@ tar -cvzf ../targz/p06_Adrian_Mora_Rodriguez.tar.gz .

tarclean:
	@ rm -f ../targz/p06_Adrian_Mora_Rodriguez.tar.gz

remake :
	@ make clean
	@ make
