#pragma once
#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <string>

using namespace std;

namespace FZ{

	class Surface
	{
		
		public:
			Surface(void);
			~Surface(void);
			static SDL_Surface * on_load(string path);
			static bool on_draw(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst,int dx,int dy);
		private :
			static SDL_Surface * load_bmp_img(string path);
			static SDL_Surface * load_png_img(string path);
	};

};
