#include <atomic>
#include <cassert>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

template <class T>
class AtomicSharedPtr {
 public:
  // typedef std::shared_ptr<T> DataPtr;
  typedef std::shared_ptr<T> DataPtr;

  // for reader thread, store before store
  DataPtr Load() const { return std::atomic_load(&m_data); }

  // for writer thread
  void Store(T&& t) { Store(std::make_shared<T>(std::move(t))); }

  void Store(const T& t) { Store(std::make_shared<T>(t)); }

  void Store(DataPtr t) { std::atomic_store(&m_data, t); }

 private:
  DataPtr m_data;
};

using Map = std::map<std::string, std::string>;
static AtomicSharedPtr<Map> g_ptr;

void write() {
  while (true) {
    //实际上是shared_ptr<A>
    AtomicSharedPtr<Map>::DataPtr new_data(
        new std::map<std::string, std::string>());
    new_data->insert(std::make_pair(std::to_string(std::rand()), "a"));
    new_data->insert(std::make_pair(std::to_string(std::rand()), "b"));
    new_data->insert(std::make_pair(std::to_string(std::rand()), "c"));
    //这里可以做一些加载数据的操作
    g_ptr.Store(new_data);
  }
}

void read() {
  while (true) {
    AtomicSharedPtr<Map>::DataPtr read_ptr = g_ptr.Load();
    for (Map::iterator it = read_ptr->begin(); it != read_ptr->end(); it++)
      printf("read:map[%s]=%s\n", it->first.c_str(), it->second.c_str());
  }
}

int main(int argc, char* argv[]) {
  AtomicSharedPtr<Map>::DataPtr new_data(
      new std::map<std::string, std::string>());
  new_data->insert(std::make_pair(std::to_string(std::rand()), "a"));
  new_data->insert(std::make_pair(std::to_string(std::rand()), "b"));
  new_data->insert(std::make_pair(std::to_string(std::rand()), "c"));
  //这里可以做一些加载数据的操作
  g_ptr.Store(new_data);

  int n = 10;
  std::vector<std::thread> thread_vec;
  while (n--) {
    thread_vec.insert(thread_vec.end(), std::thread(write));
  }
  n = 20;
  while (n--) {
    thread_vec.insert(thread_vec.end(), std::thread(read));
  }

  for (size_t i = 0; i < thread_vec.size(); ++i) {
    thread_vec[i].join();
  }

  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}
