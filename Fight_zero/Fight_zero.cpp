// Fight_zero.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "SDL.h"
#include "SDL_image.h"
#include "GameConfig.h"
#include "Surface.h"
#include "MagicianWalkAnimation.h"
#include "MagicianWalkAnimation_1.h"
#include "MagicianStandAnimation_2.h"
#include "GameAnimationFactory.h"
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
FZ::GameAnimation* anima;

int m_x = 0;
int m_y = 0;

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
	SDL_Surface * sc = FZ::Surface::create_surface(640,400);
	//SDL_FillRect(sc,0,SDL_MapRGB(sc->format,255,255,255));
	//SDL_SetAlpha(sc, SDL_SRCALPHA, 0);
	player = FZ::Surface::on_load("./resource/actors/magician/mofashi-stand-2.png");
	FZ::Surface::on_draw(sc,NULL,screen,0,0);
	SDL_Flip(screen);
	anima = FZ::utils::GameAnimationFactory::get_magician_walk_animation_2(sc);
	
	cout<<anima->clips.size()<<endl;
	cout<<SDL_GetTicks()<<endl;
	FZ::Surface::on_draw(player,&rect,sc,0,0);
	
	SDL_Flip(sc);
	//SDL_UpdateRect(sc, 0, 0, 0, 0);
	while(true){

		SDL_Event event;
		if (SDL_PollEvent(&event)) {
					event_line(event);
			}
	
		//SDL_UpdateRect(screen, 0, 0, 0, 0);
	//	FZ::Surface::on_draw(player,&rect3,screen,0,0);
		//SDL_Flip(screen);
		//SDL_FillRect(sc, NULL, 0);
		//anima->on_draw(m_x,m_y);
	    //SDL_Flip(sc);
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
						m_x+=20;
						break;
                }
            }

         
		else if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        
	
}