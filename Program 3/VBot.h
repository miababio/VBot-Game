//---------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This is the VBot class. It is an abstract class, because it 
//          contains virtual methods. This class creates a VBot (Virtual Bot)
//          and sets the coordinates of the VBot onto the panel that the game
//          is played. The VBot class also moves the VBot, and computes
//          VBot battles, as well as how much energy is used per battle by
//          a VBot.
//---------------------------------------------------------------------------

#pragma once 

#include <vcclr.h>   

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class VBot
{
public:
   //----------------------------------------------------------------------------
   // This is the defualt constructor. This sets the x and y coordinates of the
   // VBot, as well as putting the VBot on the panel for the game
   //----------------------------------------------------------------------------
   VBot( int startX, int startY, Panel ^ drawingPanel ) : 
      x(startX), y(startY), panel(drawingPanel), energy(100), image(NULL) { }

   //----------------------------------------------------------------------------
   // This is the default destructor. Destroys the VBot
   //----------------------------------------------------------------------------
   virtual ~VBot() { }

   //----------------------------------------------------------------------------
   // This function calculates how the VBot will move within the panel for the
   // game
   //----------------------------------------------------------------------------
   virtual void Move() = 0;

   //----------------------------------------------------------------------------
   // This function calculates how much energy a VBot will contribute to fight
   // with during a battle
   //----------------------------------------------------------------------------
   virtual int EnergyToFightWith() = 0;

   //----------------------------------------------------------------------------
   // This function checks to see whether a VBot is dead. A VBot is dead if it
   // has no energy left to fight
   //----------------------------------------------------------------------------
   bool IsDead() const { return energy <= 0; }

   //----------------------------------------------------------------------------
   // This function displays the VBot on the game's panel
   //----------------------------------------------------------------------------
   virtual void Show();

   //----------------------------------------------------------------------------
   // This function determines if a VBot touches another VBot
   //----------------------------------------------------------------------------
   bool CollidedWith ( VBot * b ) const;

   //----------------------------------------------------------------------------
   // This function calculates what happens when two VBots battle
   //----------------------------------------------------------------------------
   void DoBattleWith ( VBot * b );
   
protected:
      //----------------------------------------------------------------------------
      // Variable Declarations
      //----------------------------------------------------------------------------
      int x, y;                           // Current position of the VBot
      gcroot<Drawing::Bitmap ^> image;    // Image displayed for the VBot
      gcroot<Panel ^> panel;              // Panel on which to show the VBot.
      int energy;                         // Current energy of the VBot
};
