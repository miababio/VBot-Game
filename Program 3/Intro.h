//---------------------------------------------------------------------------
// Name:    Michael Ababio
//
// Project: Program 3 - BOT wars Visual C++ Windows Program  
//
// Purpose: This is the form class, which creates the introductory window
//          for the VBot game.          
//---------------------------------------------------------------------------
#pragma once
#include "MyForm.h"

namespace Program3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Intro
	/// </summary>
	public ref class Intro : public System::Windows::Forms::Form
	{
	public:
		Intro(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			player = gcnew SoundPlayer("Sounds\\ThanksForPlaying.wav"); //loads sound file
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Intro()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Label^  label1;
   protected: 
   private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
   private:
      SoundPlayer ^player;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Intro::typeid));
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->BackColor = System::Drawing::Color::Transparent;
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(148, 47);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(701, 108);
         this->label1->TabIndex = 0;
         this->label1->Text = L"WELCOME TO";
         this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->BackColor = System::Drawing::Color::Transparent;
         this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label2->Location = System::Drawing::Point(198, 454);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(630, 108);
         this->label2->TabIndex = 1;
         this->label2->Text = L"VBOT WARS";
         this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // Intro
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
         this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
         this->ClientSize = System::Drawing::Size(1008, 730);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->label1);
         this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
         this->Name = L"Intro";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Welcome";
         this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Intro::Intro_MouseClick);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

	private: System::Void Intro_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
					MyForm^ newForm = gcnew MyForm;
					MessageBox::Show("Welcome to VBot Wars!! Click OK to continue", "Welcome!!", MessageBoxButtons::OK);
               try
               {
                  player->Load();
                  player->PlaySync();
               }
               catch(Win32Exception^ ex)
               {
                  MessageBox::Show(ex->Message);
               }
					this->Hide();
					newForm->Show();
					newForm->BringToFront();
				}
	};
}
