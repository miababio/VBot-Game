//--------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This file contains and defines all the methods for CardinalBot.h                
//--------------------------------------------------------------------------
#include "stdafx.h"
#include "CardinalBot.h"
#include <random>
using namespace System::Media;

CardinalBot:: CardinalBot(int x, int y, Panel ^ panel) : VBot(x, y, panel)
{
   image = gcnew Bitmap("Images\\MetalMan\\East\\MetalMan_East0.bmp"); 
   img_counter = 0; 
   direction = GO_EAST;
}

CardinalBot::~CardinalBot()
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

void CardinalBot::Move()
{
   if(direction == GO_EAST)
	   x += MOVEMENT_SPEED;
   else if(direction == GO_WEST)
      x -= MOVEMENT_SPEED;
   else if(direction == GO_NORTH)
      y -= MOVEMENT_SPEED;
   else
      y += MOVEMENT_SPEED;

	if(leftStep)
	{
		image = gcnew Drawing::Bitmap("Images\\MetalMan\\East\\MetalMan_East0.bmp");
		leftStep = !leftStep;
		rightStep = !rightStep;
		reverse = false;
	}
	else if(reverse == false && rightStep == false)
	{
		image = gcnew Drawing::Bitmap("Images\\MetalMan\\East\\MetalMan_East1.bmp");
		rightStep = true;
	}
	else if(reverse == true)
	{
		image = gcnew Drawing::Bitmap("Images\\MetalMan\\East\\MetalMan_East1.bmp");
		leftStep = true;
	}
	else if(rightStep)
	{
		image = gcnew Drawing::Bitmap("Images\\MetalMan\\East\\MetalMan_East2.bmp");
		reverse = true;
	}
   image->MakeTransparent();
	CheckWall();
}

int CardinalBot::EnergyToFightWith()
{
   int randomNum = (int)(rand() % energy + 1);
	return randomNum;
}

void CardinalBot::Show()
{
   Graphics ^ g = panel->CreateGraphics();
   g->DrawImage( image, x, y, PIXEL_WIDTH, PIXEL_HEIGHT );
   g->~Graphics();
}

void CardinalBot::CheckWall()
{
	if(x + image->Width < 0) // HITS WEST WALL
   {
      direction = (rand() % RANDOM_DIRECTION + 1);
      GoDirection(direction);
   }

   else if(x > panel->Width) // HITS EAST WALL
   {
      direction = (rand() % RANDOM_DIRECTION + 1);
      GoDirection(direction);
   }

   else if(y > panel->Height) // HITS SOUTH WALL
   {
      direction = (rand() % RANDOM_DIRECTION + 1);
      GoDirection(direction);
   }

	else if(y + image->Height < 0) // HITS NORTH WALL
   {
      direction = (rand() % RANDOM_DIRECTION + 1);
      GoDirection(direction);
   }
}

void CardinalBot::GoDirection(int direction)
{
   if(direction == GO_NORTH)
   {
		if(y > panel->Height) // This condition is only when the bot is past the South Wall
			x = (panel->Width / HALF) - image->Width;
		else
		{
			x = (panel->Width / HALF) - image->Width;
			y = panel->Height + (y + image->Height);
		}
   }
   else if(direction == GO_SOUTH)
   {
		if(y + image->Height < 0) // This condition is only when the bot is past the North Wall
			x = (panel->Width / HALF) - image->Width;
		else
		{
			x = (panel->Width / HALF) - image->Width;
			y =  (y + image->Height) - panel->Height;
		}
   }
   else if(direction == GO_EAST)
   {
		if(x + image->Width < 0) // This condition is only when the bot is past the West Wall
			y = (panel->Height / HALF) - image->Height;
		else
		{
			x = panel->Width - (x + image->Width);
			y = (panel->Height / HALF) - image->Height;
		}
   }
   else if(direction == GO_WEST)
   {
      x = panel->Width;
      y = (panel->Height / HALF) - image->Height;
   }
}
