# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++20 -Wall

# Source file
SRC := main.cpp
# Output directory and executable name
BIN_DIR := bin
EXE := $(BIN_DIR)/main

# Include directories
INCLUDES := -I.

# Libraries (if any)
LIBS :=

# Windows-specific settings
ifeq ($(OS),Windows_NT)
	# Executable file extension
	EXE := $(BIN_DIR)/main.exe
	# Library directories
	LIBS :=
	# Libraries to link (if any)
	LIBS +=
	# Use mingw32-make for building on Windows
	MAKE := mingw32-make
	# Command for running the executable on Windows
	RUN_COMMAND := $(EXE)
else
	# macOS-specific settings (assuming Clang compiler)
	# Add macOS-specific compiler flags (if any)
	CXXFLAGS +=
	# Add macOS-specific library directories (if any)
	LIBS :=
	# Add macOS-specific libraries to link (if any)
	LIBS +=
	# Use make for building on macOS or other Unix-like systems
	MAKE := make
	# Command for running the executable on macOS and Unix-like systems
	RUN_COMMAND := $(EXE)
endif

all: $(EXE)

$(EXE): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $< -o $@

run: $(EXE)
	$(RUN_COMMAND)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all run clean
