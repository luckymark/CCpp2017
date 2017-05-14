/******************************************************************************************
  1) 我们需要在播放动画的同时，对物件之间的碰撞进行判断。带着这样的目的而写了这个类

  2) 所以这个header的功能是这个虚拟世界的核心, 在这个世界里的一切物体想要发生相互作用的话，
     都必须要经由这个header来实现。

  3) 我们将一切的相互作用都看作一种动画。每个动画是物件(item)的一个数据成员，可以看成是item
     做的事，通过这件事，我们可以看到物体的状态，也可以通过这件事来影响这个物体的属性。
     	1) 所有的item间的互动，将藉由Animation来实现

  4) 整个世界的时间是通过帧来定义的，通过time和pixel这两个概念，我们可以定义离散的速度和加速度。
     进一步，我们可以通过这些离散的变量来模拟真实世界的物体运动。

  5) 介于声音这种东西的连续性，我思考很久之后，想到了一种折衷的解决方案。
  	1) 使用全局的队列来维护声音，让所有的声音一起播放，一起结束。

  6) 进一步的，我想到了可以使用全局的队列来维护所有东西发生的顺序,这些东西，就像这个世界的法则。

  7) 所以，之后我会实现一个全局的队列(Director)来对所有的时间进行操作。让所有的事都圆满的解决吧。
     这个类的名字暗示着对游戏中一切事件的掌控。2333333

  8) 其实还可以对Animation类做进一步的抽象，但是现在暂时不想
  9) 最后，我们将Animation类之间的接触判断，下放到Frame类来计算
******************************************************************************************/
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
		sf::Image 	image;				//to store the image of this frame
		sf::Texture 	texture;			//to store the texture of this frame
		sf::Sprite 	sprite;				//to display this frame

		float 		x[2];				//0 for the L, 1 for the R, store the edge
		float 		y[2];				//0 for the L, 1 for the R, store the edge
								//we also called x0 & y0 draw_position

		sf::Vector2f  	del_position;			// 1) to store the del position of the frame(item) and the core
								// 2) we'll use this info to align the picture
								// 3) this is a relative position of the up_left conner of the picture

		sf::Vector2f 	core_position;			// 1) this store the core position of the frame
								// 2) draw_position = core_position - del_position

		void update_draw_position(); 			//use the core_position and the del_position to update the draw_position


		int impact_flag;				/*留给后续开发Item类的时候进行相互作用的时候使用*/
		int hurt_flag;
	public:
		Frame();
		Frame( 	string image_file_name,			//path & filename
			string image_info_flie_name );		// don't use this when you use STL

		//void initlize();				//make everything be ready
		sf::Sprite* display();					//display this Frame on a specific window
		int is_in(const sf::Vector2f &point);		//to check if a point is in this Frame
		int is_in(Frame *other);

		void set_image(string image_file_name);		//these functions are used to set something about the image
		void set_image_info(string image_info_flie_name);

		void set_core_position(sf::Vector2f position); 	//set the core_position

		~Frame(){}
};

#endif
