#include "Lister.h"
#include "Mover.h"
#include <iostream>
#include <vector>
#include <string>

bool validSelection(const std::string& s, const int& max) {
  if(s == "q" || s == "quit" || s == "exit") {
    exit(0);
  }

  // Make sure the selection is a number and is between (0, max].
  if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
    return false;
  }

  char* p;
  strtol(s.c_str(), &p, 10);

  return (*p == 0) && (std::stoi(s) <= max) && (std::stoi(s) > 0);
}

bool run() {
  Lister lister = Lister();
  Lister::WindowList windows = lister.getWindowList();

  // Select the window to move.
  std::vector<std::string> windowNames;
  int i = 0;
  for(auto& window : windows) {
    windowNames.push_back(window.first);
    std::cout << i + 1 << ": " << window.first << std::endl;
    i++;
  }
  std::cout << "(Press Enter to reload list, exit by typing \"q\", \"quit\", or \"exit\")" << std::endl;

  std::cout << "Select a window to move: ";
  std::string selectedWindow;
  std::getline(std::cin, selectedWindow);
  if(!validSelection(selectedWindow, i)) {
    return false;
  }

  int windowNum = std::stoi(selectedWindow);
  windowNum--;

  // Select the Layout.
  Mover mover = Mover(windowNames[windowNum]);

  for(i = 0; i < (int)Mover::Layout::__LAST; i++) {
    std::cout << i + 1 << ": " << mover.getLayoutString((Mover::Layout)i) << std::endl;
  }

  std::cout << "Select a layout: ";
  std::string positionSelection;
  std::getline(std::cin, positionSelection);
  if(!validSelection(positionSelection, i)) {
    return false;
  }

  int windowPosition = std::stoi(positionSelection);
  windowPosition--;

  mover.move((Mover::Layout)windowPosition, windows[mover.getWindowName()]);

  return true;
}

int main() {
  while(1) {
    if(!run()) {
      // Clear the console if the move was successful.
      system("cls");
    }
  }

  return 0;
}

