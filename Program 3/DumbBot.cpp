//--------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This file contains and defines all the methods for DumbBot.h                
//--------------------------------------------------------------------------
#include "stdafx.h"
#include "DumbBot.h"
#include <random>
using namespace System::Media;

DumbBot::DumbBot(int x, int y, Panel ^ panel) : VBot(x, y, panel)
{
   image = gcnew Bitmap("Images\\Simba\\simba0.bmp");
   img_counter = 0;
}

DumbBot::~DumbBot()
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

void DumbBot::Move()
{
	x += MOVEMENT_SPEED;
	if(img_counter == 0)
		image = gcnew Drawing::Bitmap("Images\\Simba\\simba0.bmp");
	else if(img_counter == 1)
		image = gcnew Drawing::Bitmap("Images\\Simba\\simba1.bmp");
	else if(img_counter == FRAME2)
		image = gcnew Drawing::Bitmap("Images\\Simba\\simba2.bmp");
	else if(img_counter == FRAME3)
		image = gcnew Drawing::Bitmap("Images\\Simba\\simba3.bmp");
	else if(img_counter == FRAME4)
		image = gcnew Drawing::Bitmap("Images\\Simba\\simba4.bmp");
   else if(img_counter == LAST_FRAME)
		image = gcnew Drawing::Bitmap("Images\\Simba\\simba5.bmp");
   image->MakeTransparent();
   CheckWall();
	IncrementCounter();
}

int DumbBot::EnergyToFightWith() // Will return a random amount of energy
{
   int randomNum = (int)(rand() % energy + 1);
	return randomNum;
}

void DumbBot::IncrementCounter()
{
	if(img_counter >= LAST_FRAME)
		img_counter = 0;
	else
		img_counter++;
}

void DumbBot::Show()
{
   Graphics ^ g = panel->CreateGraphics();
   g->DrawImage( image, x, y, PIXEL_WIDTH, PIXEL_HEIGHT );
   g->~Graphics();
}

void DumbBot::CheckWall()
{
   if(x > panel->Width)
	{
		x = panel->Width - (x + image->Width);
      y = (y + image->Height);
	}
   else if(y > panel->Height)
   {
      y = 0 - image->Height;
      x = panel->Width - (x + image->Width);
   }
}