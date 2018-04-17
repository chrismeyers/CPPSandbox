#pragma once

#include <string>

template <typename T>
class Vector {
public:
  Vector(std::initializer_list<T> nums) : mSize(nums.size()), mVector(new T[mSize]) {
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
      return -1;
    }

    T sum = 0;
    for(int i = 0; i < mSize; i++) {
      sum += mVector[i] * other.mVector[i];
    }
    return sum;
  }
  Vector<T>* operator+(const Vector<T>& other) const {
    if(mSize != other.mSize) {
      return new Vector<T>(0);
    }

    Vector<T>* tmp = new Vector<T>(mSize);
    for(int i = 0; i < mSize; i++) {
      tmp->mVector[i] = mVector[i] + other.mVector[i];
    }
    return tmp;
  }

private:
  int mSize;
  T* mVector;
};