#include <iostream>

template <typename T, typename... Types>
void printf(const T& firstArg, const Types&... args) {
  std::cout << firstArg << std::endl;
  printf(args...);
}

int main(int argc, char* argv[]) {
  // printf("helloword", 11, std::bitset<16>(377));
  printf("hello", "world", "test");
  return 0;
}
