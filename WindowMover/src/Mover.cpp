#include "Mover.h"
#include <iostream>

Mover::Mover(const std::string& programName) 
  : mWindowName(programName), mLayout(Layout::CENTER) {
  setTaskbarHeight();
}

Mover::~Mover() {

}

void Mover::move(const Layout& layout, HWND hwnd) {
  // Clear the console before moving a window.
  system("cls");

  if(!hwnd) {
    std::cout << "\"" << mWindowName << "\" is not currently running." << std::endl << std::endl;
    return;
  }

  if(!IsWindow(hwnd)) {
    std::cout << "\"" << mWindowName << "\" no longer exists." << std::endl << std::endl;
    return;
  }

  mLayout = layout;

  if(mLayout == Layout::CURRENT) {
    std::cout << "Keeping \"" << mWindowName << "\" where it is..." << std::endl << std::endl;
    return;
  }

  // If the window is currently minimized, restore it before moving.
  handleMinimized(hwnd);

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
    std::cout << "Moving \"" << mWindowName << "\"..." << std::endl;
    std::cout << "Window Size: " << windowSize[(int)WindowDimension::WIDTH] << "x" << windowSize[(int)WindowDimension::HEIGHT] << std::endl;
    std::cout << "Desktop Size: " << desktopSize[(int)WindowDimension::WIDTH] << "x" << desktopSize[(int)WindowDimension::HEIGHT] << std::endl;
    std::cout << "Moved Location: " << coords[(int)PositionComponent::X] << ", " << coords[(int)PositionComponent::Y] << std::endl << std::endl;

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
  y = ((desktopSize[(int)WindowDimension::HEIGHT] - mTaskbarHeight) - windowSize[(int)WindowDimension::HEIGHT]) / 2;

  return std::vector<int> {x, y};
}

std::vector<int> Mover::getLeftCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize) {
  int x, y;
  x = ((desktopSize[(int)WindowDimension::WIDTH] / 2) - windowSize[(int)WindowDimension::WIDTH]) / 2;
  y = ((desktopSize[(int)WindowDimension::HEIGHT] - mTaskbarHeight) - windowSize[(int)WindowDimension::HEIGHT]) / 2;

  return std::vector<int> {x, y};
}

std::vector<int> Mover::getRightCenterCoords(const HWND& hwnd, const std::vector<int>& windowSize, const std::vector<int>& desktopSize) {
  int x, y;
  x = (desktopSize[(int)WindowDimension::WIDTH] / 2) + (((desktopSize[(int)WindowDimension::WIDTH] / 2) - windowSize[(int)WindowDimension::WIDTH]) / 2);
  y = ((desktopSize[(int)WindowDimension::HEIGHT] - mTaskbarHeight) - windowSize[(int)WindowDimension::HEIGHT]) / 2;

  return std::vector<int> {x, y};
}

void Mover::setTaskbarHeight() {
  APPBARDATA data;
  data.cbSize = sizeof(data);
  SHAppBarMessage(ABM_GETTASKBARPOS, &data);
  mTaskbarHeight = data.rc.bottom - data.rc.top;
}

std::string Mover::getLayoutString(const Layout& layout) {
  if(layout == Layout::LEFT_CENTER) {
    return "Centered - Left Half";
  }
  else if(layout == Layout::CENTER) {
    return "Centered - Middle";
  }
  else if(layout == Layout::RIGHT_CENTER) {
    return "Centered - Right Half";
  }
  else if(layout == Layout::CURRENT) {
    return "Keep the current position";
  }

  return "";
}

void Mover::handleMinimized(const HWND& hwnd) {
  WINDOWPLACEMENT placement;
  memset(&placement, 0, sizeof(WINDOWPLACEMENT));
  placement.length = sizeof(WINDOWPLACEMENT);
  GetWindowPlacement(hwnd, &placement);

  switch(placement.showCmd) {
  case SW_SHOWMINIMIZED:
    ShowWindow(hwnd, SW_RESTORE);
    break;
  default:
    ShowWindow(hwnd, SW_NORMAL);
    break;
  }

  SetForegroundWindow(hwnd);
}