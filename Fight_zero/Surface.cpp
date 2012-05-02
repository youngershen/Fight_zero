#include "StdAfx.h"
#include "Surface.h"

FZ::Surface::Surface(void)
{
}

FZ::Surface::~Surface(void)
{
}

SDL_Surface * FZ::Surface::on_load(string path)
{
	string ext = path.substr(path.find_last_of('.')+1,3);
	SDL_Surface * surface;
	
	if(ext.compare("png") == 0 ){

		surface = SDL_DisplayFormatAlpha(load_png_img(path.c_str()));
		//surface = load_png_img(path.c_str());
		return surface;
	
	}else if(ext.compare("bmp") == 0){
		
		surface = load_bmp_img(path.c_str());
		return surface;
	
	}else{
	
		cout<<"load texture error !"<<endl;
		return NULL;
	}
}

bool FZ::Surface::on_draw(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, int dx,int dy)
{
	int flag = 0;
	SDL_Rect rect;
	rect.x = dx;
	rect.y = dy;

	if(src ==NULL || dst == NULL)
	{
		return false;

	}else{
	
		flag = SDL_BlitSurface(src,srcrect,dst,&rect);	
		if(flag == 0){
			//SDL_UpdateRect(dst,dx,dy,srcrect->w, srcrect->h);
			return true;
		}else{
			printf("apply surface may failure !--%s",SDL_GetError());
			return false;
		}
	}
}



SDL_Surface *FZ::Surface::load_bmp_img(std::string path)
{
	SDL_Surface * image_surface;
	image_surface = SDL_LoadBMP(path.c_str());
	return image_surface;

}
SDL_Surface * FZ::Surface::load_png_img(std::string path)
{
	
	SDL_Surface * image_surface;
	SDL_RWops *rwop;
	rwop = SDL_RWFromFile(path.c_str(), "rb");
	image_surface = IMG_LoadPNG_RW(rwop);
	
	if(!image_surface) 
	{
	  printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
    }

	return image_surface;

}

SDL_Surface * FZ::Surface::create_surface(int width,int height)
{
	SDL_Surface * surface;	
	surface=SDL_CreateRGBSurface(SDL_SWSURFACE,width,height,32,0,0,0,0);
	return surface;
}