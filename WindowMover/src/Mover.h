#pragma once

#include "Utils.h"
#include <string>

class Mover {
public:
  enum class Layout {
    LEFT_CENTER, CENTER, RIGHT_CENTER, CURRENT, __LAST
  };
public:
  Mover(const std::string& programName);
  ~Mover();
  void move(const Layout& layout, HWND hwnd);
  std::string getLayoutString(const Layout& layout);
  inline std::string getWindowName() { return mWindowName; }
private:
  WindowMoverUtils::Position getCenterCoords(const HWND& hwnd);
  WindowMoverUtils::Position getLeftCenterCoords(const HWND& hwnd);
  WindowMoverUtils::Position getRightCenterCoords(const HWND& hwnd);
  void setTaskbarHeight();
private:
  std::string mWindowName;
  Layout mLayout;
  int mTaskbarHeight;
  WindowMoverUtils::WindowSize mWindowSize;
  WindowMoverUtils::WindowSize mDesktopSize;
};
