#pragma once
#include "SDL.h"
#include "Surface.h"
#include "GameAnimation.h"
#include "MagicianStandAnimation_1.h"
#include "MagicianStandAnimation_2.h"
#include "MagicianWalkAnimation_1.h"
#include "MagicianWalkAnimation_2.h"

namespace FZ{

	namespace utils{

		class GameAnimationFactory
		{
			public:
				GameAnimationFactory(void);
				~GameAnimationFactory(void);
				static FZ::GameAnimation * get_magician_stand_animation_1(SDL_Surface * screen);
				static FZ::GameAnimation * get_magician_stand_animation_2(SDL_Surface * screen);
				static FZ::GameAnimation * get_magician_walk_animation_1(SDL_Surface * screen);
				static FZ::GameAnimation * get_magician_walk_animation_2(SDL_Surface * screen);
		};

	};
};
