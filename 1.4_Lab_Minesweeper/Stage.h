#pragma once
#include "wx/wx.h"

class Stage : public wxFrame
{
public:
	int btnWidth = 10;
	int btnHeight = 10;
	wxButton **btns;
	int* button = nullptr;
	bool Radar = true;
public:
	Stage();
	~Stage();

	void OnButtonClick(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();
};

