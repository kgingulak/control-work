#pragma once

namespace collatz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ name_prog_label;
	protected:
	private: System::Windows::Forms::Button^ result_button;
	private: System::Windows::Forms::Label^ number_label;
	private: System::Windows::Forms::Label^ length_label;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->name_prog_label = (gcnew System::Windows::Forms::Label());
			this->result_button = (gcnew System::Windows::Forms::Button());
			this->number_label = (gcnew System::Windows::Forms::Label());
			this->length_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// name_prog_label
			// 
			this->name_prog_label->AutoSize = true;
			this->name_prog_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->name_prog_label->Location = System::Drawing::Point(45, 30);
			this->name_prog_label->Name = L"name_prog_label";
			this->name_prog_label->Size = System::Drawing::Size(295, 16);
			this->name_prog_label->TabIndex = 0;
			this->name_prog_label->Text = L"Наибольшая последовательность Коллатца";
			// 
			// result_button
			// 
			this->result_button->Location = System::Drawing::Point(150, 200);
			this->result_button->Name = L"result_button";
			this->result_button->Size = System::Drawing::Size(75, 23);
			this->result_button->TabIndex = 1;
			this->result_button->Text = L"Вычислить";
			this->result_button->UseVisualStyleBackColor = true;
			this->result_button->Click += gcnew System::EventHandler(this, &MyForm::result_button_Click);
			// 
			// number_label
			// 
			this->number_label->AutoSize = true;
			this->number_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->number_label->Location = System::Drawing::Point(20, 80);
			this->number_label->Name = L"number_label";
			this->number_label->Size = System::Drawing::Size(227, 32);
			this->number_label->TabIndex = 2;
			this->number_label->Text = L"Число порождающее наибольшую\r\nпоследовательность:";
			// 
			// length_label
			// 
			this->length_label->AutoSize = true;
			this->length_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->length_label->Location = System::Drawing::Point(20, 150);
			this->length_label->Name = L"length_label";
			this->length_label->Size = System::Drawing::Size(193, 16);
			this->length_label->TabIndex = 3;
			this->length_label->Text = L"Длина последовательности:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 261);
			this->Controls->Add(this->length_label);
			this->Controls->Add(this->number_label);
			this->Controls->Add(this->result_button);
			this->Controls->Add(this->name_prog_label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Наибольшая послед. Коллатца";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void result_button_Click(System::Object^ sender, System::EventArgs^ e) {
		result_button->Enabled = false;

		System::Collections::Generic::Dictionary<long long int, int>^ dict =
			gcnew System::Collections::Generic::Dictionary<long long int, int>();

		int max_length = 0;
		int result_number = 0;

		for (int n = 1; n < 1000000; n++)
		{
			int length = 0;
			long long int temp = n;

			while(temp != 1)
			{
				if (dict->ContainsKey(temp))
				{
					length += dict[temp];
					break;
				}
				else if (temp % 2 == 0)
				{
					temp /= 2;
					length++;
				}
				else
				{
					temp = (temp * 3 + 1);
					length++;
				}
			}

			if (max_length < length)
			{
				max_length = length;
				result_number = n;
			}

			if (!dict->ContainsKey(n))
				dict->Add(n, length);
		}

		number_label->Text = ("Число порождающее наибольшую" + "\n" + "последовательность: " + result_number);
		length_label->Text = ("Длина последовательности: " + max_length);
		result_button->Enabled = true;
	}
};
}
