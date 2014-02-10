//---------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This is the VBotList class, which hold all of the VBots that are
//          created during the game. This list manages all of the actions
//          that a VBot may do during the game.
//---------------------------------------------------------------------------
#include "VBot.h"
#include <vector>
using namespace std;


#ifndef VBOTLIST_H
#define VBOTLIST_H

class VBotList
{

public:
   //----------------------------------------------------------------------------
   // This is the defualt destructor. This deletes all elements in the VBot list
   //----------------------------------------------------------------------------
   ~VBotList();

   //----------------------------------------------------------------------------
   // This function Adds a VBot to the list
   //----------------------------------------------------------------------------
   void AddBot(VBot * addbot);
   
   //----------------------------------------------------------------------------
   // This function Moves all the VBots in the list
   //----------------------------------------------------------------------------
   void MoveBots();

   //----------------------------------------------------------------------------
   // This function displays all the VBots in the list on the game window's panel
   //----------------------------------------------------------------------------
	void ShowBots();

   //----------------------------------------------------------------------------
   // This function goes through the list of VBots and checks whether any of them
   // are fighting or not, and handles their fight accordingly
   //----------------------------------------------------------------------------
   void CheckBattles();

   //----------------------------------------------------------------------------
   // This function removes a specific VBot from the list
   //----------------------------------------------------------------------------
   void RemoveBot(VBot * deleteBot);

private:
   //----------------------------------------------------------------------------
   // Variable Declarations
   //----------------------------------------------------------------------------
   static const int MAX_BOTS = 100;
	int count;
   vector<VBot*> list;
};

#endif