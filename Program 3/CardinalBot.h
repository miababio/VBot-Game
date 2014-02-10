//----------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This is the CardinalBot class, which consists of a robotic warrior
//          that only walks in cardinal directions! The Move, Show,
//          and EnergyToFightWith functions have all been inherited and
//          modified from the VBot class. 
//----------------------------------------------------------------------------
#include "VBot.h"

#ifndef CARDINALBOT_H
#define CARDINALBOT_H

class CardinalBot: public VBot
{

public:
   //----------------------------------------------------------------------------
   // This is the defualt constructor. This sets the x and y coordinates of the
   // VBot, as well as putting the VBot on the panel for the game. This function
   // also initializes the image counter, to determine which image to load next,
   // and initializes the initial direction the CardinalBot should move.
   //----------------------------------------------------------------------------
   CardinalBot(int x, int y, Panel ^ panel);

   //----------------------------------------------------------------------------
   // This function calculates how the VBot will move within the panel for the
   // game
   //----------------------------------------------------------------------------
   void Move();

   //----------------------------------------------------------------------------
   // This is the defualt destructor. This removes the VBot from the panel, and
   // when it is removed, replaces its icon with an explosion sequence. An
   // explosion sound is played during the sequence.
   //----------------------------------------------------------------------------
	~CardinalBot();

   //----------------------------------------------------------------------------
   // This function displays the VBot on the game's panel
   //----------------------------------------------------------------------------
   void Show();

   //----------------------------------------------------------------------------
   // This function determines which dierection the CardinalBot should go after
   // it disappears from the screen
   //----------------------------------------------------------------------------
   void GoDirection(int direction);

   //----------------------------------------------------------------------------
   // This function calculates how much energy a VBot will contribute to fight
   // with during a battle
   //----------------------------------------------------------------------------
   int EnergyToFightWith();

private:
   //----------------------------------------------------------------------------
   // Variable Declarations
   //----------------------------------------------------------------------------
   static const int RANDOM_DIRECTION = 4;
   static const int GO_NORTH = 1;
   static const int GO_SOUTH = 2;
   static const int GO_EAST = 3;
   static const int GO_WEST = 4;
   static const int EXPLOSION_TIME = 82;
   static const int PIXEL_HEIGHT = 32;
   static const int PIXEL_WIDTH = 32;
   static const int MOVEMENT_SPEED = 5;
   static const int EXPLOSION_SEQUENCE = 8;
   static const int HALF = 2;

	int img_counter;
   int direction;
	void CheckStepEast();
   void CheckStepWest();
   void CheckStepNorth();
   void CheckStepSouth();
	void CheckWall();
	bool leftStep, rightStep, reverse;
};

#endif