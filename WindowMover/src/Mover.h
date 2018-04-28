#pragma once

#include <windows.h>
#include <vector>
#include <string>

class Mover {
public:
  static const int TASKBAR_HEIGHT = 40;
  enum class WindowDimension {
    WIDTH, HEIGHT
  };
  enum class PositionComponent {
    X, Y
  };
  enum class Layout {
    CENTER, LEFT_CENTER, RIGHT_CENTER
  };
public:
  Mover(const std::string& programName);
  ~Mover();
  void move(const Layout& layout, HWND hwnd);
  std::vector<int> getWindowSize(const HWND& hwnd);
  std::vector<int> getDesktopSize();
  std::vector<int> getCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize);
  std::vector<int> getLeftCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize);
  std::vector<int> getRightCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize);
  std::string getWindowName() { return mWindowName; }
private:
  std::string mWindowName;
  Layout mLayout;
};
