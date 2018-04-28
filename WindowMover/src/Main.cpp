#include "Processes.h"
#include "Mover.h"
#include <iostream>

int main() {
  Mover mover = Mover("League of Legends");
  mover.move(Mover::Layout::LEFT_CENTER);

  std::cin.get();
  return 0;
}
