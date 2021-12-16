

#ifndef LIGHTCHESS_SRC_CHESS_MAIN_H_
#define LIGHTCHESS_SRC_CHESS_MAIN_H_


#include <wx/wx.h>

#include "frame_main.h"



class GUIApp : public wxApp
{
 public:
  GUIApp();
  ~GUIApp();
  bool OnInit() override;

 private:
  FrameMain *frame_main = nullptr;

};




#endif //LIGHTCHESS_SRC_CHESS_MAIN_H_
