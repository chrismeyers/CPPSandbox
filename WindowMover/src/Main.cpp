#include "Lister.h"
#include "Mover.h"
#include <iostream>
#include <vector>

void run() {
  Lister lister = Lister();
  Lister::WindowList windows = lister.getWindowList();

  // Select the window to move.
  std::vector<std::string> windowNames;
  int i = 1;
  for(auto& window : windows) {
    windowNames.push_back(window.first);
    std::cout << i << ": " << window.first << std::endl;
    i++;
  }

  std::cout << "Select a window to move: ";
  int windowNum;
  std::cin >> windowNum;
  windowNum--;

  // Select the Layout.
  Mover mover = Mover(windowNames[windowNum]);

  for(int i = 0; i < (int)Mover::Layout::__LAST; i++) {
    std::cout << i + 1 << ": " << mover.getLayoutString((Mover::Layout)i) << std::endl;
  }

  std::cout << "Select a layout: ";
  int windowPosition;
  std::cin >> windowPosition;
  windowPosition--;

  mover.move((Mover::Layout)windowPosition, windows[mover.getWindowName()]);
}

int main() {
  while(1) {
    run();
    std::cout << std::endl;
  }

  return 0;
}

