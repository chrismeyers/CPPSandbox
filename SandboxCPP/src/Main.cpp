#include <string>
#include <iostream>

#include "PassBy.h"
#include "EnumTest.h"
#include "Vector.h"

int main() {
  std::string name = "Chris";
  std::cout << "Memory address of name: " << &name << std::endl;
  std::cout << name << std::endl;

  PassBy passBy;
  passBy.ref(name);
  std::cout << name << std::endl;
  passBy.val(name);
  std::cout << name << std::endl;
  passBy.ptr(&name);
  std::cout << name << std::endl;

  std::cout << std::endl << "======================================" << std::endl << std::endl;

  EnumTest enumTest;
  std::cout << "Initial mLevel          " << (int)enumTest.getLevel() << std::endl;
  std::cout << "Inital mFood            " << (int)enumTest.getFood() << std::endl << std::endl;

  std::cout << "EnumTest::Level::One    " << (int)EnumTest::Level::One << std::endl;
  enumTest.setLevel(EnumTest::Level::Two);
  std::cout << "EnumTest::Level::Two    " << (int)enumTest.getLevel() << std::endl;
  enumTest.setLevel();
  std::cout << "EnumTest::Level::Three  " << (int)enumTest.getLevel() << std::endl << std::endl;

  std::cout << "Food::Level::Apples     " << (int)EnumTest::Food::Apples << std::endl;
  enumTest.setFood(EnumTest::Food::Potatoes);
  std::cout << "Food::Level::Potatoes   " << (int)enumTest.getFood() << std::endl;
  enumTest.setFood();
  std::cout << "Food::Level::Carrots    " << (int)enumTest.getFood() << std::endl;

  std::cout << "Same enum               " << (bool)(EnumTest::Level::One == EnumTest::Level::One) << std::endl;
  std::cout << "Same int                " << (bool)((int)EnumTest::Level::One == (int)EnumTest::Food::Apples) << std::endl;

  std::cout << std::endl << "======================================" << std::endl << std::endl;

  Vector<double> v1 { 1.2, 3.4, 5.6 };
  Vector<double> v2 { 7.8, 9.0 };
  Vector<double> v3 { 11.12, 13.14, 15.16 };
  std::cout << v1.toString() << std::endl;
  std::cout << v2.toString() << std::endl;
  std::cout << v3.toString() << std::endl;
  
  try {
    std::cout << "v1 * v2 = " << (v1 * v2) << std::endl;
  }
  catch(VectorSizeMismatch& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "v1 * v3 = " << (v1 * v3) << std::endl;
  }
  catch(VectorSizeMismatch& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Vector<double> v4 = v1 + v2;
    std::cout << "v1 + v2 = " << (v4).toString() << std::endl;
  }
  catch(VectorSizeMismatch& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Vector<double> v5 = v1 + v3;
    std::cout << "v1 + v3 = " << (v5).toString() << std::endl;
  }
  catch(VectorSizeMismatch& e) {
    std::cout << e.what() << std::endl;
  }

  std::cin.get();
  return 0;
}
