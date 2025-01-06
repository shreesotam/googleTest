# Compiler and Linker
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# MyMathLib Directories
MYMATHLIB_DIR = ../MyMathLib
MYMATHLIB_INC = $(MYMATHLIB_DIR)/inc
MYMATHLIB_LIB = $(MYMATHLIB_DIR)/lib/libMyMathLib.a

# Files
SRC_FILES = $(SRC_DIR)/main.cpp
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
TARGET = $(BIN_DIR)/app

# Default Target
all: $(TARGET)

# Link Executable
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(MYMATHLIB_INC) -o $@ $^ $(MYMATHLIB_LIB)

# Compile Main Source Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(MYMATHLIB_INC) -c $< -o $@

# Directory Rules
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean Build Artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
