#include "StdAfx.h"
#include "GameAnimation.h"

FZ::GameAnimation::GameAnimation(void)
{
}

FZ::GameAnimation::~GameAnimation(void)
{
}

void FZ::GameAnimation::init()
{
	 animate_rate = 60;
	 animate_length = 0;
     animate_start_time = SDL_GetTicks();
	 current_frame = 0; 
	 sprite = NULL;
	 //clips = 0;

}

FZ::GameAnimation::GameAnimation(int animate_rate, int animate_length, SDL_Surface *sprite,int width,int height,SDL_Surface * dest)
{
	this->animate_rate = animate_rate;
	this->current_frame = 0;
	this->animate_length = animate_length;
	this->sprite = sprite;
	this->height = height;
	this->width = width;
	this->dest = dest;
	this->animate_start_time = SDL_GetTicks();
	//this->init_clips();
}

void FZ::GameAnimation::on_draw(int x,int y)
{
	float fps;
	if(this->current_frame == this->animate_length - 1){
	
		this->current_frame = 0;
	
	}else{

		//this->current_frame++;
		if(this->animate_rate == 0){
			this->current_frame++;
		}else{
		
			/*
			float fps = 1000 * 1.0f / this->animate_rate ;
			float time =  fps * this->animate_length;
			Uint32 t_time  = (SDL_GetTicks() - this->animate_start_time) / time > 0 ? (SDL_GetTicks() - this->animate_start_time) % (int)time :(int)(SDL_GetTicks() - this->animate_start_time);
			//cout<<"sdl cframe :"<<this->animate_length*(t_time / time)<<endl;
			int c_frame = (int)floor(this->animate_length*(t_time / time));
			if( c_frame > this->animate_length -1){
				c_frame = 0;
			}
			//cout<<"fps:"<<(int)fps<<endl;
			//SDL_Delay(fps);
			this->current_frame = c_frame;
			*/
			float fps = 1000 * 1.0f / this->animate_rate ;
			SDL_Delay(fps);
			this->current_frame++;
		}
		
	}
	cout<<"current frame:"<<this->current_frame<<endl;
	bool flag  = FZ::Surface::on_draw(this->sprite,&this->clips[this->current_frame],this->dest,x,y);

	if(!flag){
		
		cout<<"draw texture error::"<<SDL_GetError()<<endl;
	}
	
}