CXX_FLAGS := -std=c++17 -g #-Ofast # Quitar -Ofast para debug
PRE_FLAGS := -MMD -MP

# Project directory structure
SRC := src
LIB := lib
INC := include
MAINFILE := $(SRC)/main.cc

# Build directories and output
TARGET := p08_maximum_diversity_problem
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
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cc files
$(BUILD)/%.o: $(SRC)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

clean :
	@ rm -f *.o string doc
	@ rm -f p08_maximum_diversity_problem
	@ rm -rf *~ basura b i
	@ rm -rf a.out
	@ rm -f $(OBJECTS) $(EXECUTABLE)
	@ rm -f lib/*.o
	@ find . -name '*~' -exec rm {} \;
	@ find . -name basura -exec rm {} \;

tar:
	@ tar -cvzf ../targz/p08_Adrian_Mora_Rodriguez.tar.gz .

cleanbuild:
	@ rm -rf build/*

tarclean:
	@ rm -f ../targz/p08_Adrian_Mora_Rodriguez.tar.gz

remake :
	@ make clean
	@ make cleanbuild
	@ make
