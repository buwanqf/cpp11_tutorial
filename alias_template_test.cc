#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename Container, typename T>
void test_move(Container container, T t) {
  uint32_t n = 10;
  do {
    cout << t << endl;
    container.insert(container.end(), t);
  } while (n--);
}

// template <typename T, template <class> class Container>

int main(int argc, char *argv[]) {
  test_move(vector<int>(), 1);
  test_move(vector<string>(), "1");
  test_move(set<int>(), 1);
  test_move(set<string>(), "1");
  return 0;
}
