main: main.cpp Animation.o Item.o Character.o Director.o Player.o Bullet.o Room.o 
	clang++ main.cpp Item.o Animation.o Frame.o Character.o Director.o Player.o Bullet.o Room.o \
		Bag.o Prop.o Magic.o Skill.o Buff.o\
		-F /Library/Frameworks -framework sfml-audio -framework sfml-window -framework sfml-graphics \
		-framework sfml-system -framework OpenGL -framework GLUT -o main.cpp.out -g

Director.o: Director.cpp Director.h 
	clang++ -I /usr/local/include Director.cpp -c -g

Player.o: Player.h Player.cpp Item.o Character.o
	clang++ -I /usr/local/include Player.cpp -c -g

Character.o: Character.cpp Character.h Item.o
	clang++ -I /usr/local/include Character.cpp -c -g

Bullet.o: Bullet.h Bullet.cpp Item.o
	clang++ -I /usr/local/include Bullet.cpp -c -g

Room.o: Room.h Room.cpp Item.o
	clang++ -I /usr/local/include Room.cpp -c -g

Item.o:	Item.cpp Item.h Animation.o Concept.h Bag.o Prop.o Magic.o Skill.o Buff.o
	clang++ -I /usr/local/include Item.cpp -c -g

Animation.o: Animation.cpp Animation.h Frame.o
	clang++ -I /usr/local/include Animation.cpp -c -g

Frame.o: Frame.cpp Frame.h
	clang++ -I /usr/local/include Frame.cpp -c -g

Buff.o: Buff.cpp Buff.h
	clang++ -I /usr/local/include/ Buff.cpp -c -g

Prop.o: Prop.cpp Prop.h
	clang++ -I /usr/local/include/ Prop.cpp -c -g

Bag.o: Bag.cpp Bag.h
	clang++ -I /usr/local/include/ Bag.cpp -c -g

Magic.o: Magic.cpp Magic.h
	clang++ -I /usr/local/include/ Magic.cpp -c -g

Skill.o: Skill.cpp Skill.h
	clang++ -I /usr/local/include/ Skill.cpp -c -g


template: main.cpp
	clang++ -I /usr/local/include -F /Library/Frameworks -framework sfml-audio -framework sfml-window -framework sfml-graphics -framework sfml-system main.cpp -framework OpenGL -framework GLUT -o main.cpp.out: main.cpp

clean: *
	rm *.o
	rm -r *.dSYM
