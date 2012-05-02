#include "StdAfx.h"
#include "GameAnimationFactory.h"

FZ::utils::GameAnimationFactory::GameAnimationFactory(void)
{
}

FZ::utils::GameAnimationFactory::~GameAnimationFactory(void)
{
}


FZ::GameAnimation * FZ::utils::GameAnimationFactory::get_magician_walk_animation_2(SDL_Surface * screen)
{
	SDL_Surface * player = FZ::Surface::on_load("./resource/actors/magician/mofashi-walk-1.png");
	FZ::animation::MagicianWalkAnimation_2* animation = new FZ::animation::MagicianWalkAnimation_2(6,8,player,74,122,screen);
	return animation;
}

FZ::GameAnimation * FZ::utils::GameAnimationFactory::get_magician_stand_animation_1(SDL_Surface *screen)
{
	SDL_Surface * player = FZ::Surface::on_load("./resource/actors/magician/mofashi-stand-2.png");
	FZ::animation::MagicianStandAnimation_1 * animation = new FZ::animation::MagicianStandAnimation_1(6,8,player,60,131,screen);
	return animation;
}

FZ::GameAnimation * FZ::utils::GameAnimationFactory::get_magician_stand_animation_2(SDL_Surface *screen)
{
	SDL_Surface * player = FZ::Surface::on_load("./resource/actors/magician/mofashi-stand-2.png");
	FZ::animation::MagicianStandAnimation_2 * animation = new FZ::animation::MagicianStandAnimation_2(6,8,player,60,131,screen);
	return animation;
}

FZ::GameAnimation * FZ::utils::GameAnimationFactory::get_magician_walk_animation_1(SDL_Surface * screen)
{
	SDL_Surface * player = FZ::Surface::on_load("./resource/actors/magician/mofashi-walk-1.png");
	FZ::animation::MagicianWalkAnimation_1* animation = new FZ::animation::MagicianWalkAnimation_1(6,8,player,74,122,screen);
	return animation;
}
