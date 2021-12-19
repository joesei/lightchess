
#ifndef LIGHTCHESS_SRC_FRAME_MAIN_H_
#define LIGHTCHESS_SRC_FRAME_MAIN_H_


#include <wx/wx.h>


class FrameMain : public wxFrame {
 public:
  FrameMain();
  ~FrameMain();

  // Main Window
  wxBoxSizer *btn_sizer = nullptr;
  wxButton *singleplayer = nullptr;
  wxButton *multiplayer = nullptr;
  wxButton *settings = nullptr;

  // Color Select Window
  wxStaticText *color_select_text = nullptr;
  wxButton *btn_white = nullptr;
  wxButton *btn_black = nullptr;

  wxDECLARE_EVENT_TABLE();
  void SPButtonClicked(wxCommandEvent &event);
  void MPButtonClicked(wxCommandEvent &event);
  void SettingsButtonClicked(wxCommandEvent &event);
  void OnSizeChange(wxSizeEvent &event);

  enum class Frames {
    kMain,
    kColorSelect,
    kChess
  };

  Frames frame;

 private:
  void DisplayMainMenu();
  void DisplayColorSelect();

};

enum Buttons {
  kSingleplayer,
  kMultiplayer,
  kSettings,
  kWhite,
  kBlack
};



#endif //LIGHTCHESS_SRC_FRAME_MAIN_H_
