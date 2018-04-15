#pragma once

#include <string>

class PassBy {
private:
public:
  PassBy();
  ~PassBy();
  void ref(std::string &str);
  void val(std::string str);
  void ptr(std::string *str);
};
