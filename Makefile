name=main
compiler=clang++
compiler_options=-std=c++20 -Wall -Wextra -Weffc++ -O2 -pedantic

run: $(name)
	clear
	./$(name)

build: main.cpp curl.o html.o
	$(compiler) $(compiler_options) -o $(name) main.cpp curl.o -lcurl html.o

curl.o: src/curl.cc
	$(compiler) $(compiler_options) -c src/curl.cc

html.o: src/html.cc
	$(compiler) $(compiler_options) -c src/html.cc

clean: 
	rm -f *.o $(name)

check: $(name)
	valgrind --leak-check=full -s ./$(name)