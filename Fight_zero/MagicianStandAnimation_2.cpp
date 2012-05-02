#include "StdAfx.h"
#include "MagicianStandAnimation_2.h"

FZ::animation::MagicianStandAnimation_2::MagicianStandAnimation_2(void)
{
}

FZ::animation::MagicianStandAnimation_2::~MagicianStandAnimation_2(void)
{
}


FZ::animation::MagicianStandAnimation_2::MagicianStandAnimation_2(int animate_rate,int animate_length,SDL_Surface * sprite,int width,int height,SDL_Surface * dest) : GameAnimation(animate_rate,animate_length,sprite,width,height,dest)
{
	this->init_clips();
}

void FZ::animation::MagicianStandAnimation_2::init_clips(void)
{
	int length = this->animate_length;
	int width  = this->width;
	int height = this->height;
	int rows   = length / 4;

	for(int i = 0 ; i< rows;i++)
	{
		for(int n = 0 ; n < 4;n ++)
		{
			SDL_Rect rect;
			rect.w = width;
			rect.h = height;
			rect.x = n * width;
			rect.y = (2+i) * height;
			this->clips.push_back(rect);
		}
	}
}
