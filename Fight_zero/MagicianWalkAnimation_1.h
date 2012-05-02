#pragma once

#include "SDL.h"
#include "GameAnimation.h"
#include <iostream>

using namespace std;

namespace FZ{
	namespace animation{
		
		class MagicianWalkAnimation_1 :public GameAnimation
		{
			public:
				MagicianWalkAnimation_1(int animate_rate,int animate_length,SDL_Surface * sprite,int width,int height,SDL_Surface * dest);
				MagicianWalkAnimation_1(void);
				~MagicianWalkAnimation_1(void);
				virtual void init_clips(void);	
		};
	
	};
};
