# \/ LEFT TO MIGRATE \/
clean: 
	rm -f *.o $(name)

check: $(name)
	@valgrind --leak-check=full -s ./$(name)