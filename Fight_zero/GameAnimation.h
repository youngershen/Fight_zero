#pragma once
#include "SDL.h"
#include "Surface.h"

#include <iostream>
#include <vector>
#include <cmath>
namespace FZ{

	class GameAnimation
	{
		public:
			int animate_rate;
			int animate_length;
			int animate_start_time;
			int current_frame;
			SDL_Surface * sprite;
			//SDL_Rect * clips;
			vector<SDL_Rect> clips;
			SDL_Surface * dest;
			void init(void);
			int width;
			int height;
		public:
			GameAnimation(void);
			~GameAnimation(void);
			GameAnimation(int animate_rate,int animate_length,SDL_Surface * sprite,int width,int height,SDL_Surface * dest);
			void on_draw(int x,int y);		
			virtual void init_clips() = 0;
	};

};
