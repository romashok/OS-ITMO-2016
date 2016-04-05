all: sigusr

sigusr: sigusr.o
	gcc -s $< -o $@

sigusr.o: sigusr.c
	gcc -c $< -o $@

clean:
	rm -f sigusr.o sigusr
