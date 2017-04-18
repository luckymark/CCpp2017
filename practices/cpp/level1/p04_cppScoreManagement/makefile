main: main.o List.o Student.o UI.o IO.o
	clang++ -o main.cpp.out main.o List.o Student.o UI.o IO.o -g -lcurses
	make clean
List.o: List.h Student.h UI.h IO.h List.cpp
	clang++ -c List.cpp -Wc++11-extensions -std=c++11
Student.o: Student.h UI.h Student.cpp IO.h
	clang++ -c Student.cpp -std=c++11 -Wc++11-extensions
UI.o: UI.h UI.cpp 
	clang++ -c UI.cpp
IO.o: List.h UI.h IO.h IO.cpp
	clang++ -c IO.cpp
main.o: IO.h UI.h main.cpp
	clang++ -c main.cpp
clean: main.o List.o Student.o UI.o IO.o
	rm main.o List.o Student.o UI.o IO.o

debug: main.cpp Student.h Student.cpp List.h List.cpp UI.h UI.cpp IO.h IO.cpp
	clang++ -o main.cpp.out -g main.cpp Student.cpp List.cpp UI.cpp IO.cpp -lcurses -Wc++11-extensions -std=c++11
