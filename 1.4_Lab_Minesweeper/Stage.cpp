#include "Stage.h"

wxBEGIN_EVENT_TABLE(Stage,wxFrame)
EVT_BUTTON(10001, OnButtonClick)
wxEND_EVENT_TABLE()

Stage::Stage() : wxFrame(nullptr, wxID_ANY,"Game", wxPoint(30, 30), wxSize(800,800))
{
	btns = new wxButton * [btnWidth * btnHeight];
	wxGridSizer* grid = new wxGridSizer(btnWidth, btnHeight, 0, 0);

	button = new int[btnWidth * btnHeight];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0; x < btnWidth; x++)
	{
		for (int y = 0; y < btnHeight; y++)
		{
			btns[y * btnWidth + x] = new wxButton(this, 1000 + (y * btnWidth + x));
			btns[y * btnWidth + x]->SetFont(font);
			grid->Add(btns[y * btnWidth + x], 1, wxEXPAND | wxALL);

			btns[y * btnWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Stage::OnButtonClick, this);
			button[y * btnWidth + x] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();

}
Stage::~Stage()
{
	delete[]btns;
}

void Stage::OnButtonClick(wxCommandEvent &evt)
{
	int x = (evt.GetId() - 1000) % btnWidth;
	int y = (evt.GetId() - 1000) / btnWidth;

	if (Radar)
	{
		int Explosives = 30;

		while (Explosives)
		{
			int rx = rand() % btnWidth;
			int ry = rand() % btnHeight;

			if (button[ry * btnWidth + rx] == 0 && rx != x && ry != y)
			{
				button[ry * btnWidth + rx] = -1;
				Explosives--;
			}
		}
		Radar = false;

	}
	btns[ y * btnWidth + x]->Enable(false);
	

	if (button[y*btnWidth + x] == -1)
	{
		wxMessageBox("BOOOOOOOOOOOOM!!! ---- Game Over----");

			Radar = true;
			for (int x = 0; x < btnWidth; x++)
			{
				for (int y = 0; y < btnHeight; y++)
				{
					button[y * btnWidth + x] = 0;
					btns[y * btnWidth + x]->SetLabel("");
					btns[y * btnWidth + x]->Enable(true);
				}
			}
	}
	else
	{
		int Blown = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (x + i >= 0 && x + i < btnWidth && y + j >= 0 && y + j < btnHeight)
				{
					if (button[(y + j) * btnWidth + (x + i)] == -1)
					{
						Blown++;
					}
				}
			}
		}
		if (Blown > 0)
		{
			btns[y * btnWidth + x]->SetLabel(std::to_string(Blown));
		}
	}

	evt.Skip();
}