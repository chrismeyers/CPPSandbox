#include "Lister.h"
#include "Mover.h"
#include <iostream>

int main() {
  Lister lister = Lister();
  Lister::WindowList windows = lister.getWindowList();

  Mover mover = Mover("League of Legends");
  mover.move(Mover::Layout::RIGHT_CENTER, windows[mover.getWindowName()]);

  std::cin.get();
  return 0;
}
