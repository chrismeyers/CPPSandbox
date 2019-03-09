#include "Lister.h"
#include "Mover.h"
#include "Resizer.h"
#include "Utils.h"
#include <iostream>
#include <vector>

bool run() {
  Lister lister = Lister();
  Lister::WindowList windows = lister.getWindowList();

  std::cout << "Usage:\n"
            << "  - Press Enter to reload list\n"
            << "  - Exit by typing \"q\", \"quit\", or \"exit\"\n"
            << "  - Start over by typing \"r\" or \"restart\"\n" << std::endl;

  // Select the window to move.
  std::vector<std::string> windowNames;
  int i = 0;
  for(auto& window : windows) {
    DWORD pid;
    GetWindowThreadProcessId(window.second, &pid);

    windowNames.push_back(window.first);
    std::cout << i + 1 << ": " << window.first << " [" << pid << "]" << std::endl;
    i++;
  }

  std::string selectedWindow;
  do {
    std::cout << "Select a window to move: ";
    std::getline(std::cin, selectedWindow);
    if(WindowMoverUtils::shouldRestart(selectedWindow) || selectedWindow.empty()) {
      return true; // Refresh the list if blank input.
    }
  } while(!WindowMoverUtils::validSelection(selectedWindow, i));

  int windowNum = std::stoi(selectedWindow);
  windowNum--;

  // Resize the window.
  std::cout << "Change the size of the window? [y/N]: ";
  std::string shouldChangeSize;
  std::getline(std::cin, shouldChangeSize);
  if(WindowMoverUtils::shouldRestart(shouldChangeSize)) {
    return true;
  }
  else if(WindowMoverUtils::validYes(shouldChangeSize)) {
    Resizer resizer = Resizer(windowNames[windowNum]);

    std::string windowSize;
    do {
      WindowMoverUtils::WindowSize maxSize = WindowMoverUtils::getMaxWindowSize();
      std::cout << "Specify a size (max: " << maxSize.width << "x" << maxSize.height << "): ";
      std::getline(std::cin, windowSize);
      if(WindowMoverUtils::shouldRestart(windowSize)) {
        return true;
      }
    } while(!WindowMoverUtils::shouldExit(windowSize) && !resizer.parseSize(windowSize));

    resizer.resize(windows[resizer.getWindowName()]);
  }

  // Select the Layout.
  Mover mover = Mover(windowNames[windowNum]);

  for(i = 0; i < (int)Mover::Layout::__LAST; i++) {
    std::cout << i + 1 << ": " << mover.getLayoutString((Mover::Layout)i) << std::endl;
  }

  std::string positionSelection;
  do {
    std::cout << "Select a layout: ";
    std::getline(std::cin, positionSelection);
    if(WindowMoverUtils::shouldRestart(positionSelection)) {
      return true;
    }
  } while(!WindowMoverUtils::validSelection(positionSelection, i));

  int windowPosition = std::stoi(positionSelection);
  windowPosition--;

  mover.move((Mover::Layout)windowPosition, windows[mover.getWindowName()]);

  system("pause");
  return true;
}

int main() {
  while(1) {
    if(run()) {
      system("cls"); // Clear the console on success or restart.
    }
  }

  return 0;
}

