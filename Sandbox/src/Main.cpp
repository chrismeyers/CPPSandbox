#include <string>
#include <iostream>

#include "PassBy.h"
#include "EnumTest.h"

int main() {
  std::string name = "Chris";
  std::cout << "Memory address of name: " << &name << std::endl;
  std::cout << name << std::endl;

  PassBy passBy;
  passBy.ref(name);
  std::cout << name << std::endl;
  passBy.val(name);
  std::cout << name << std::endl;
  passBy.ptr(&name);
  std::cout << name << std::endl;

  std::cout << std::endl << "======================================" << std::endl << std::endl;

  EnumTest enumTest;
  std::cout << "Level One:   " << EnumTest::One << std::endl;
  enumTest.setLevel(EnumTest::Two);
  std::cout << "Level Two:   " << enumTest.getLevel() << std::endl;
  enumTest.setLevel();
  std::cout << "Level Three: " << enumTest.getLevel() << std::endl;

  std::cout << "Food Apples:   " << EnumTest::Apples << std::endl;
  enumTest.setFood(EnumTest::Potatoes);
  std::cout << "Food Potatoes: " << enumTest.getFood() << std::endl;
  enumTest.setFood();
  std::cout << "Food Carrots:  " << enumTest.getFood() << std::endl;

  std::cin.get();
  return 0;
}
