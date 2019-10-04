#include <iostream>

int main(int argc, char *argv[]) {
  int i = 0;
  std::cout << i << std::endl;
  int j(0);
  std::cout << j << std::endl;
  if (__cplusplus >= 201103) {
    std::cout << __cplusplus << std::endl;
    int k{};
    std::cout << k << std::endl;
    int l{1};
    std::cout << l << std::endl;
    // int m{1.1};
    // std::cout << m << std::endl;
  }
  return 0;
}
