CXX=gcc

CFLAGS = -c -Wall -Werror -std=c99

FLAGS = -Wall -Werror -std=c99

OBJECTS = build/main.o build/generate_number.o build/user_input.o build/check_user_guess.o

.PHONY: clean all bin build run

all: bin build bin/key

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/main.o 

build/generate_number.o: src/generate_number.c 
	$(CXX) $(CFLAGS) src/generate_number.c -o build/generate_number.o

build/user_input.o: src/user_input.c 
	$(CXX) $(CFLAGS) src/user_input.c -o build/user_input.o

build/check_user_guess.o: src/check_user_guess.c
	$(CXX) $(CFLAGS) src/check_user_guess.c -o build/check_user_guess.o

build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin

run:
	./bin/key