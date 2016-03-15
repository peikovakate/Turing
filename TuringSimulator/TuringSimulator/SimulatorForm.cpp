#include "SimulatorForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TuringSimulator::SimulatorForm form;
	Application::Run(%form);
}