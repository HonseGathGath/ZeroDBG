all: loader target

loader: main.c
	gcc -g main.c -o bin/debugger

target: target.c
	gcc -g target.c -o bin/target

clean:
	rm -rf bin/*
