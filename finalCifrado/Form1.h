#pragma once
//#include "utils.h"
#include "Header.h"
using namespace System::Runtime::InteropServices;

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(27, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(246, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Algoritmo de cifrado.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label2->Location = System::Drawing::Point(27, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(790, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Introduce un mensaje en el siguiente cuadro de texto y haz clic en el botón Cifra"
				L"r";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label5->Location = System::Drawing::Point(846, 416);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Equipo 2";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label3->Location = System::Drawing::Point(27, 227);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(824, 26);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Introduce un mensaje en el siguiente cuadro de texto y haz clic en el botón Desci"
				L"frar";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(32, 143);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(778, 30);
			this->textBox1->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(822, 140);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 37);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Cifrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox2->Location = System::Drawing::Point(32, 296);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(778, 30);
			this->textBox2->TabIndex = 9;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2->Location = System::Drawing::Point(822, 293);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 37);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Descifrar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(971, 454);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Algoritmo de cifrado. Equipo 2.";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ name;
	name = textBox1->Text;
	if (name->Length % 2) {
		name += " ";
	}

	std::string nName = static_cast<const char*>(Marshal::StringToHGlobalAnsi(name).ToPointer());
	//	callNative(nName); // Call to C++ native

	textBox1->Text = gcnew String(cifradoPrincipal(nName).c_str()); ;


}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ name;
	name = textBox2->Text;
	std::string nName = static_cast<const char*>(Marshal::StringToHGlobalAnsi(name).ToPointer());
	textBox2->Text = gcnew String(descifradoPrincipal(nName).c_str()); ;


}
};
}
