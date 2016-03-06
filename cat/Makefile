all: cat

cat: cat.o
	gcc -s $< -o $@

cat.o: cat.c
	gcc -c $< -o $@

clean:
	rm -f cat.o cat
