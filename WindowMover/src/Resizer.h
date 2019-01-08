#pragma once

#include "Utils.h"
#include <string>

class Resizer {
public:
  Resizer(const std::string& programName);
  ~Resizer();

  bool parseSize(const std::string& size);
  void resize(const HWND& hwnd);
  inline std::string getWindowName() { return mWindowName; }
private:
  std::string mWindowName;
  WindowMoverUtils::WindowSize mWindowSize;
};

