#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <glog/logging.h>
#include <iostream>

namespace BasicAllocator {

template <typename DataType>
class Allocator {
 public:
  using value_type = DataType;
  void deallocate(DataType* p, std::size_t n) {
    LOG(INFO) << "deallocation done. p = " << p << ", size = " << n;
  }
};

}  // namespace BasicAllocator

#endif  // ALLOCATOR_H_
