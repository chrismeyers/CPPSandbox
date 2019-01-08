#pragma once

#include <windows.h>
#include <string>

namespace WindowMoverUtils {
  struct WindowSize {
    int width;
    int height;
  };

  struct Position {
    int X;
    int Y;
  };

  WindowSize getWindowSize(const HWND& hwnd);
  WindowSize getMaxWindowSize();
  bool shouldExit(std::string s);
  bool shouldRestart(std::string s);
  bool validYes(std::string s);
  bool validSelection(const std::string& s, int max);
  void bringToFront(const HWND& hwnd);
}