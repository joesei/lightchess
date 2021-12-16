
#include <iostream>//print
#include <thread> //sleep
#include <chrono> //sleep
#include "frame_main.h"


// NOTE: Using Bind function instead of event table may cause memory leak when the child objects
//       of FrameMain (i.e. buttons) are deleted
wxBEGIN_EVENT_TABLE(FrameMain, wxFrame)
  EVT_BUTTON(kSingleplayer, FrameMain::SPButtonClicked)
  EVT_BUTTON(kMultiplayer, FrameMain::MPButtonClicked)
  EVT_BUTTON(kSettings, FrameMain::SettingsButtonClicked)
wxEND_EVENT_TABLE()

FrameMain::FrameMain() : wxFrame(nullptr, wxID_ANY, "lightchess") {
  DisplayMainMenu();
}

FrameMain::~FrameMain() {

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

void FrameMain::DisplayMainMenu() {
  this->DestroyChildren();
  singleplayer = new wxButton(this, kSingleplayer, "Singleplayer", wxPoint(20, 20), wxSize(150, 30));
  multiplayer = new wxButton(this, kMultiplayer, "Multiplayer", wxPoint(20, 60), wxSize(150, 30));
  settings = new wxButton(this, kSettings, "Settings", wxPoint(20, 100), wxSize(150, 30));

  button_sizer = new wxBoxSizer(wxVERTICAL);
  wxSizerFlags flags_expand(1);
  flags_expand.Align(10).Center().Border(wxALL, 10);
  button_sizer->Add(singleplayer, flags_expand);
  button_sizer->Add(multiplayer, flags_expand);
  button_sizer->Add(settings, flags_expand);

  SetSizerAndFit(button_sizer);
}

void FrameMain::DisplayColorSelect() {
  this->DestroyChildren();

}


