main: main.o Rect.o Circle.o Tri.o Canvas.o
	clang++ -o main.cpp.out main.o Rect.o Circle.o Tri.o Canvas.o
main.o: main.cpp Canvas.h
	clang++ -c main.cpp Canvas.h -std=c++11
Rect.o: Rect.cpp Canvas.h
	clang++ -c Rect.cpp Canvas.h -std=c++11
Circle.o: Circle.cpp Canvas.h
	clang++ -c Circle.cpp Canvas.h -std=c++11
Tri.o: Tri.cpp Canvas.h
	clang++ -c Tri.cpp Canvas.h -std=c++11
Canvas.o: Canvas.cpp Canvas.h
	clang++ -c Canvas.cpp Canvas.h -std=c++11

clean: *.o
	rm *.o
