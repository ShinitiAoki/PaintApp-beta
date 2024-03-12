TARGET = noteapp
CC = g++
SRC = $(wildcard ./*.cpp)
HEADERS = $(wildcard ./*.hpp)
OBJ = $(SRC:.cpp=.o)
FLAGS = -lGL -lGLU -lglut

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f main.o noteapp