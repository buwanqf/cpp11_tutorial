#include <iostream>

class Test {
 public:
  Test(int data) : data_(data) {}
  virtual ~Test() {}

 private:
  int data_;
};

class Test1 {
 public:
  Test1() {}
  explicit Test1(int data1) : data1_(data1) {}
  Test1(const Test1& test1) : data1_(test1.data1_) {}
  Test1& operator=(const int data1) {
    data1_ = data1;
    return *this;
  }
  Test1& operator=(const Test1& test1) {
    data1_ = test1.data1_;
    return *this;
  }
  virtual ~Test1() {}

 private:
  int data1_;
};

int main(int argc, const char* argv[]) {
  Test test{1};
  Test test_1 = 1;
  Test1 test1{1};
  Test1 test1_1;
  test1_1 = 1;
  return 0;
}
