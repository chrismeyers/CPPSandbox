#pragma once
class EnumTest {
public:
  enum Level : char {
    One, Two, Three
  };
public:
  EnumTest();
  ~EnumTest();
  Level getLevel();
  void setLevel(Level l);
  void setLevel();
private:
  Level mLevel;
};
