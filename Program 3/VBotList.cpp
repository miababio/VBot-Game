//--------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This file contains and defines all the methods for VBotList.h                
//--------------------------------------------------------------------------
#include "stdafx.h"
#include "VBotList.h"
#include "SmartBot.h"
#include <algorithm>

VBotList::~VBotList() 
{
   list.clear();
}

void VBotList::AddBot(VBot * addbot)
{
   list.push_back(addbot);
}

void VBotList::ShowBots()
{
   for(unsigned int i = 0; i < list.size(); i++)
      list[i]->Show();
}

void VBotList::MoveBots()
{
   for(unsigned int i = 0; i < list.size(); i++)
      list[i]->Move();
}

void VBotList::CheckBattles()
{
   for(unsigned int i = 0; i < list.size(); i++)
   {
      for(unsigned int j = i + 1; j < list.size(); j++)
      {
         if(list[i]->CollidedWith(list[j]))
         {
            list[i]->DoBattleWith(list[j]);
            if(list[i]->IsDead())
            {
               VBot* deleteBot = list[i];
               RemoveBot(deleteBot);
					deleteBot->~VBot();
            }
            else if(list[j]->IsDead())
            {
               VBot* deleteBot = list[j];
               RemoveBot(deleteBot);
					deleteBot->~VBot();
            }
         }
      }
   }
}

void VBotList::RemoveBot(VBot * deleteBot)
{
   list.erase(std::remove(list.begin(), list.end(), deleteBot), list.end());
}
