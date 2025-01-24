BIN=./bin
SRC=./src
CC=g++
CFLAGS=-std=c++17 -fsanitize=address -fsanitize=undefined -Wall -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -O2

SOURCES = $(wildcard $(SRC)/*.cpp)
EXECS = $(patsubst $(SRC)/%.cpp,$(BIN)/%,$(SOURCES))

all: $(EXECS)

# Create bin directory if it doesn't exist
$(BIN):
	@mkdir -p $@

# Compile rule with directory dependency
$(BIN)/%: $(SRC)/%.cpp | $(BIN)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "Cleaning..."
	@if [ -d "$(BIN)" ]; then \
		find "$(BIN)" -mindepth 1 -not -name '.gitkeep' -delete; \
	fi
	@echo "Removed all binaries!"

.PHONY: all clean
