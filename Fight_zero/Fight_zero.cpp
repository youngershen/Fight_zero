// Fight_zero.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "SDL.h"
#include "SDL_image.h"
#include "GameConfig.h"
#include "Surface.h"
#include "MagicianWalkAnimation.h"

#include <windows.h>
#include <iostream>
#pragma comment(lib,"SDL.lib")
#pragma comment(lib,"SDL_image.lib")

using namespace std;

void event_line(SDL_Event event);
bool quit = false;
//SDL_Event event;
SDL_Surface * screen;
SDL_Surface * player;
SDL_Rect rect;
SDL_Rect rect2;
SDL_Rect rect3;
FZ::animation::MagicianWalkAnimation * anima;
int _tmain(int argc, _TCHAR* argv[])
{
	
	
	
	rect.x = 0;
	rect.y = 0;
	rect.w = 60;
	rect.h = 131;

	rect2.h = 131;
	rect2.w = 60;
	rect2.x = 0;
	rect2.y = 262;

	screen = FZ::GameConfig::init_game("sd","",400,640);
	player = FZ::Surface::on_load("./resource/actors/magician/mofashi-stand-2.png");
	anima = new FZ::animation::MagicianWalkAnimation(6,8,player,60,131,screen);
	
	cout<<anima->clips.size()<<endl;
	cout<<SDL_GetTicks()<<endl;

	while(true){

		SDL_Event event;
		if (SDL_PollEvent(&event)) {
					event_line(event);
			}
	
		//SDL_UpdateRect(screen, 0, 0, 0, 0);
	//	FZ::Surface::on_draw(player,&rect3,screen,0,0);
		//SDL_Flip(screen);
	//	SDL_FillRect(screen, NULL, 0);
		anima->on_draw(0,0);
	    SDL_Flip(screen);
	}

	return 0;
}



void event_line(SDL_Event event)
{
	
           
            if( event.type == SDL_KEYDOWN )
            {
                
                switch( event.key.keysym.sym )
                {
                    case SDLK_UP:
						cout<<"up"<<endl;
						rect3 = rect;
						
						//FZ::Surface::on_draw(player,&rect3,screen,0,0);
						break;
                    case SDLK_DOWN: cout<<"down"<<endl; 
						rect3 = rect2;
						//FZ::Surface::on_draw(player,&rect3,screen,0,0);
						break;
                    case SDLK_LEFT: cout<<"left"<<endl;
						
						break;
                    case SDLK_RIGHT: cout<<"right"<<endl;
						
						break;
                }
            }

         
		else if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        
	
}