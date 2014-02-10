//---------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This is the SmartBot class, which consists of a robotic man
//          walking from one end of the panel to the other. The Move, Show,
//          and EnergyToFightWith functions have all been inherited and
//          modified from the VBot class. 
//---------------------------------------------------------------------------

#include "VBot.h"

#ifndef SMARTBOT_H
#define SMARTBOT_H

class SmartBot: public VBot
{

public:
   //----------------------------------------------------------------------------
   // This is the defualt constructor. This sets the x and y coordinates of the
   // VBot, as well as putting the VBot on the panel for the game. This function
   // also initializes the image counter, to determine which image to load next.
   //----------------------------------------------------------------------------
   SmartBot(int x, int y, Panel ^ panel); 

   //----------------------------------------------------------------------------
   // This function calculates how the SmartBot will move within the panel for
   // the game
   //----------------------------------------------------------------------------
   void Move();

   //----------------------------------------------------------------------------
   // This is the defualt destructor. This removes the VBot from the panel, and
   // when it is removed, replaces its icon with an explosion sequence. An
   // explosion sound is played during the sequence.
   //----------------------------------------------------------------------------
   ~SmartBot();

   //----------------------------------------------------------------------------
   // This function displays the VBot on the game's panel
   //----------------------------------------------------------------------------
   void Show();

   //----------------------------------------------------------------------------
   // This function calculates how much energy a VBot will contribute to fight
   // with during a battle
   //----------------------------------------------------------------------------
   int EnergyToFightWith();

   //----------------------------------------------------------------------------
   // This function increments the counter, so the proper image sequence is
   // loaded in order
   //----------------------------------------------------------------------------
   void IncrementCounter();

   //----------------------------------------------------------------------------
   // This function determines what happens when the SmartBot reaches the edge of
   // a wall within the game's panel
   //----------------------------------------------------------------------------
	void CheckWall();

private:
   //----------------------------------------------------------------------------
   // Variable Declarations
   //----------------------------------------------------------------------------
	static const int EXPLOSION_TIME = 82;
   static const int FRAME2 = 2;
   static const int FRAME3 = 3;
   static const int LAST_FRAME = 4;
   static const int PIXEL_HEIGHT = 100;
   static const int PIXEL_WIDTH = 100;
   static const int MOVEMENT_SPEED = 5;
   static const int EXPLOSION_SEQUENCE = 8;

   int img_counter;
};

#endif
