#ifndef FRAME_H_
#define FRAME_H_


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <utility>
using namespace std;


class Frame{ //帧
	private:
		sf::Image 	image;				
		sf::Texture 	texture;			
		sf::Sprite 	sprite;				

		float 		x[2];				
		float 		y[2];				
								

		sf::Vector2f  	del_position;			
								
								

		sf::Vector2f 	core_position;			
								
		sf::Vector2f 	length;

		void update_draw_position(); 			


		int impact_flag;				
		int hurt_flag;
	public:
		Frame();
		Frame( 	string image_file_name,			
			string image_info_flie_name );		

		//void initlize();				
		void display(sf::RenderWindow *win);				
		int is_in(const sf::Vector2f &point);		
		int is_in(Frame *other);

		void set_image(string image_file_name);		
		void set_image_info(string image_info_flie_name);
		void set_core_position(sf::Vector2f position); 	
		void set_length(sf::Vector2f len);
		void set_scale(sf::Vector2f scale);

		~Frame(){}
};

#endif
