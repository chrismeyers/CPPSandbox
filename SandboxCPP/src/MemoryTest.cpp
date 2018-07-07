#include "MemoryTest.h"
#include <iostream>

MemoryA::MemoryA() {
  std::cout << "MemoryA ctor" << std::endl;
}

MemoryA::~MemoryA() {
  std::cout << "MemoryA dtor" << std::endl;
}

MemoryB::MemoryB() :
  a(new MemoryA)
{ 
  std::cout << "MemoryB ctor" << std::endl;
}

MemoryB::~MemoryB() {
  std::cout << "MemoryB dtor" << std::endl;
}
