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
******************************************************************************************/
#ifndef ANIMATION_H_
#define ANIMATION_H_


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Frame.h"
#include "Concept.h"

#include <string>
#include <utility>
using namespace std;

class Animation{
	private:
		vector<Frame> 		sequence;		//store all the Frames of the Animation
								//!!! don't add anything behind the sequence,
								// because the vector's memery model

		sf::SoundBuffer 	sound_buffer;		//store the SoundBuffer
		sf::Sound		sound;			//store the Sound

		sf::Time		last_time;		//to store the lasting time of all the frame
		sf::Clock		cur_time;		//to store the played time of currend frame

		int 			play_flag;		//flag to check if the Animation is playing
		int 			cur_frame;		//position of the current frame in the sequence	

		sf::Vector2f		core_position;		//store the core_position of the Animation (pixel)
		sf::Vector2f		speed;			//store the vector of speed (pixel/second)
		float			max_speed;		//store the max_speed that the animation could deal with
		float 			stop_ratio;	 	//the ratio of the speed down
		sf::Vector2f		acceleration;		//store the vector of acceleration ( pixel/(second^2) )
		int 			affect_flag;
	public:
		Animation();
		Animation(  string frame_setting_file_name,	// 1) path & filename
			    string sound_file_name );		// 2) need a setting a file which store a list of images *****

		int is_playing();				// use to check if the Animation is playing (for the director)
		void initlize();				// reset the whole Animation
		void next_frame(sf::Time dt);			// use to move to the next frame, note that the imformation should be
								// claculate with the time

		sf::Sprite* begin_cur_display();		// use to start display the current frame (pic + sound)
		void end_cur_display(); 			// use to end display  the current frame (sound)
								// note that we don't need to stop a image by ourself


		//void affect_others(Animation *other);		/******* get some impact on others *******/
		void be_affected(Animation *other);		/*留由后续开发Item时继续补充*/


		void set_sound(const string &sound_file_name);	// use to set sound
		void set_sequence(const string &frame_setting_file_name); 
								// use to set sequence
		void update_last_time();			// use to update the last time of every period of the sound
		void set_acceleration(sf::Vector2f ac); 	// use to set the acceleration
		void set_speed(sf::Vector2f sp);		// use to set the speed
		void set_core_position(sf::Vector2f pos);	// use to set the position
		void set_max_speed(float maxx);			// use to set the max speed
		void set_play_flag(int f);			// play_flag表示是否正在播放
		void set_stop_ratio(float f);

		sf::Vector2f get_core_position();		// 用于更新Item的位置
		sf::Vector2f get_speed();

		int is_affect();


		~Animation(){}

};



#endif
