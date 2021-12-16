
#include "chess_main.h"

// Set entry point of program
wxIMPLEMENT_APP(GUIApp);

GUIApp::GUIApp() {

}

GUIApp::~GUIApp() {

}

bool GUIApp::OnInit() {
  frame_main = new FrameMain();
  frame_main->CenterOnParent();
  frame_main->Show();

  return true;
}