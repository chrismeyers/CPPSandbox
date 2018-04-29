#pragma once

#include <windows.h>
#include <vector>
#include <string>

class Mover {
public:
  enum class WindowDimension {
    WIDTH, HEIGHT
  };
  enum class PositionComponent {
    X, Y
  };
  enum class Layout {
    LEFT_CENTER, CENTER, RIGHT_CENTER, __LAST
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
  void setTaskbarHeight();
  std::string getWindowName() { return mWindowName; }
  std::string getLayoutString(const Layout& layout);
private:
  std::string mWindowName;
  Layout mLayout;
  int mTaskbarHeight;
};
