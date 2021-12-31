
#include "frame_main.h"


// NOTE: Using Bind function instead of event table may cause memory leak when the child objects
//       of FrameMain (i.e. buttons) are deleted
wxBEGIN_EVENT_TABLE(FrameMain, wxFrame)
  EVT_BUTTON(kSingleplayer, FrameMain::SPButtonClicked)
  EVT_BUTTON(kMultiplayer, FrameMain::MPButtonClicked)
  EVT_BUTTON(kSettings, FrameMain::SettingsButtonClicked)
  EVT_BUTTON(kWhite, FrameMain::ColorButtonClicked)
  EVT_BUTTON(kBlack, FrameMain::ColorButtonClicked)
  EVT_SIZE(FrameMain::OnSizeChange)
wxEND_EVENT_TABLE()

FrameMain::FrameMain() : wxFrame(nullptr, wxID_ANY, "lightchess") {
  DisplayMainMenu();
}

FrameMain::~FrameMain() {
  delete[] squares;
}


void FrameMain::SPButtonClicked(wxCommandEvent &event) {
  DisplayColorSelect();
  event.Skip();
}

void FrameMain::MPButtonClicked(wxCommandEvent &event) {

  event.Skip();
}

void FrameMain::SettingsButtonClicked(wxCommandEvent &event) {

  event.Skip();
}

void FrameMain::ColorButtonClicked(wxCommandEvent &event) {
  wxString color = ((wxButton*)(event.GetEventObject()))->GetLabel();
  is_white = (color == "White");
  DisplayChess();
  event.Skip();
}

void FrameMain::OnSizeChange(wxSizeEvent &event) {

  int height = this->GetSize().GetHeight();
  int width = this->GetSize().GetWidth();
  if (frame == Frames::kMain) {

    int btn_height = height / 12;
    int btn_width = width / 4;

    singleplayer->SetSize(wxSize(btn_width, btn_height));
    singleplayer->SetPosition(wxPoint(width / 2 - (btn_width / 2), height * 0.475));

    multiplayer->SetSize(wxSize(btn_width, btn_height));
    multiplayer->SetPosition(wxPoint(width / 2 - (btn_width / 2), height * 0.6));

    settings->SetSize(wxSize(btn_width, btn_height));
    settings->SetPosition(wxPoint(width / 2 - (btn_width / 2), height * 0.725));

  } else if (frame == Frames::kColorSelect) {

    // 1 point = 1.333 pixels
    auto font = wxFont(height / 25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    color_select_text->SetFont(font);
    color_select_text->SetPosition(wxPoint(40, 40));

    int btn_height = height / 12;
    int btn_width = width / 5;

    btn_white->SetSize(wxSize(btn_width, btn_height));
    btn_black->SetSize(wxSize(btn_width, btn_height));

    btn_white->SetPosition(wxPoint(width * 0.15, height * 0.5));
    btn_black->SetPosition(wxPoint(width * 0.6, height * 0.5));
  }
  event.Skip();

}

void FrameMain::DisplayMainMenu() {
  frame = Frames::kMain;
  this->DestroyChildren();
  singleplayer = new wxButton(this, kSingleplayer, "Singleplayer", wxPoint(0, 0), wxSize(120, 30));
  multiplayer = new wxButton(this, kMultiplayer, "Multiplayer", wxPoint(0, 0), wxSize(120, 30));
  settings = new wxButton(this, kSettings, "Settings", wxPoint(0, 0), wxSize(120, 30));
  btn_sizer = new wxBoxSizer(wxVERTICAL);
  btn_sizer->SetMinSize(wxSize(640, 360));
  SetSizerAndFit(btn_sizer);
}

void FrameMain::DisplayColorSelect() {
  frame = Frames::kColorSelect;
  this->DestroyChildren();

  // Also shown in OnSizeChange
  int height = this->GetSize().GetHeight();
  int width = this->GetSize().GetWidth();

  btn_white = new wxButton(this, kWhite, "White", wxPoint(0, 0), wxSize(120, 30));
  btn_black = new wxButton(this, kBlack, "Black", wxPoint(0, 0), wxSize(120, 30));

  color_select_text = new wxStaticText(this, wxID_ANY, "Select Color:");
  auto font = wxFont(height / 25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
  color_select_text->SetFont(font);
  color_select_text->SetPosition(wxPoint(40, 40));
  int btn_height = height / 12;
  int btn_width = width / 5;

  btn_white->SetSize(wxSize(btn_width, btn_height));
  btn_black->SetSize(wxSize(btn_width, btn_height));

  btn_white->SetPosition(wxPoint(width * 0.15, height * 0.5));
  btn_black->SetPosition(wxPoint(width * 0.6, height * 0.5));
}

void FrameMain::DisplayChess() {
  frame = Frames::kChess;
  this->DestroyChildren();

  board = new wxGridSizer(8, 8, 0, 0);
  squares = new wxButton*[64];

  for (int x = 0; x < 8; ++x) {
    for (int y = 0; y < 8; ++y) {
      squares[y * 8 + x] = new wxButton(this, wxID_ANY);
      board->Add(squares[y * 8 + x], 1, wxEXPAND | wxALL);
    }
  }

  this->SetSizer(board);

  board->Layout();
  this->Update();
}


