#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[]) {
  using MapData = std::map<std::string, std::string>;
  MapData map_data;
  std::cout << map_data["test"] << std::endl;
  return 0;
}
