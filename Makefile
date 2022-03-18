name=main
compiler_options = -Wall -Wextra -Weffc++ -O2 -pedantic
libs_location = ./lib/show
libs = -lshow

all: build $(name).exe
	./$(name).exe

run: $(name).exe
	./$(name).exe

build: compile_all clean

compile_all: $(name).cpp #build_libs
	#g++ $(compiler_options) -c $(name).cpp -o $(name).o
	#g++ -o $(name).exe $(name).o -L$(libs_location) $(libs)
	g++ -o $(name).exe $(name).cpp

#build_libs: 
	#make -C $(libs_location) all

clean: $(name).o
	rm $(name).o

.PHONY: all build build_libs clean
