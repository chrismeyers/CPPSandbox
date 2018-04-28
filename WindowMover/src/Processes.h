#pragma once

#include <windows.h>
#include <utility>
#include <vector>
#include <string>

class Processes {
  typedef std::vector<std::pair<std::string, DWORD>> ProcessMap; // vector<sting name, DWORD pid>
public:
  Processes();
  ~Processes();
  void buildProcessMap();
  DWORD getPidFromName(std::string name);
  std::string getNameFromPid(DWORD pid);
  void printProcessMap();
  ProcessMap getProcessMap() const { return mProcessMap; }
private:
  ProcessMap mProcessMap;
};
