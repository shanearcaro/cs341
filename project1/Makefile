SRC_DIR := ./src
HEAD_DIR := include

EXE:= main
CPPFLAGS = g++ -Iinclude -std=c++17
OUT_FILE := output.txt

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

all: $(SRC_DIR)/$(EXE).cpp
	$(CPPFLAGS) $(SRC_FILES) -o $(EXE)

run: $(SRC_DIR)/$(EXE).cpp
	make
	./$(EXE)

output: $(SRC_DIR)/$(EXE).cpp
	make
	./$(EXE) > $(OUT_FILE)

clean:
	rm $(PROJ) $(OUT_FILE)
	