#include "Mover.h"
#include <iostream>

Mover::Mover(const std::string& programName) 
  : mWindowName(programName), mLayout(Layout::CENTER) {

}

Mover::~Mover() {

}

void Mover::move(const Layout& layout, HWND hwnd) {
  mLayout = layout;

  std::cout << mWindowName << std::endl;

  std::vector<int> windowSize = getWindowSize(hwnd);
  std::vector<int> desktopSize = getDesktopSize();
  std::vector<int> coords;

  if(mLayout == Layout::CENTER) {
    coords = getCenterCoords(hwnd, windowSize, desktopSize);
  }
  else if(mLayout == Layout::LEFT_CENTER) {
    coords = getLeftCenterCoords(hwnd, windowSize, desktopSize);
  }
  else if(mLayout == Layout::RIGHT_CENTER) {
    coords = getRightCenterCoords(hwnd, windowSize, desktopSize);
  }

  if(!windowSize.empty() && !coords.empty()) {
    std::cout << "Window Size: " << windowSize[(int)WindowDimension::WIDTH] << "x" << windowSize[(int)WindowDimension::HEIGHT] << std::endl;
    std::cout << "Desktop Size: " << desktopSize[(int)WindowDimension::WIDTH] << "x" << desktopSize[(int)WindowDimension::HEIGHT] << std::endl;
    std::cout << "Moved Location: " << coords[(int)PositionComponent::X] << ", " << coords[(int)PositionComponent::Y] << std::endl;

    MoveWindow(hwnd,
      coords[(int)PositionComponent::X], coords[(int)PositionComponent::Y],
      windowSize[(int)WindowDimension::WIDTH], windowSize[(int)WindowDimension::HEIGHT],
      true);
  }
}

std::vector<int> Mover::getWindowSize(const HWND& hwnd) {
  RECT window;
  GetWindowRect(hwnd, &window);
  int windowWidth = window.right - window.left;
  int windowHeight = window.bottom - window.top;

  return std::vector<int> {windowWidth, windowHeight};
}

std::vector<int> Mover::getDesktopSize() {
  RECT desktop;
  GetWindowRect(GetDesktopWindow(), &desktop);
  int desktopWidth = desktop.right - desktop.left;
  int desktopHeight = desktop.bottom - desktop.top;

  return std::vector<int> {desktopWidth, desktopHeight};
}

std::vector<int> Mover::getCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize) {
  int x, y;
  x = (desktopSize[(int)WindowDimension::WIDTH] - windowSize[(int)WindowDimension::WIDTH]) / 2;
  y = ((desktopSize[(int)WindowDimension::HEIGHT] - Mover::TASKBAR_HEIGHT) - windowSize[(int)WindowDimension::HEIGHT]) / 2;

  return std::vector<int> {x, y};
}

std::vector<int> Mover::getLeftCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize) {
  int x, y;
  x = ((desktopSize[(int)WindowDimension::WIDTH] / 2) - windowSize[(int)WindowDimension::WIDTH]) / 2;
  y = ((desktopSize[(int)WindowDimension::HEIGHT] - Mover::TASKBAR_HEIGHT) - windowSize[(int)WindowDimension::HEIGHT]) / 2;

  return std::vector<int> {x, y};
}

std::vector<int> Mover::getRightCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize) {
  int x, y;
  x = (desktopSize[(int)WindowDimension::WIDTH] / 2) + (((desktopSize[(int)WindowDimension::WIDTH] / 2) - windowSize[(int)WindowDimension::WIDTH]) / 2);
  y = ((desktopSize[(int)WindowDimension::HEIGHT] - Mover::TASKBAR_HEIGHT) - windowSize[(int)WindowDimension::HEIGHT]) / 2;

  return std::vector<int> {x, y};
}
