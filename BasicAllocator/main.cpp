#include <glog/logging.h>
#include <map>
#include <vector>
#include "allocator.h"

int main(int argc, char* argv[]) {
  FLAGS_logtostdout = 1;
  // FLAGS_minloglevel = 2;
  google::InitGoogleLogging(argv[0]);

  /************************************************/
  std::vector<int, BasicAllocator::Allocator<int>> v;

  v.push_back(10);
  v.push_back(11);
  v.push_back(12);
  v.push_back(13);

  v.pop_back();
  std::vector<int> v4;
  auto v2 = v;
  auto v3 = move(v);
  if (v2 == v3) {
    LOG(INFO) << "v2 and v3 are equal vectors";
  }
  // v4 = v2;
  /************************************************/
  LOG(INFO) << "Map>";
  std::map<int, int, std::less<int>,
           BasicAllocator::Allocator<std::pair<const int, int>>>
      M;
  M[1] = 1;

  LOG(INFO) << "main end";
}