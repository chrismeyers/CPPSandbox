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
  mLevel = EnumTest::Three;
}
