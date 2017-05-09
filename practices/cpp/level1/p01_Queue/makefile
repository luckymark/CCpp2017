main: main.o Queue.o
	clang++ main.o Queue.o -o main.out
	make clean
Queue.o: Queue.h Queue.cpp
	cc Queue.cpp -c
main.o: main.cpp Queue.h
	cc main.cpp -c
clean:
	rm main.o Queue.o
