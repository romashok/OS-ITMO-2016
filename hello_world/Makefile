all: hello_world
clean:
	rm -f hello_world hello_world.o
hello_world.o: hello_world.c
	gcc -c $< -o $@
hello_world: hello_world.o
	gcc -s $< -o $@
