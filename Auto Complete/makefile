#Makefile

#Compiler
CXX = g++

#Flags
COMPILE_FLAG = -std=c++11

#Path
SRC_PATH = ./src/auto_complete.cpp
INCLUDE_PATH = ./include/dictionary.h

#Executable
BIN_NAME = ./build/at_cp

vector: $(SRC_PATH) $(INCLUDE_PATH)
	$(CXX) $(COMPILE_FLAG) $(SRC_PATH) $(INCLUDE_PATH) -o $(BIN_NAME)