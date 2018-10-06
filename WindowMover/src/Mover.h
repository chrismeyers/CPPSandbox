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
    LEFT_CENTER, CENTER, RIGHT_CENTER, CURRENT, __LAST
  };
public:
  Mover(const std::string& programName);
  ~Mover();
  void move(const Layout& layout, HWND hwnd);
  std::string getLayoutString(const Layout& layout);
  std::string getWindowName() { return mWindowName; }
private:
  std::vector<int> getWindowSize(const HWND& hwnd);
  std::vector<int> getDesktopSize();
  std::vector<int> getCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize);
  std::vector<int> getLeftCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize);
  std::vector<int> getRightCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize);
  void setTaskbarHeight();
  void handleMinimized(const HWND& hwnd);
private:
  std::string mWindowName;
  Layout mLayout;
  int mTaskbarHeight;
};
