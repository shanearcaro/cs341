SRC_DIR := ./src
HEAD_DIR := include

EXE:= main
CPPFLAGS = g++ -Iinclude -std=c++17

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

all: $(SRC_DIR)/$(EXE).cpp
	$(CPPFLAGS) $(SRC_FILES) -o $(EXE)

run: $(SRC_DIR)/$(EXE).cpp
	make
	./$(EXE)

clean:
	rm $(PROJ)

# CC = g++ -Iinclude -Isrc
# ARG = -std=c++17
# LINK = main.cpp node.cpp
# PROJ = main

# all: $(PROJ).cpp
# 	$(CC) $(ARG) $(LINK) -o $(PROJ)

# run: $(PROJ).cpp
# 	make all
# 	./$(PROJ)

# clean:
# 	rm $(PROJ)