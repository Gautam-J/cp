BIN=./bin
SRC=./src
CC=g++

SOURCES = $(wildcard $(SRC)/*.cpp)
EXECS = $(patsubst $(SRC)/%.cpp,$(BIN)/%,$(SOURCES))

all: $(EXECS)

$(BIN)/%:  $(SRC)/%.cpp
	$(CC) $(INC) $< -o $@ $(LIBS)
