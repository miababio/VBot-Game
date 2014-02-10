//--------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This file contains the information to create a window for the
//          VBot game.
//--------------------------------------------------------------------------
#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Program3::MyForm form;
    Application::Run(%form);
}

