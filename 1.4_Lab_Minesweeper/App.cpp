#include "App.h"
#include "Stage.h"

wxIMPLEMENT_APP(App);

App::App()
{

}
App::~App()
{

}
bool App::OnInit()
{
	stage = new Stage();
	stage->Show();
	return true;
}
