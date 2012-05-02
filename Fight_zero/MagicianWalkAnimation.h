#pragma once
#include "SDL.h"
#include "GameAnimation.h"

#include <iostream>
using namespace std;




namespace FZ{
	namespace animation{

		class MagicianWalkAnimation : public FZ::GameAnimation 	
		{
			public:
				MagicianWalkAnimation(void);
				MagicianWalkAnimation(int animate_rate,int animate_length,SDL_Surface * sprite,int width,int height,SDL_Surface * dest);
				~MagicianWalkAnimation(void);
				virtual void init_clips(void);
		};
	};


};