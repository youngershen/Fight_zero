#pragma once
#include "SDL.h"
#include "GameAnimation.h"
#include <iostream>

using namespace std;

namespace FZ{
	
	namespace animation{

		class MagicianWalkAnimation_2 : public GameAnimation
		{
			public:
				MagicianWalkAnimation_2(int animate_rate,int animate_length,SDL_Surface * sprite,int width,int height,SDL_Surface * dest);
				MagicianWalkAnimation_2(void);
				~MagicianWalkAnimation_2(void);
				virtual void init_clips(void);	
		};
		
	};
};