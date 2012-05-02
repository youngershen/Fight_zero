#pragma once
#include "SDL.h"
#include "GameAnimation.h"

#include <iostream>

using namespace std;

namespace FZ{
	namespace animation{
		class MagicianStandAnimation_1 :public FZ::GameAnimation
		{
			public:
				MagicianStandAnimation_1(int animate_rate,int animate_length,SDL_Surface * sprite,int width,int height,SDL_Surface * dest);
				MagicianStandAnimation_1(void);
				~MagicianStandAnimation_1(void);
				virtual void init_clips(void);
		};
	};
};