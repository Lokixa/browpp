name=br
compiler=clang++
compiler_options=-std=c++20 -Wall -Wextra -Weffc++ -pedantic

run: $(name)
	@clear
	./$(name)

build: main.cpp curl.o html.o
	$(compiler) $(compiler_options) -o $(name) main.cpp curl.o -lcurl html.o
	rm *.o

curl.o: src/curl.cc
	@$(compiler) $(compiler_options) -c src/curl.cc

html.o: src/html.cc
	@$(compiler) $(compiler_options) -c src/html.cc

test: curl.o html.o
	@$(compiler) -std=c++20 tests/curl_test.cpp curl.o -lcurl -o curl_test
	@./curl_test || true
	@rm curl_test

	@$(compiler) -std=c++20 tests/html_test.cpp html.o -o html_test
	@./html_test || true
	@rm html_test

	@rm *.o

clean: 
	rm -f *.o $(name)

check: $(name)
	@valgrind --leak-check=full -s ./$(name)