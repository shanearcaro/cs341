CC = g++
ARG = -std=c++17
PROJ = main

all: $(PROJ).cpp
	$(CC) $(ARG) $(PROJ).cpp dfa.cpp -o $(PROJ)

run: $(PROJ).cpp
	make all
	./$(PROJ)

clean:
	rm $(PROJ)