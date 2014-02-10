//---------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This is the form class, which creates the window for the VBot
//          game. This class also sets up controls for the window, so the
//          user can manipulate the VBots on the window.
//---------------------------------------------------------------------------
#include "SmartBot.h"
#include "DumbBot.h"
#include "CardinalBot.h"
#include "VBotList.h"

#pragma once

//----------------------------------------------------------------------------
// Variable Declarations
//----------------------------------------------------------------------------
namespace Program3 {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;
   using namespace System::Media; // for sound later.....

   /// <summary>
   /// Summary for MyForm
   /// </summary>
   public ref class MyForm : public System::Windows::Forms::Form
   {
   public:
      MyForm(void)
      {
         InitializeComponent();
         player = gcnew SoundPlayer();
         cboBotList->SelectedIndex = 0;
         list = new VBotList();
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~MyForm()
      {
         if (components)
         {
            delete components;
         }
      }
   private: System::Windows::Forms::Panel^  gamePanel;
   private: System::Windows::Forms::Button^  btnAddBot;


   protected: 
   private:
      SoundPlayer ^player;
      String^ botName;
      VBotList *list;
      int xCoord, yCoord, count;
      static const int SMARTBOT = 0, DUMBBOT = 1, CARDINALBOT = 2, MAX_BOTS = 100;
   private: System::Windows::Forms::Timer^  gameTimer;
   private: System::Windows::Forms::TrackBar^  gameTrackBar;
   private: System::Windows::Forms::Button^  btnExit;

   private: System::Windows::Forms::ContextMenuStrip^  cxtMenu;
   private: System::Windows::Forms::ToolStripMenuItem^  soundsToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  enableSoundsToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  musicToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  enableMusicToolStripMenuItem;
   private: System::Windows::Forms::Label^  lblGameSpeed;
   private: System::Windows::Forms::ComboBox^  cboBotList;
   private: System::Windows::Forms::NumericUpDown^  numUpDwnX;
   private: System::Windows::Forms::NumericUpDown^  numUpDwnY;
   private: System::Windows::Forms::Label^  lblX;
   private: System::Windows::Forms::Label^  lblY;
   private: System::Windows::Forms::Label^  lblSlow;
   private: System::Windows::Forms::Label^  lblFast;
   private: System::Windows::Forms::Button^  btnReset;




   private: System::ComponentModel::IContainer^  components;
   private:
      /// <summary>
      /// Required designer variable.
      /// </summary>


#pragma region Windows Form Designer generated code
      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      void InitializeComponent(void)
      {
         this->components = (gcnew System::ComponentModel::Container());
         System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
         this->gamePanel = (gcnew System::Windows::Forms::Panel());
         this->btnAddBot = (gcnew System::Windows::Forms::Button());
         this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
         this->gameTrackBar = (gcnew System::Windows::Forms::TrackBar());
         this->btnExit = (gcnew System::Windows::Forms::Button());
         this->cxtMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
         this->soundsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->enableSoundsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->musicToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->enableMusicToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->lblGameSpeed = (gcnew System::Windows::Forms::Label());
         this->cboBotList = (gcnew System::Windows::Forms::ComboBox());
         this->numUpDwnX = (gcnew System::Windows::Forms::NumericUpDown());
         this->numUpDwnY = (gcnew System::Windows::Forms::NumericUpDown());
         this->lblX = (gcnew System::Windows::Forms::Label());
         this->lblY = (gcnew System::Windows::Forms::Label());
         this->lblSlow = (gcnew System::Windows::Forms::Label());
         this->lblFast = (gcnew System::Windows::Forms::Label());
         this->btnReset = (gcnew System::Windows::Forms::Button());
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gameTrackBar))->BeginInit();
         this->cxtMenu->SuspendLayout();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numUpDwnX))->BeginInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numUpDwnY))->BeginInit();
         this->SuspendLayout();
         // 
         // gamePanel
         // 
         this->gamePanel->BackColor = System::Drawing::SystemColors::Window;
         this->gamePanel->Location = System::Drawing::Point(157, 142);
         this->gamePanel->Name = L"gamePanel";
         this->gamePanel->Size = System::Drawing::Size(694, 447);
         this->gamePanel->TabIndex = 0;
         this->gamePanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::gamePanel_Paint);
         // 
         // btnAddBot
         // 
         this->btnAddBot->Location = System::Drawing::Point(443, 97);
         this->btnAddBot->Name = L"btnAddBot";
         this->btnAddBot->Size = System::Drawing::Size(75, 23);
         this->btnAddBot->TabIndex = 1;
         this->btnAddBot->Text = L"Add Vbot";
         this->btnAddBot->UseVisualStyleBackColor = true;
         this->btnAddBot->Click += gcnew System::EventHandler(this, &MyForm::btnAddBot_Click);
         // 
         // gameTimer
         // 
         this->gameTimer->Interval = 300;
         this->gameTimer->Tick += gcnew System::EventHandler(this, &MyForm::gameTimer_Tick);
         // 
         // gameTrackBar
         // 
         this->gameTrackBar->LargeChange = 100;
         this->gameTrackBar->Location = System::Drawing::Point(747, 75);
         this->gameTrackBar->Maximum = 500;
         this->gameTrackBar->Minimum = 20;
         this->gameTrackBar->Name = L"gameTrackBar";
         this->gameTrackBar->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
         this->gameTrackBar->Size = System::Drawing::Size(104, 45);
         this->gameTrackBar->SmallChange = 50;
         this->gameTrackBar->TabIndex = 2;
         this->gameTrackBar->TickFrequency = 50;
         this->gameTrackBar->Value = 300;
         this->gameTrackBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::gameTrackBar_ValueChanged);
         // 
         // btnExit
         // 
         this->btnExit->Location = System::Drawing::Point(645, 657);
         this->btnExit->Name = L"btnExit";
         this->btnExit->Size = System::Drawing::Size(129, 23);
         this->btnExit->TabIndex = 3;
         this->btnExit->Text = L"Close Program";
         this->btnExit->UseVisualStyleBackColor = true;
         this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
         // 
         // cxtMenu
         // 
         this->cxtMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->soundsToolStripMenuItem, 
            this->musicToolStripMenuItem});
         this->cxtMenu->Name = L"contextMenuStrip1";
         this->cxtMenu->Size = System::Drawing::Size(152, 48);
         // 
         // soundsToolStripMenuItem
         // 
         this->soundsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->enableSoundsToolStripMenuItem});
         this->soundsToolStripMenuItem->Name = L"soundsToolStripMenuItem";
         this->soundsToolStripMenuItem->Size = System::Drawing::Size(151, 22);
         this->soundsToolStripMenuItem->Text = L"Sounds";
         // 
         // enableSoundsToolStripMenuItem
         // 
         this->enableSoundsToolStripMenuItem->Name = L"enableSoundsToolStripMenuItem";
         this->enableSoundsToolStripMenuItem->Size = System::Drawing::Size(151, 22);
         this->enableSoundsToolStripMenuItem->Text = L"Enable Sounds";
         // 
         // musicToolStripMenuItem
         // 
         this->musicToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->enableMusicToolStripMenuItem});
         this->musicToolStripMenuItem->Name = L"musicToolStripMenuItem";
         this->musicToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::M));
         this->musicToolStripMenuItem->Size = System::Drawing::Size(151, 22);
         this->musicToolStripMenuItem->Text = L"&Music";
         // 
         // enableMusicToolStripMenuItem
         // 
         this->enableMusicToolStripMenuItem->CheckOnClick = true;
         this->enableMusicToolStripMenuItem->Name = L"enableMusicToolStripMenuItem";
         this->enableMusicToolStripMenuItem->Size = System::Drawing::Size(144, 22);
         this->enableMusicToolStripMenuItem->Text = L"Enable Music";
         this->enableMusicToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::enableMusicToolStripMenuItem_Click);
         // 
         // lblGameSpeed
         // 
         this->lblGameSpeed->AutoSize = true;
         this->lblGameSpeed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)), 
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->lblGameSpeed->Location = System::Drawing::Point(719, 39);
         this->lblGameSpeed->Name = L"lblGameSpeed";
         this->lblGameSpeed->Size = System::Drawing::Size(160, 20);
         this->lblGameSpeed->TabIndex = 4;
         this->lblGameSpeed->Text = L"Change GameSpeed";
         // 
         // cboBotList
         // 
         this->cboBotList->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
         this->cboBotList->FormattingEnabled = true;
         this->cboBotList->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Smart Bot", L"Dumb Bot", L"Cardinal Bot"});
         this->cboBotList->Location = System::Drawing::Point(91, 75);
         this->cboBotList->Name = L"cboBotList";
         this->cboBotList->Size = System::Drawing::Size(121, 21);
         this->cboBotList->TabIndex = 5;
         // 
         // numUpDwnX
         // 
         this->numUpDwnX->BackColor = System::Drawing::SystemColors::Window;
         this->numUpDwnX->Location = System::Drawing::Point(285, 75);
         this->numUpDwnX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {600, 0, 0, 0});
         this->numUpDwnX->Name = L"numUpDwnX";
         this->numUpDwnX->Size = System::Drawing::Size(120, 20);
         this->numUpDwnX->TabIndex = 6;
         // 
         // numUpDwnY
         // 
         this->numUpDwnY->Location = System::Drawing::Point(554, 75);
         this->numUpDwnY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {350, 0, 0, 0});
         this->numUpDwnY->Name = L"numUpDwnY";
         this->numUpDwnY->Size = System::Drawing::Size(120, 20);
         this->numUpDwnY->TabIndex = 7;
         // 
         // lblX
         // 
         this->lblX->AutoSize = true;
         this->lblX->Location = System::Drawing::Point(311, 107);
         this->lblX->Name = L"lblX";
         this->lblX->Size = System::Drawing::Size(68, 13);
         this->lblX->TabIndex = 8;
         this->lblX->Text = L"X-Coordinate";
         // 
         // lblY
         // 
         this->lblY->AutoSize = true;
         this->lblY->Location = System::Drawing::Point(580, 107);
         this->lblY->Name = L"lblY";
         this->lblY->Size = System::Drawing::Size(68, 13);
         this->lblY->TabIndex = 9;
         this->lblY->Text = L"Y-Coordinate";
         // 
         // lblSlow
         // 
         this->lblSlow->AutoSize = true;
         this->lblSlow->Location = System::Drawing::Point(744, 107);
         this->lblSlow->Name = L"lblSlow";
         this->lblSlow->Size = System::Drawing::Size(30, 13);
         this->lblSlow->TabIndex = 10;
         this->lblSlow->Text = L"Slow";
         // 
         // lblFast
         // 
         this->lblFast->AutoSize = true;
         this->lblFast->Location = System::Drawing::Point(824, 107);
         this->lblFast->Name = L"lblFast";
         this->lblFast->Size = System::Drawing::Size(27, 13);
         this->lblFast->TabIndex = 11;
         this->lblFast->Text = L"Fast";
         // 
         // btnReset
         // 
         this->btnReset->Location = System::Drawing::Point(259, 657);
         this->btnReset->Name = L"btnReset";
         this->btnReset->Size = System::Drawing::Size(75, 23);
         this->btnReset->TabIndex = 12;
         this->btnReset->Text = L"Reset Game";
         this->btnReset->UseVisualStyleBackColor = true;
         this->btnReset->Click += gcnew System::EventHandler(this, &MyForm::btnReset_Click);
         // 
         // MyForm
         // 
         this->AcceptButton = this->btnAddBot;
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackColor = System::Drawing::SystemColors::Control;
         this->ClientSize = System::Drawing::Size(1008, 730);
         this->ContextMenuStrip = this->cxtMenu;
         this->ControlBox = false;
         this->Controls->Add(this->btnReset);
         this->Controls->Add(this->lblFast);
         this->Controls->Add(this->lblSlow);
         this->Controls->Add(this->lblY);
         this->Controls->Add(this->lblX);
         this->Controls->Add(this->numUpDwnY);
         this->Controls->Add(this->numUpDwnX);
         this->Controls->Add(this->cboBotList);
         this->Controls->Add(this->lblGameSpeed);
         this->Controls->Add(this->btnExit);
         this->Controls->Add(this->gameTrackBar);
         this->Controls->Add(this->btnAddBot);
         this->Controls->Add(this->gamePanel);
         this->DoubleBuffered = true;
         this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
         this->Name = L"MyForm";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"VBOT WARS";
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gameTrackBar))->EndInit();
         this->cxtMenu->ResumeLayout(false);
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numUpDwnX))->EndInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numUpDwnY))->EndInit();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   //----------------------------------------------------------------------------
   // When paint is called for the panel, the VBot list will display all the bots
   //----------------------------------------------------------------------------
   private: System::Void gamePanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
               if(gameTimer->Enabled == true)
                  list->ShowBots(); 
            }
   //----------------------------------------------------------------------------
   // Adds a VBot to the window
   //----------------------------------------------------------------------------
   private: System::Void btnAddBot_Click(System::Object^  sender, System::EventArgs^  e) {
               int whichBot = cboBotList->SelectedIndex;
               xCoord = Decimal::ToInt32(numUpDwnX->Value);
               yCoord = Decimal::ToInt32(numUpDwnY->Value);
               if(whichBot == SMARTBOT)              
                  list->AddBot(new SmartBot(xCoord, yCoord, gamePanel));
               else if(whichBot == DUMBBOT)
                  list->AddBot(new DumbBot(xCoord, yCoord, gamePanel));
               else if(whichBot == CARDINALBOT)
                  list->AddBot(new CardinalBot(xCoord, yCoord, gamePanel));
               gameTimer->Enabled = true;
            }
   //----------------------------------------------------------------------------
   // While the timer is ticking, moves the VBots in the list and checks for 
   // battles
   //----------------------------------------------------------------------------
   private: System::Void gameTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
               list->MoveBots();
               list->CheckBattles();
               gamePanel->Invalidate();
            }
   private: System::Void gameTrackBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
               gameTimer->Interval = gameTrackBar->Value;
            }
   private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
               if(MessageBox::Show("Are you sure you want to quit the game??", "Quit Program", 
                  MessageBoxButtons::YesNo, MessageBoxIcon::Information) == ::DialogResult::Yes)
                  Application::Exit();
            }
   private: System::Void enableMusicToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
               if(enableMusicToolStripMenuItem->Checked == true)
               {
                  enableSoundsToolStripMenuItem->Checked = false; // disables sound
                  try
                  {
                     player->SoundLocation = "Sounds\\TMAN.wav"; // enables music
                     player->PlayLooping();
                  }
                  catch(Win32Exception^ ex)
                  {
                     MessageBox::Show(ex->Message);
                  }
               }
               else
               {
                  try
                  {
                     player->Stop();
                  }
                  catch(Win32Exception^ ex)
                  {
                     MessageBox::Show(ex->Message);
                  }
               }
            }
   //----------------------------------------------------------------------------
   // Resets the window for the game
   //----------------------------------------------------------------------------
   private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
               if(MessageBox::Show("Are you sure you want to restart the game??", "Restart", 
                  MessageBoxButtons::OKCancel, MessageBoxIcon::Information) == ::DialogResult::OK)
               {
                  gameTimer->Enabled = false;
                  list->~VBotList();
                  gamePanel->Refresh();
               }
            }
   };
}
