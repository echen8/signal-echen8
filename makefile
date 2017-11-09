all: main.c
	gcc -o signal main.c
run: all
	./signal