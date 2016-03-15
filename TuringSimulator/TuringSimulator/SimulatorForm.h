#pragma once
#include "TuringLogic.h"


namespace TuringSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// —водка дл€ SimulatorForm
	/// </summary>
	public ref class SimulatorForm : public System::Windows::Forms::Form
	{

	public:
		SimulatorForm(void)
		{
			InitializeComponent();
			TuringMachine t();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SimulatorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;

	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  calculate;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  reset;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  move;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnB;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Tape;
	private: System::Windows::Forms::Button^  play;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  pause;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->calculate = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->move = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Tape = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->play = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pause = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(20, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(80, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(120, 40);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(80, 20);
			this->textBox2->TabIndex = 1;
			// 
			// calculate
			// 
			this->calculate->Location = System::Drawing::Point(320, 40);
			this->calculate->Name = L"calculate";
			this->calculate->Size = System::Drawing::Size(80, 20);
			this->calculate->TabIndex = 2;
			this->calculate->Text = L"Calculate";
			this->calculate->UseVisualStyleBackColor = true;
			this->calculate->Click += gcnew System::EventHandler(this, &SimulatorForm::calculate_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(220, 40);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(80, 20);
			this->textBox3->TabIndex = 3;
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(406, 40);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(80, 20);
			this->reset->TabIndex = 4;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &SimulatorForm::reset_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(100, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L" -";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(200, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 7;
			// 
			// move
			// 
			this->move->Enabled = false;
			this->move->Location = System::Drawing::Point(406, 66);
			this->move->Name = L"move";
			this->move->Size = System::Drawing::Size(80, 23);
			this->move->TabIndex = 8;
			this->move->Text = L"move";
			this->move->UseVisualStyleBackColor = true;
			this->move->Click += gcnew System::EventHandler(this, &SimulatorForm::move_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column0,
					this->Column1, this->ColumnB
			});
			this->dataGridView1->Enabled = false;
			this->dataGridView1->Location = System::Drawing::Point(20, 103);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(349, 282);
			this->dataGridView1->TabIndex = 9;
			// 
			// Column0
			// 
			this->Column0->HeaderText = L"0";
			this->Column0->Name = L"Column0";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"1";
			this->Column1->Name = L"Column1";
			// 
			// ColumnB
			// 
			this->ColumnB->HeaderText = L"B";
			this->ColumnB->Name = L"ColumnB";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Tape });
			this->dataGridView2->Enabled = false;
			this->dataGridView2->Location = System::Drawing::Point(406, 103);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 40;
			this->dataGridView2->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->Size = System::Drawing::Size(85, 282);
			this->dataGridView2->TabIndex = 10;
			// 
			// Tape
			// 
			this->Tape->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Tape->HeaderText = L"";
			this->Tape->Name = L"Tape";
			// 
			// play
			// 
			this->play->Location = System::Drawing::Point(320, 66);
			this->play->Name = L"play";
			this->play->Size = System::Drawing::Size(80, 23);
			this->play->TabIndex = 11;
			this->play->Text = L">";
			this->play->UseVisualStyleBackColor = true;
			this->play->Click += gcnew System::EventHandler(this, &SimulatorForm::play_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &SimulatorForm::timer1_Tick);
			// 
			// pause
			// 
			this->pause->Location = System::Drawing::Point(320, 66);
			this->pause->Name = L"pause";
			this->pause->Size = System::Drawing::Size(80, 23);
			this->pause->TabIndex = 12;
			this->pause->Text = L"||";
			this->pause->UseVisualStyleBackColor = true;
			this->pause->Visible = false;
			this->pause->Click += gcnew System::EventHandler(this, &SimulatorForm::pause_Click);
			// 
			// SimulatorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(553, 404);
			this->Controls->Add(this->pause);
			this->Controls->Add(this->play);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->move);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->calculate);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"SimulatorForm";
			this->Text = L"SimulatorForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: TuringMachine* t; //указатель на обьект машины тьюринга 
	private: System::Void calculate_Click(System::Object^  sender, System::EventArgs^  e) {
		int a, b;
		try {
			a = Convert::ToInt32(textBox1->Text); //считываем числа
			b = Convert::ToInt32(textBox2->Text);
		}
		catch (...) {
			a = b = 1;
		}
		TuringMachine* tm = new TuringMachine(a, b); // создает обьект
		t = tm;
		vector<vector<string>> v = t->getinstructions();
		for (int i = 0; i<v.size(); i++) { // заполн€ет таблицу инструкций
			dataGridView1->Rows->Add();
			for (int j = 0; j < v[i].size(); j++) {
				String^ rule = gcnew String(v[i][j].c_str());
				dataGridView1->Rows[i]->Cells[j]->Value = rule;
			}
		}
		string tape = t->getTape(); 
		for (int i = 0; i < tape.size(); i++) { // заполн€ет ленту
			dataGridView2->Rows->Add();
			dataGridView2->Rows[i]->Cells[0]->Value = Convert::ToString(Convert::ToChar(tape[i]));
		}
		calculate->Enabled = false;
		move->Enabled = true;
	}
private: System::Void reset_Click(System::Object^  sender, System::EventArgs^  e) {
	calculate->Enabled = true;
	move->Enabled = false;
	dataGridView1->Rows->Clear();
	dataGridView2->Rows->Clear();
	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
	timer1->Stop();
	play->Visible = true;
	pause->Visible = false;
}
private: System::Void makeStep() {
	if (t->running() == true) { //если состо€ние не €вл€етс€ конечным
		int step = t->move();
		int i = t->getState();
		int j = t->getNumberOfSymbol();
		dataGridView1->CurrentCell = dataGridView1->Rows[i]->Cells[j];
		int curIndex = dataGridView2->CurrentRow->Index;
		dataGridView2->CurrentCell->Value = Convert::ToString(Convert::ToChar(t->getSymbolAt(curIndex)));
		curIndex += step;
		//когда  выходит за пределы видимой ленты
		if (curIndex >= dataGridView2->RowCount) {
			dataGridView2->Rows->Add();
		}
		else if (curIndex < 0) {
			dataGridView2->Rows->Insert(0);
			curIndex = 0;
		}
		dataGridView2->CurrentCell = dataGridView2->Rows[curIndex]->Cells[0]; // двигаем каретку
	}
	else {
		String^ res = Convert::ToString(t->result());
		textBox3->Text = res;
	}
}
private: System::Void move_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		this->makeStep();
	}
	catch (...) {
		label3->Text = "ќшибка";
	}
}

private: System::Void play_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	play->Visible = false;
	pause->Visible = true;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->makeStep();
}
private: System::Void pause_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	play->Visible = true;
	pause->Visible = false;
}
};
}
