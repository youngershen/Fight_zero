#pragma once

#include "SDL.h"
#include <iostream>
#include <string>
using namespace std;

namespace FZ{

	class GameConfig
	{
		public:
		GameConfig(void);
		~GameConfig(void);
		static SDL_Surface * init_game(std::string title, std::string icon, int screen_height, int screen_width);
	};

};
