#pragma once

class EnumTest {
public:
  enum class Level {
    One, Two, Three
  };
  enum class Food {
    Apples, Potatoes, Carrots
  };
public:
  EnumTest();
  ~EnumTest();
  EnumTest::Level getLevel();
  void setLevel(EnumTest::Level l);
  void setLevel();
  EnumTest::Food getFood();
  void setFood(EnumTest::Food f);
  void setFood();
private:
  EnumTest::Level mLevel;
  EnumTest::Food mFood;
};
