#pragma once

#include <string>
#include <list>
#include <exception>

class VectorSizeMismatch : public std::exception {
public:
  virtual const char* what() const throw() {
    return "Vector sizes do not match.";
  }
};

template <typename T>
class Vector {
public:
  Vector(std::initializer_list<T> nums) : mSize(nums.size()), mVector(new T[mSize]) {
    std::copy(nums.begin(), nums.end(), mVector);
  }
  Vector(std::list<T> nums) : mSize(nums.size()), mVector(new T[mSize]) {
    std::copy(nums.begin(), nums.end(), mVector);
  }
  Vector(int len) : mSize(len), mVector(new T[len]) {}
  ~Vector() {
    delete mVector;
  }
  int size() {
    return mSize;
  }
  std::string toString() {
    std::string str = "";
    for(int i = 0; i < mSize; i++) {
      str += std::to_string(mVector[i]);
      if(i < mSize - 1) {
        str += ", ";
      }
    }
    return str;
  }
  T operator*(const Vector<T>& other) const {
    if(mSize != other.mSize) {
      throw VectorSizeMismatch();
    }

    T sum = 0;
    for(int i = 0; i < mSize; i++) {
      sum += mVector[i] * other.mVector[i];
    }
    return sum;
  }
  Vector<T> operator+(const Vector<T>& other) const {
    if(mSize != other.mSize) {
      throw VectorSizeMismatch();
    }

    std::list<T> nums;
    for(int i = 0; i < mSize; i++) {
      nums.push_back(mVector[i] + other.mVector[i]);
    }
    return Vector<T>(nums);
  }

private:
  int mSize;
  T* mVector;
};
