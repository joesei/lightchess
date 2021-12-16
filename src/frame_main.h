
#ifndef LIGHTCHESS_SRC_FRAME_MAIN_H_
#define LIGHTCHESS_SRC_FRAME_MAIN_H_


#include <wx/wx.h>


class FrameMain : public wxFrame {
 public:
  FrameMain();
  ~FrameMain();
  wxBoxSizer *button_sizer = nullptr;
  wxButton *singleplayer = nullptr;
  wxButton *multiplayer = nullptr;
  wxButton *settings = nullptr;

  wxDECLARE_EVENT_TABLE();
  void SPButtonClicked(wxCommandEvent &event);
  void MPButtonClicked(wxCommandEvent &event);
  void SettingsButtonClicked(wxCommandEvent &event);

 private:
  void DisplayMainMenu();
  void DisplayColorSelect();

};

enum Buttons {
  kSingleplayer,
  kMultiplayer,
  kSettings
};

#endif //LIGHTCHESS_SRC_FRAME_MAIN_H_
