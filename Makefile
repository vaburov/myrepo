CC = g++
SOURCES = abcsort.cpp
EXECUTABLE = abcsort.app
#OBJECTS=$(SOURCES:.cpp=.o)

all: build run
build:  
	@$(CC) $(SOURCES) -o $(EXECUTABLE)
	@echo abcsort.app program building done.
run:
	@echo Running program:
	@./$(EXECUTABLE)
