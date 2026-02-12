#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Task 1 - Number Gussing game::MyForm form;
	Application::Run(% form);
}