CXX=gcc

CFLAGS = -c -Wall -Werror -std=c99

FLAGS = -Wall -Werror -std=c99

OBJECTS = build/src/main.o build/src/generate_number.o build/src/user_input.o build/src/check_user_guess.o

TEST_OBJECTS = build/test/main.o build/test/tests.o build/src/user_input.o build/src/check_user_guess.o

.PHONY: clean all bin build run

all: prog test

prog: bin build bin/key

test: bin build bin/key_test
	bin/key_test

bin/key_test: $(TEST_OBJECTS)
	$(CXX) $(FLAGS) $(TEST_OBJECTS) -o bin/key_test

build/test/main.o: test/main.c
	$(CXX) $(CFLAGS) test/main.c -I thirdparty/ -I src/ -o build/test/main.o

build/test/tests.o: test/tests.c
	$(CXX) $(CFLAGS) test/tests.c -I thirdparty/ -I src/ -o build/test/tests.o

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/src/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/src/main.o 

build/src/generate_number.o: src/generate_number.c 
	$(CXX) $(CFLAGS) src/generate_number.c -o build/src/generate_number.o

build/src/user_input.o: src/user_input.c 
	$(CXX) $(CFLAGS) src/user_input.c -o build/src/user_input.o

build/src/check_user_guess.o: src/check_user_guess.c
	$(CXX) $(CFLAGS) src/check_user_guess.c -o build/src/check_user_guess.o

build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin

run:
	./bin/key