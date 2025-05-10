C := gcc
CC := g++
ANTLR_INCLUDE := -I/usr/local/include/antlr4-runtime
ANTLR_LIB := -L/usr/local/lib -lantlr4-runtime
LLVM_VERSION := 14
LLVM_INCLUDE := -I/usr/include/llvm-$(LLVM_VERSION) -I/usr/include/llvm-c-$(LLVM_VERSION)
LLVM_CONFIG := /usr/lib/llvm-$(LLVM_VERSION)/bin/llvm-config
LLVM_LIBS := $(shell $(LLVM_CONFIG) --libs)
LLVM_CXXFLAGS := -std=c++17 -funwind-tables -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS

# Configuration file location
CONFIG_FILE := build/cfg/buildtype

# Default mode
ifeq ("$(wildcard $(CONFIG_FILE))","")
	MODE := release-dynamic
else
	MODE := $(shell cat $(CONFIG_FILE))
endif

# Compiler flags for different modes
DEBUG_CXXFLAGS := -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -g -Og
RELEASE_DYNAMIC_CXXFLAGS := -O2
RELEASE_STATIC_CXXFLAGS := -O2 -static

# Choose the appropriate flags based on the selected mode
ifeq ($(MODE), debug)
	CXXFLAGS := $(LLVM_CXXFLAGS) $(DEBUG_CXXFLAGS)
else ifeq ($(MODE), release-dynamic)
	CXXFLAGS := $(LLVM_CXXFLAGS) $(RELEASE_DYNAMIC_CXXFLAGS)
else ifeq ($(MODE), release-static)
	CXXFLAGS := $(LLVM_CXXFLAGS) $(RELEASE_STATIC_CXXFLAGS)
else
	$(error Invalid mode: $(MODE). Use 'debug', 'release-dynamic', or 'release-static.')
endif

LINK := $(ANTLR_LIB) $(LLVM_LIBS)
SOURCES := $(wildcard src/*.cpp) # This will include main.cpp and all other .cpp files
OBJECTS := $(SOURCES:src/%.cpp=build/obj/%.o)
EXE_NAME := pascc # The single executable to be produced

# Main target - builds the single 'pascc' executable
all: $(EXE_NAME)

$(EXE_NAME): build/obj $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE_NAME) $(LINK) $(CXXFLAGS)

# Ensure the obj and cfg directories exist
build/obj:
	mkdir -p build/obj build/cfg

# Rule for compiling all .cpp files from src/
build/obj/%.o: src/%.cpp | build/obj
	$(CC) $(ANTLR_INCLUDE) $(LLVM_INCLUDE) $(CXXFLAGS) -c $< -o $@
ANTLR4_JAR := /usr/local/lib/antlr4/antlr4-4.13.2-complete.jar 
# Target to generate parser from grammar
antlrs: src/PascalS.g4
	@echo "正在使用 ANTLR JAR: $(ANTLR4_JAR)"
	java -jar $(ANTLR4_JAR) -Dlanguage=Cpp -visitor -no-listener src/PascalS.g4
	@echo "ANTLR Cpp 代码生成完成。"
# Clean target
clean:
	rm -f build/obj/*.o $(EXE_NAME)

config:
	@echo "Current mode: $(MODE)"
	@echo "To change mode, run: make set MODE=<mode>"
	@echo "Available modes: debug, release-dynamic, release-static"

set:
	@echo "$(MODE)" > $(CONFIG_FILE)
	@echo "Build mode set to $(MODE) and saved to $(CONFIG_FILE)"

.PHONY: all clean config set antlrs # Added 'all' and 'antlrs'
