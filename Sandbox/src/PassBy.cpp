#include <iostream>

#include "PassBy.h"

PassBy::PassBy() {
}

PassBy::~PassBy() {
}

void PassBy::ref(std::string &str) {
  std::cout << "Memory address of str (ref): " << &str << std::endl;
  str = "apples";
}

void PassBy::val(std::string str) {
  std::cout << "Memory address of str (val): " << &str << std::endl;
  str = "potatoes";
}

void PassBy::ptr(std::string *str) {
  std::cout << "Memory address of str (pointer): " << str << std::endl;
  *str = "carrots";
}
