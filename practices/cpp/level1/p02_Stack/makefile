main: main.o Stack.o
	clang++ -g main.o Stack.o -o main.out
	make clean
main.o: main.cpp Stack.h
	clang++ -c -g main.cpp
Stack.o: Stack.cpp Stack.h
	clang++ -c -g Stack.cpp
clean:	Stack.o main.o
	rm Stack.o main.o
