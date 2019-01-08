#pragma once

#include <memory>

class MemoryA {
public:
  MemoryA();
  ~MemoryA();
};

class MemoryB {
public:
  MemoryB();
  ~MemoryB();
private:
  std::unique_ptr<MemoryA> a;
};