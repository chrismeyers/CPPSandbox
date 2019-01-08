#pragma once

#include <windows.h>
#include <map>
#include <string>

class Lister {
public:
  typedef std::map<std::string, HWND> WindowList; // vector<sting name, HWND handle>
public:
  Lister();
  ~Lister();
  void list();
  bool EnumWindowsProc(const HWND& hwnd);
  void printWindowList();
  inline WindowList getWindowList() { return mWindowList; }
private:
  WindowList mWindowList;
};

