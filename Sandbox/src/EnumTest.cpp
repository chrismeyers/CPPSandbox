#include "EnumTest.h"

EnumTest::EnumTest() {
}

EnumTest::~EnumTest() {
}

EnumTest::Level EnumTest::getLevel() {
  return mLevel;
}

void EnumTest::setLevel(EnumTest::Level l) {
  mLevel = l;
}

void EnumTest::setLevel() {
  mLevel = EnumTest::Level::Three;
}

EnumTest::Food EnumTest::getFood() {
  return mFood;
}

void EnumTest::setFood(EnumTest::Food f) {
  mFood = f;
}

void EnumTest::setFood() {
  mFood = EnumTest::Food::Carrots;
}
