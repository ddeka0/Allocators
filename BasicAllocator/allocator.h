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
    free(p);
    LOG(INFO) << "deallocation done. p = " << p << ", size = " << n;
  }

  DataType* allocate(std::size_t n) {
    DataType* p = (DataType*)malloc(n * sizeof(DataType));
    LOG(INFO) << "allocation done. p = " << p << ", size = " << n;
    return p;
  }
};

}  // namespace BasicAllocator

#endif  // ALLOCATOR_H_
