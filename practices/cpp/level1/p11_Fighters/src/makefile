main: main.cpp Animation.o Frame.o Item.o Character.o Director.o Player.o
	clang++ main.cpp Item.o Animation.o Frame.o Character.o Director.o Player.o -F /Library/Frameworks -framework sfml-audio -framework sfml-window -framework sfml-graphics -framework     sfml-system -framework OpenGL -framework GLUT -o main.cpp.out -g

Director.o: Director.cpp Director.h 
	clang++ -I /usr/local/include Director.cpp -c -g

Item.o:	Item.cpp Item.h
	clang++ -I /usr/local/include Item.cpp -c -g

Animation.o: Animation.cpp Animation.h
	clang++ -I /usr/local/include Animation.cpp -c -g

Frame.o: Frame.cpp Frame.h
	clang++ -I /usr/local/include Frame.cpp -c -g

Character.o: Character.cpp Item.h
	clang++ -I /usr/local/include Character.cpp -c -g

Player.o: Item.h Player.cpp
	clang++ -I /usr/local/include Player.cpp -c -g


template: main.cpp
	clang++ -I /usr/local/include -F /Library/Frameworks -framework sfml-audio -framework sfml-window -framework sfml-graphics -framework sfml-system main.cpp -framework OpenGL -framework GLUT -o main.cpp.out: main.cpp

clean: *
	rm *.o
	rm -r *.dSYM
