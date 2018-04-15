#pragma once

class EnumTest {
public:
  enum Level : char {
    One, Two, Three
  };
  enum Food : char {
    Apples, Potatoes, Carrots
  };
public:
  EnumTest();
  ~EnumTest();
  Level getLevel();
  void setLevel(Level l);
  void setLevel();
  Food getFood();
  void setFood(Food f);
  void setFood();
private:
  Level mLevel;
  Food mFood;
};
