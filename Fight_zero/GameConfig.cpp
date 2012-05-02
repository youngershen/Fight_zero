#include "StdAfx.h"
#include "GameConfig.h"

FZ::GameConfig::GameConfig(void)
{
}

FZ::GameConfig::~GameConfig(void)
{
}
SDL_Surface *  FZ::GameConfig::init_game(std::string title, std::string icon, int screen_height, int screen_width)
{

	
	#ifdef __windows__
		SDL_putenv("SDL_VIDEODRIVER=directx");
	#endif

	#ifdef __linux__
	  putenv("SDL_VIDEODRIVER=dga");
	#endif

	SDL_Surface * screen;
	SDL_WM_SetCaption("null", NULL );
	//SDL_WM_SetIcon(load_texture(icon), NULL );

	int flag = SDL_Init(SDL_INIT_EVERYTHING);
	if(flag == -1){
		cout<<"sdl init error"<<SDL_GetError()<<endl;
		exit(-1);
	}

	screen = SDL_SetVideoMode(screen_width,screen_height,32,SDL_SWSURFACE);
	
	return screen;
}