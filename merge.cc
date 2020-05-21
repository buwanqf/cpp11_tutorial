#include <iostream>
#include <string>
#include <vector>

std::vector<int> unionTow(const std::vector<int>& vec_1,
                          const std::vector<int>& vec_2) {
  std::vector<int> result_vec;
  int i = 0;
  int j = 0;
  while (i < vec_1.size() && j < vec_2.size()) {
    if (vec_1[i] < vec_2[j]) {
      if (result_vec.size() == 0 || vec_1[i] != result_vec.back()) {
        result_vec.push_back(vec_1[i++]);
      } else {
        i++;
      }
    } else {
      if (result_vec.size() == 0 || vec_2[j] != result_vec.back()) {
        result_vec.push_back(vec_2[j++]);
      } else {
        j++;
      }
    }
  }

  while (i < vec_1.size()) {
    if (result_vec.size() == 0 || vec_1[i] != result_vec.back()) {
      result_vec.push_back(vec_1[i++]);
    } else {
      i++;
    }
  }

  while (j < vec_2.size()) {
    if (result_vec.size() == 0 || vec_2[j] != result_vec.back()) {
      result_vec.push_back(vec_2[j++]);
    } else {
      j++;
    }
  }

  return result_vec;
}

std::vector<int> intersectionTow(const std::vector<int>& vec_1,
                                 const std::vector<int>& vec_2) {
  std::vector<int> result_vec;
  int i = 0;
  int j = 0;
  while (i < vec_1.size() && j < vec_2.size()) {
    if (vec_1[i] == vec_2[j]) {
      result_vec.push_back(vec_1[i]);
      i++;
      j++;
    } else if (vec_1[i] < vec_2[j]) {
      i++;
    } else {
      j++;
    }
  }
  return result_vec;
}

std::vector<int> merge(std::vector<std::vector<int>>& vec_vec) {
  std::vector<int> result_vec;
  if (vec_vec.size() == 0) {
    return result_vec;
  }
  result_vec = vec_vec[0];
  for (int i = 1; i < vec_vec.size(); i++) {
    result_vec = unionTow(result_vec, vec_vec[i]);
  }
  return result_vec;
}

int main(int argc, char const* argv[]) {
  std::vector<std::vector<int>> vec_vec = {
      {1, 2, 3, 5, 7, 8, 11, 22, 33, 44, 66},
      {2, 4, 5, 6, 7, 8, 10, 22, 23, 25},
      {7, 8, 10, 22, 23, 30, 33, 50},
      {10, 11, 17, 22, 23, 30, 33, 50},
      {22, 23, 24, 25, 26, 30, 33, 50},

  };
  std::vector<int> result_vec = merge(vec_vec);

  for (auto value : result_vec) {
    std::cout << value << " ";
  }

  std::cout << std::endl;

  return 0;
}
