#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main(){
	sf::VertexArray triangle(sf::Triangles, 3);

	// define the position of the triangle's points
	triangle[0].position = sf::Vector2f(10, 10);
	triangle[1].position = sf::Vector2f(100, 10);
	triangle[2].position = sf::Vector2f(100, 100);

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;

	sf::RenderWindow window;
	sf::Event event;
	window.create(sf::VideoMode(800,800), "My window");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(true);
	while(window.isOpen()){
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
			}
		}
		window.clear(sf::Color(100,100,100));

		window.draw(triangle);

		window.display();
	}
	return 0;
}
