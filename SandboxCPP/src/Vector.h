#pragma once

#include <string>
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
  Vector(std::initializer_list<T> nums) : mSize(nums.size()), mVals(new T[mSize]) {
    std::copy(nums.begin(), nums.end(), mVals);
  }
  Vector(int len) : mSize(len), mVals(new T[len]) {
    for(int i = 0; i < mSize; i++) {
      mVals[i] = 0;
    }
  }
  Vector(const Vector& a) : mSize(a.mSize), mVals(new T[a.mSize]) {
    for(int i = 0; i < mSize; i++) {
      mVals[i] = a.mVals[i];
    }
  }
  ~Vector() {
    delete mVals;
  }
  int size() {
    return mSize;
  }
  std::string toString() {
    std::string str = "";
    for(int i = 0; i < mSize; i++) {
      str += std::to_string(mVals[i]);
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
      sum += mVals[i] * other.mVals[i];
    }
    return sum;
  }
  Vector<T> operator+(const Vector<T>& other) const {
    if(mSize != other.mSize) {
      throw VectorSizeMismatch();
    }

    Vector<T> tmp(mSize);
    for(int i = 0; i < mSize; i++) {
      tmp.mVals[i] = mVals[i] + other.mVals[i];
    }
    return tmp;
  }

private:
  int mSize;
  T* mVals;
};
