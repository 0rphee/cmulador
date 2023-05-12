# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++20 -Wall

# Source file and output executable
SRC := main.cpp
EXE := main

# Include directories
INCLUDES := -I.

# Libraries (if any)
# LIBS :=

# Windows-specific settings
ifeq ($(OS),Windows_NT)
	# Executable file extension
	EXE := main.exe
	# Library directories
	# LIBS :=
	# Libraries to link (if any)
	# LIBS +=
	# Use mingw32-make for building on Windows
	MAKE := mingw32-make
	# Command for running the executable on Windows
	RUN_COMMAND := ./$(EXE)
else
	# macOS-specific settings (assuming Clang compiler)
	# Add macOS-specific compiler flags (if any) -mmacosx-version-min=10.9
	CXXFLAGS += 
	# Add macOS-specific library directories (if any) -Lpath/to/libraries
	# LIBS := 
	# Add macOS-specific libraries to link (if any) -llibrary_name
	# LIBS += 	# Use make for building on macOS or other Unix-like systems
	MAKE := make
	# Command for running the executable on macOS and Unix-like systems
	RUN_COMMAND := ./$(EXE)
endif

all: $(EXE)

$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $< -o $@

run: $(EXE)
	$(RUN_COMMAND)

clean:
	rm -f $(EXE)

.PHONY: all run clean

