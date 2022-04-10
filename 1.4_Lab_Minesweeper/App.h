#pragma once
#include "wx/wx.h"

class Stage;

class App: public wxApp
{
private:
	Stage* stage = nullptr;
public:
	App();
	~App();
	virtual bool OnInit();
};

