VBot-Game
=========

Class project for my Object Oriented Programming and Data Structures II class. 

"A VBot (Virtual Bot) is a little creature that moves around on the screen.
When VBots meet, they do battle.  Each VBot puts a given amount of energy
into the battle.  Winners are rewarded and losers are penalized."

For this project, we were provided a base class (VBot.h/Vbot.cpp), and had to create three different VBots from
the base class. We also had minimal, yet specific requirements to create a GUI interface to control the VBots as they battle. Any other features added were considered extra credit. 

This project was created using Microsoft Visual Studio 2012.

Extra Features
--------------
The following implementations are extra features:
Added explosions for when the VBots are considered dead, 
Added sound to the explosions,
Added the option to enable/disable background music (right-click GUI interface to see option),
Added an introductory screen before you get to the game
  
Some Known Bugs
---------------
One bug that is prevalent to the program is that you cannot play the background music and the sound of the explosions at the same time. If a VBot is about to perish as the music is playing, then the sound of the explosion will play and the background music will stop playing (if enabled). To fix this, simply right-click and un-check, then check the option to enable background music, and the music should start playing again. 

"Enable Sounds" option doesn't work (the explosion sound is always on)
