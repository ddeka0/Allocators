#include <glog/logging.h>
#include <vector>
#include "allocator.h"

int main(int argc, char* argv[]) {
  FLAGS_logtostdout = 1;
  // FLAGS_minloglevel = 2;
  google::InitGoogleLogging(argv[0]);

  std::vector<int, BasicAllocator::Allocator<int>> v;

  LOG(INFO) << "main end";
}