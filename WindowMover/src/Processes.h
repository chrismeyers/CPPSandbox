#pragma once

#include <utility>
#include <vector>
#include <string>

class Processes {
  typedef std::vector<std::pair<std::string, std::string>> ProcessMap;
public:
  Processes();
  ~Processes();
  void buildProcessMap();
  void printProcessMap();
  ProcessMap getProcessMap() const { return mProcessMap; }
private:
  ProcessMap mProcessMap;
};