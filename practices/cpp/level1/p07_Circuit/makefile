main: main.o Circuit.o Fan.o Light.o Power.o Switch.o
	clang++ -o main.out main.o Circuit.o Fan.o Light.o Power.o Switch.o
main.o: main.cpp
	clang++ -c main.cpp
Circuit.o: Circuit.cpp Circuit.h
	clang++ -c Circuit.cpp
Fan.o: Fan.cpp Circuit.h
	clang++ -c Fan.cpp
Power.o: Power.cpp Circuit.h
	clang++ -c Power.cpp
Light.o: Light.cpp Circuit.h
	clang++ -c Light.cpp
Switch.o: Switch.cpp Circuit.h
	clang++ -c Switch.cpp

clean: *.o
	rm *.o
