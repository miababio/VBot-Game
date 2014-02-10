//--------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This file is the startup program for the VBot game. This file 
//          contains the information to create an introductory window for 
//          the VBot game.              
//--------------------------------------------------------------------------
#include "stdafx.h"
#include "Intro.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main_real(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	 Program3::Intro intro;
	 Application::Run(%intro);
    return 0;
}

