# Compiler and Archiver
CXX = g++
AR = ar
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

# Directories
INC_DIR = inc
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib

# Library Name
LIB_NAME = libMyMathLib.a
LIB_PATH = $(LIB_DIR)/$(LIB_NAME)

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Default Target
all: $(LIB_PATH)

# Create Static Library
$(LIB_PATH): $(OBJ_FILES) | $(LIB_DIR)
	$(AR) rcs $@ $^

# Compile Source Files into Object Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Directory Rules
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Clean Build Artifacts
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)

.PHONY: all clean
