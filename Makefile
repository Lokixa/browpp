name=main
compiler=clang++
compiler_options=-Wall -Wextra -Weffc++ -O2 -pedantic

all: run

build: main.cpp
	$(compiler) $(compiler_options) -c src/curl.cc
	$(compiler) $(compiler_options) -o $(name) main.cpp curl.o -lcurl

$(name): main.cpp
	$(compiler) $(compiler_options) -c src/curl.cc
	$(compiler) $(compiler_options) -o $(name) main.cpp curl.o -lcurl
	
run: $(name)
	clear
	./$(name)

clean: 
	rm -f curl.o $(name)

check: $(name)
	valgrind --leak-check=full -s ./$(name)