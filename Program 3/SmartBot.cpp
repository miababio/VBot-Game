//--------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This file contains and defines all the methods for SmartBot.h                
//--------------------------------------------------------------------------
#include "stdafx.h"
#include <vcclr.h>
#include <random>
#include "SmartBot.h"
using namespace System::Media;

SmartBot::SmartBot(int x, int y, Panel ^ panel) : VBot(x, y, panel)
{
   image = gcnew Bitmap("Images\\Robot Dude\\Robot0.bmp");
   img_counter = 0; 
}
SmartBot::~SmartBot()
{
	SoundPlayer^ boomPlayer = gcnew SoundPlayer();
	boomPlayer->SoundLocation = "Sounds\\Explosion.wav";
	boomPlayer->Play();
	
	int explosions = 0, explode_time = 0;
	while(explode_time < EXPLOSION_TIME)
	{
		image = gcnew Drawing::Bitmap("Images\\Explosions\\Explosion" + explosions.ToString() + ".bmp");
		image->MakeTransparent();
		Show();
		if(explosions >= EXPLOSION_SEQUENCE)
			explosions = 0;
		explosions++;
		explode_time++;
	}
}

void SmartBot::Move()
{
	x -= MOVEMENT_SPEED;
	if(img_counter == 0)
		image = gcnew Drawing::Bitmap("Images\\Robot Dude\\Robot0.bmp");
	else if(img_counter == 1)
		image = gcnew Drawing::Bitmap("Images\\Robot Dude\\Robot1.bmp");
	else if(img_counter == FRAME2)
		image = gcnew Drawing::Bitmap("Images\\Robot Dude\\Robot2.bmp");
	else if(img_counter == FRAME3)
		image = gcnew Drawing::Bitmap("Images\\Robot Dude\\Robot3.bmp");
	else if(img_counter == LAST_FRAME)
		image = gcnew Drawing::Bitmap("Images\\Robot Dude\\Robot4.bmp");
   image->MakeTransparent();
	CheckWall();
	IncrementCounter();
}

int SmartBot::EnergyToFightWith()
{
	int randomNum = (int)(rand() % energy + 1);
	return randomNum;
}

void SmartBot::IncrementCounter()
{
	if(img_counter >= LAST_FRAME)
		img_counter = 0;
	else
		img_counter++;
}

void SmartBot::CheckWall()
{
	if(x + image->Width < 0)
	{
		x = panel->Width + (x + image->Width);
      y = (y + image->Height);
	}
   else if((y + image->Height) > panel->Height)
   {
      y = 0;
      x = panel->Width;
   }
}

void SmartBot::Show()
{
   Graphics ^ g = panel->CreateGraphics();
   g->DrawImage( image, x, y, PIXEL_WIDTH, PIXEL_HEIGHT );
   g->~Graphics();
}