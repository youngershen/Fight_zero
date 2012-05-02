#pragma once

#include "SDL.h"
#include "GameAnimation.h"
#include <iostream>

using namespace std;

namespace FZ{
	namespace animation{
		
		class MagicianStandAnimation_2 :public FZ::GameAnimation
		{
			public:
				MagicianStandAnimation_2(int animate_rate,int animate_length,SDL_Surface * sprite,int width,int height,SDL_Surface * dest);
				MagicianStandAnimation_2(void);
				~MagicianStandAnimation_2(void);
				virtual void init_clips(void);	
		};
	};
};
