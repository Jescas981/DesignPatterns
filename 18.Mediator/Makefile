# Directories
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
OBJ_DIR	= obj
INC_DIR	= include
# Compiler
CXX = g++
INC_DIRS = -I$(INC_DIR)
CXX_FLAGS = -Wall -Wextra -pedantic -std=c++17 $(INC_DIRS)
# Commands
MKDIR = mkdir -p
RM = rm -rf
# Variables
CPP_DIRS = $(wildcard $(SRC_DIR)/*/)
CPPS = $(wildcard $(SRC_DIR)/**/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPPS))
LIBS = $(patsubst $(SRC_DIR)/%/,$(LIB_DIR)/lib%.a,$(CPP_DIRS))

all: $(OBJS) $(LIBS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(MKDIR) $(@D)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(LIB_DIR)/lib%.a : $(wildcard $(OBJ_DIR)/%/*.o)
	$(MKDIR) $(dir $@)
	ar rcs $@ $<

info:
	$(info $(CPP_DIRS))
	$(info $(CPPS))
	$(info $(OBJS))
	$(info $(LIBS))
	$(info )


.PHONY : info